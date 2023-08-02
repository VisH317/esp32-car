#ifndef __SERVER__
#define __SERVER__

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "SPIFFS.h"
#include "config.hpp"
#include "car.hpp"

enum Command {
    FORWARD,
    RIGHT,
    LEFT,
    BACKWARD,
    STOP,
};

static const std::unordered_map<std::string, Command> codes = {
    { "forward", Command::FORWARD },
    { "right", Command::RIGHT },
    { "left", Command::LEFT },
    { "backward", Command::BACKWARD },
    { "stop": Command::STOP },
};

class CarServer {
    private:
        AsyncWebServer server;
        AsyncWebSocket socket;
        Car car;

        void loadAssets();
        void processCommand(Command command);

    public:
        CarServer(Car& car) : car(car), server(SERVER_PORT), socket(SERVER_PATH) {};;
        void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
        void notFound(AsyncWebServerRequest *request);
        void setup();
        void start();


}

#endif