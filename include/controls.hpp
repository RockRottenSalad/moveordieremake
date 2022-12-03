#pragma once

#include "vector2d.hpp"

class controls
{
    private:
        int direction;
        int speed;
    public:
        controls(int directionArg, int speedArg);
        void changeDirection(int directionArg);
        int getDirection();
        void changeSpeed(int speedArg);
        int getSpeed();
};

