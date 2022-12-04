
#include "textrender.hpp"

textRender::textRender(TTF_Font* fontArg, SDL_Color colorArg, const char* text, SDL_Rect msgRectArg)
    :font(fontArg), color(colorArg), msgRect(msgRectArg)
{
    surface = (font, text, color);
}

SDL_Rect textRender::getMsgRect()
{
    return msgRect;
}
