
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<ctime>
#include<stdio.h>

#include "window.hpp"
#include "controls.hpp"
#include "gameloophandler.hpp"
#include "textrender.hpp"


int main(int argc, char ** argv)
{
    windowCreator window("Move or DIE", 980, 980);

    SDL_Texture* playerTexture = window.loadTexture("res/gfx/plr.png");
    SDL_Texture* foodTexture = window.loadTexture("res/gfx/food.png");

    TTF_Font* iosevka = TTF_OpenFont("res/iosevka-regular.ttf", 24);
    SDL_Color white = {255, 255, 255, 0};
    SDL_Rect scoreRect;
    scoreRect.x = scoreRect.y = 10;
    scoreRect.w = 30;
    scoreRect.h = 50;

    std::srand(std::time(nullptr));
    object plr = object(Vector2D(458,458), playerTexture);
    object food = object(Vector2D(food.randomCords()), foodTexture);
    textRender score = textRender(iosevka, white, "0", scoreRect, window.getRenderer());

    controls plrControls = controls(0, 5);
    Vector2D temp;

    bool quitGame = false, eaten = true;
    SDL_Event event;

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
            plrControls.incScore();
            char *tempstr;
            sprintf(tempstr, "%d", plrControls.getScore());
            score.updateSurface(tempstr, window.getRenderer());
           // free(tempstr);
        }

        window.clear();
        window.render(food);
        window.render(plr);
        window.renderText(score);
        window.display();
    }

    window.cleanExit();
    SDL_Quit();
    return 0;
}

