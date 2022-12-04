#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include "object.hpp"
#include "textrender.hpp"

class windowCreator
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        windowCreator(const char* winTitle, int w, int h); // render window, w = width, h = height
        SDL_Texture* loadTexture(const char* filePath); // load texture
        void cleanExit(); // kill window
        void clear(); // clear previously rendered stuff
        void render(object& objectArg); // render something
        void renderText(textRender& textArg);
        void display(); // display rendered texture
};

