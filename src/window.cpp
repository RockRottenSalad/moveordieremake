
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

#include "window.hpp"
#include "object.hpp"
#include "textrender.hpp"

windowCreator::windowCreator(const char* winTitle, int w, int h)
    :window(NULL), renderer(NULL)
{
   window = SDL_CreateWindow(winTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

   if(window == NULL)
       std::cout << "well, shit: " << SDL_GetError() << std::endl;

   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   TTF_Init();
}

SDL_Texture* windowCreator::loadTexture(const char* filePath)
{
    SDL_Texture* text = NULL;
    text = IMG_LoadTexture(renderer, filePath);

    if(text == NULL)
       std::cout << "well, shit: " << SDL_GetError() << std::endl;

    return text;
}

void windowCreator::cleanExit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void windowCreator::clear()
{
    SDL_RenderClear(renderer);
}

void windowCreator::render(object& objectArg)
{
    SDL_Rect source;
    source.x = objectArg.getCurrentFrame().x;
    source.y = objectArg.getCurrentFrame().y;
    source.w = objectArg.getCurrentFrame().w;
    source.h = objectArg.getCurrentFrame().h;

    SDL_Rect dest;
    dest.x = objectArg.getPos().x;
    dest.y = objectArg.getPos().y;
    dest.w = objectArg.getCurrentFrame().w * 2;
    dest.h = objectArg.getCurrentFrame().h * 2;

    // ADD ENTITY
    SDL_RenderCopy(renderer, objectArg.getTexture(), &source, &dest);
}


void windowCreator::renderText(textRender& textArg)
{
    SDL_Rect dest = textArg.getMsgRect();

    // ADD ENTITY
    SDL_RenderCopy(renderer, textArg.getTexture(), NULL, &dest);
}


void windowCreator::display()
{
   SDL_RenderPresent(renderer); 
}

SDL_Renderer* windowCreator::getRenderer()
{
    return renderer;
}
