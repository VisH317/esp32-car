#include "car.hpp"

void Car::setup() {
    left.setup();
    right.setup();
}

void Car::moveForward()