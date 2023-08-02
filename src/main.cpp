#include <Arduino.h>
#include "utils.hpp"
#include "car.hpp"
#include "ports.hpp"
#include "config.hpp"
#include "server.hpp"

CarBot car({ MOTOR_LEFT }, { MOTOR_RIGHT });
CarServer server(car);

void setup() {
    setupSerial();
    setupWifi();
    server.setup();
    server.start();
}

void loop() {
    
}