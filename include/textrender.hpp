#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>

class textRender
{
    private:
        TTF_Font* font;
        SDL_Color color;
        SDL_Surface* surface;
        SDL_Texture* msg;
        SDL_Rect msgRect;
    public:
        textRender(TTF_Font* fontArg, SDL_Color colorArg, const char* text, SDL_Rect msgRectArg, SDL_Renderer* renderer);
        void setTexture();
        SDL_Rect getMsgRect();
        void convertSurfaceToTexture(SDL_Renderer* renderer);
        SDL_Texture* getTexture();
        void updateSurface(char* textArg, SDL_Renderer* renderer);
};
