
#include "gameloophandler.hpp"

void movePlr(controls& plrControls, object& plr, Vector2D temp)
{
        switch(plrControls.getDirection()){
            case 1:
                temp = plr.getPos();
                temp.x -= plrControls.getSpeed(); 
                plr.changePos(temp);
                break;
            case 2: 
                temp = plr.getPos();
                temp.x += plrControls.getSpeed(); 
                plr.changePos(temp);
                break;
            case 3:
                temp = plr.getPos();
                temp.y -= plrControls.getSpeed(); 
                plr.changePos(temp);
                break;
            case 4:
                temp = plr.getPos();
                temp.y += plrControls.getSpeed(); 
                plr.changePos(temp);
                break;
            default:
                break;
        }
}


bool checkCollision(object& plr, object& food)
{
    if(abs(plr.getPos().x - food.getPos().x) <= 55 && abs(plr.getPos().y - food.getPos().y) <= 55)
        return true;
    return false;
}

bool checkOutOfBounds(object& plr)
{
    if(plr.getPos().x > 980 || plr.getPos().x < -32 || plr.getPos().y > 980 || plr.getPos().y < -32)
        return true;
    return false;
}
