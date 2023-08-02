#ifndef __CAR__
#define __CAR__

#include <initializer_list>
#include "config.hpp"
#include "motorGroup.hpp"
class Car {
    private:
        MotorGroup left;
        MotorGroup right;

    public:
        Car(std::initializer_list<int> left, std::initializer_list<int> right) : left(left), right(right) {};
        void setup();

        // setup movement functions here
        void moveForward();
        void turnLeft();
        void turnRight();
        void stop();
};

#endif