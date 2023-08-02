#include "motor.hpp"

void Motor::setupMotor() {
    pinMode(port, OUTPUT);
}

void Motor::moveMotor(int power) {
    analogWrite(port, power);
}

void Motor::stopMotor() {
    analogWrite(port, 0);
}

int Motor::getPort() {
    return port;
}