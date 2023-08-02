#include "server.hpp"

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
            
    }
}
