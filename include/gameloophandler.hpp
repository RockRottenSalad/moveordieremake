#pragma once

#include<SDL2/SDL.h>
#include<cmath>

#include "controls.hpp"
#include "object.hpp"

void movePlr(controls& plrControls, object& plr, Vector2D temp);
bool checkCollision(object& plr, object& food);

