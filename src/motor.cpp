#include "motor.hpp"

void Motor::setupMotor() {
    pinMode(port, OUTPUT);
}

void Motor::moveMotor(int power) {
    analogWrite(port, power);
}