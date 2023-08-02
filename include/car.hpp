#ifndef __CAR__
#define __CAR__

#include <initializer_list>
#include "config.hpp"
#include "motorGroup.hpp"
class CarBot {
    private:
        MotorGroup left;
        MotorGroup right;

    public:
        CarBot(std::initializer_list<int> left, std::initializer_list<int> right) : left(left), right(right) {};
        void setup();

        // setup movement functions here
        void moveForward();
        void moveBackward();
        void turnLeft();
        void turnRight();
        void stop();
};

#endif