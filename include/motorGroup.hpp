#ifndef __MOTOR_GROUP__
#define __MOTOR_GROUP__

#include <Arduino.h>
#include <vector>
#include <initializer_list>
#include "motor.hpp"

class MotorGroup {
    private:
        std::vector<Motor> motors;

    public:
        MotorGroup(std::initializer_list<int> motors);
        void setup();
        void move(int power);
        void stop();
};

#endif