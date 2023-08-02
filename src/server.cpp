#include "server.hpp"

void CarServer::setup() {
    if(!SPIFFS.begin(true)) {
        Serial.println("SPIFFS init error occurred");
        throw std::runtime_error("SPIFFS init error occurred");
    }

    socket.onEvent([this](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) { 
        return this->onEvent(server, client, type, arg, data, len);
    });
    server.addHandler(&socket);

    loadAssets();

    server.onNotFound([this](AsyncWebServerRequest *request) { this->notFound(request); });
}

void CarServer::start() {
    server.begin();
}

void CarServer::onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    switch(type) {
        case WS_EVT_CONNECT:
        {
            Serial.printf("ws[%s][%u] connect\n", server->url(), client->id());
            // client->printf("Hello Client %u :)", client->id());
            // client->ping();
        }

        case WS_EVT_DISCONNECT:
        {
            Serial.printf("ws[%s][%u] disconnect\n", server->url(), client->id());
        }

        case WS_EVT_PONG:
        {
            Serial.printf("ws[%s][%u] pong[%u]: %s\n", server->url(), client->id(), len, (len) ? (char *)data : "");
        }

        case WS_EVT_ERROR:
        {
            Serial.printf("ws[%s][%u] error(%u): %s\n", server->url(), client->id(), *((uint16_t *)arg), (char *)data);
        }

        case WS_EVT_DATA:
        {
            //data packet
            AwsFrameInfo *info = (AwsFrameInfo *)arg;

            if (info->final && info->index == 0 && info->len == len) {
                //the whole message is in a single frame and we got all of it's data
                if (info->opcode == WS_TEXT)
                {
                    data[len] = 0;
                    char *command = (char *)data;

                    auto it = codes.find(std::string(command));
                    if(it != codes.end()) {
                        processCommand(it->second);
                    } 
                }
            }
        }
    }
}

void CarServer::processCommand(Command command) {
    switch(command) {
        case FORWARD:
            car.moveForward();
            break;
        case BACKWARD:
            car.moveBackward();
            break;
        case RIGHT:
            car.turnRight();
            break;
        case LEFT:
            car.turnLeft();
            break;
        case STOP:
            car.stop();
            break;
    }
}

void CarServer::notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void CarServer::loadAssets() {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
        {
            Serial.println("Requesting index page...");
            request->send(SPIFFS, "../frontend/index.html", "text/html");
        });

    // Route to load custom.css file
    server.on("/css/custom.css", HTTP_GET, [](AsyncWebServerRequest *request)
        { request->send(SPIFFS, "../frontend/css/index.css", "text/css"); });

    // Route to load custom.js file
    server.on("/js/custom.js", HTTP_GET, [](AsyncWebServerRequest *request)
        { request->send(SPIFFS, "../frontend/js/index.js", "text/javascript"); });
}