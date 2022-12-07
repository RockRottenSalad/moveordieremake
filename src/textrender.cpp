
#include "textrender.hpp"

textRender::textRender(TTF_Font* fontArg, SDL_Color colorArg, const char* text, SDL_Rect msgRectArg, SDL_Renderer* renderer)
    :font(fontArg), color(colorArg), msgRect(msgRectArg)
{
    surface = TTF_RenderText_Solid(font, text, color);
    convertSurfaceToTexture(renderer);
}

SDL_Rect textRender::getMsgRect()
{
    return msgRect;
}

void textRender::convertSurfaceToTexture(SDL_Renderer* renderer)
{
    msg = SDL_CreateTextureFromSurface(renderer, surface);
}

SDL_Texture* textRender::getTexture()
{
    return msg;
}

void textRender::updateSurface(char* textArg, SDL_Renderer* renderer)
{
    surface = TTF_RenderText_Solid(font, textArg, color); 
    convertSurfaceToTexture(renderer);
}
