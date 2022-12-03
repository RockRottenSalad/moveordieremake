#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<random>
#include<iostream>

#include "vector2d.hpp"

class object
{
    private:
        Vector2D pos;
        SDL_Rect curFrame;
        SDL_Texture* text;
    public:
        object(Vector2D posArg, SDL_Texture* textArg);
        Vector2D& getPos();
        void changePos(Vector2D posArg);
        SDL_Texture* getTexture();
        SDL_Rect getCurrentFrame();

        Vector2D randomCords();
};

