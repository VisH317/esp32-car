#ifndef __MOTOR__
#define __MOTOR__

class Motor {
    private:
        int port;

    public:
        Motor(int port) : port(port) {};
        void moveMotor(int power);
};

#endif