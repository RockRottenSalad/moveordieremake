
#include "controls.hpp"

controls::controls(int directionArg, int speedArg)
    :direction(directionArg), speed(speedArg), score(0)
{}

void controls::changeDirection(int directionArg)
{
    direction = directionArg;
}

int controls::getDirection()
{
    return direction;
}

void controls::changeSpeed(int speedArg)
{
    speed = speedArg;
}

int controls::getSpeed()
{
    return speed;
}

