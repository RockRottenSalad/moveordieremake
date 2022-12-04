
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<ctime>

#include "window.hpp"
#include "controls.hpp"
#include "gameloophandler.hpp"


int main(int argc, char ** argv)
{
    windowCreator window("Move or DIE", 980, 980);

    SDL_Texture* playerTexture = window.loadTexture("res/gfx/plr.png");
    SDL_Texture* foodTexture = window.loadTexture("res/gfx/food.png");
    object plr = object(Vector2D(458,458), playerTexture);
    object food = object(Vector2D(), foodTexture);
    controls plrControls = controls(0, 5);
    Vector2D temp;

    bool quitGame = false, eaten = true;
    SDL_Event event;

    std::srand(std::time(nullptr));

    while(!quitGame)
    {
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        plrControls.changeDirection(1);
                        break;
                    case SDLK_RIGHT:
                        plrControls.changeDirection(2);
                        break;
                    case SDLK_UP:
                        plrControls.changeDirection(3);
                        break;
                    case SDLK_DOWN:
                        plrControls.changeDirection(4);
                        break;
                }
                break;
            case SDL_QUIT:
                quitGame = true;
                break;
        }

        movePlr(plrControls, plr, temp);
        eaten = checkCollision(plr, food); 

        if(eaten == true) {
            eaten = false;
            food.changePos(food.randomCords());
            plrControls.changeSpeed(plrControls.getSpeed() + 1);
        }

        window.clear();
        window.render(food);
        window.render(plr);
        window.display();
    }

    window.cleanExit();
    SDL_Quit();
    return 0;
}

