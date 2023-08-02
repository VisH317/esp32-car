#ifndef __MOTOR__
#define __MOTOR__

#include <Arduino.h>

class Motor {
    private:
        int port;

    public:
        Motor(int port) : port(port) {};
        void setupMotor();
        int getPort();
        void moveMotor(int power);
        void stopMotor();
};

#endif