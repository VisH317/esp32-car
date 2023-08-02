#ifndef __SERVER__
#define __SERVER__

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include "config.hpp"
#include "car.hpp"

class CarServer {
    private:
        AsyncWebServer server;
        AsyncWebSocket socket;
        Car car;

        void notFound();
        void loadAssets();
        void onEvent();

    public:
        Server(std::initializer_list<int> left, std::initializer_list<int> right);
        void setup();
        void start();


}

#endif