#include "motorGroup.hpp"

MotorGroup::MotorGroup(std::initializer_list<int> motors) {
    this->motors.insert(this->motors.end(), motors.begin(), motors.end());
}

void MotorGroup::setup() {
    for(int i=0;i<this->motors.size();i++) {
        this->motors[i].setupMotor();
    }
}

void MotorGroup::move(int power) {
    for(int i=0;i<this->motors.size();i++) {
        this->motors[i].moveMotor(power);
    }
}

void MotorGroup::stop() {
    for(int i=0;i<this->motors.size();i++) {
        this->motors[i].stopMotor();
    }
}