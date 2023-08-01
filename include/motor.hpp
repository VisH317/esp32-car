#ifndef __MOTOR__
#define __MOTOR__

#include <Arduino.h>

class Motor {
    private:
        int port;

    public:
        Motor(int port) : port(port) {};
        void setupMotor();
        void moveMotor(int power);
};

#endif