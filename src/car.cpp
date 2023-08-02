#include "car.hpp"

void Car::setup() {
    left.setup();
    right.setup();
}

void Car::moveForward() {
    left.move(FORWARD_POWER);
    right.move(FORWARD_POWER);
}

void Car::moveBackward() {
    left.move(-1 * FORWARD_POWER);
    right.move(-1 * FORWARD_POWER);
}

void Car::turnLeft() {
    left.move(TURN_POWER);
    right.move(-1 * TURN_POWER);
}

void Car::turnRight() {
    left.move(-1 * TURN_POWER);
    right.move(TURN_POWER);
}

