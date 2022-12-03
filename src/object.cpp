
#include "object.hpp"

object::object(Vector2D posArg, SDL_Texture* textArg)
    :pos(posArg), text(textArg)
{
    curFrame.x = 0;
    curFrame.y = 0;

    curFrame.w = 32;
    curFrame.h = 32;
}

Vector2D& object::getPos()
{
    return pos;
}

void object::changePos(Vector2D posArg)
{
    pos = posArg;
}

SDL_Texture* object::getTexture()
{
    return text;
}

SDL_Rect object::getCurrentFrame()
{
    return curFrame;
}

Vector2D object::randomCords()
{
    return Vector2D((rand() % 980), (rand () % 980));
}
