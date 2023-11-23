#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL2/SDL.h>
#include "player.h"

//Forward Declarations
void input (Player* player, int* quit);


void input (Player* player, int* quit) {  //Various Inputs
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:  //What The X Button Does (This Could Be Fun :) )
            *quit = 1;
            break;
        case SDL_KEYDOWN:  //Temporary Control System
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    player->up = 1;
                    break;
                case SDLK_a:
                    player->left = 1;
                    break;
                case SDLK_s:
                    player->down = 1;
                    break;
                case SDLK_d:
                    player->right = 1;
                    break;
            }
            break;
        case SDL_KEYUP:  //Temporary Control System
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    player->up = 0;
                    break;
                case SDLK_a:
                    player->left = 0;
                    break;
                case SDLK_s:
                    player->down = 0;
                    break;
                case SDLK_d:
                    player->right = 0;
                    break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:  //Temporary Control System
            switch (event.button.button) {
                case SDL_BUTTON_LEFT:
                player->leftClick = 1;
                break;
                case SDL_BUTTON_RIGHT:
                player->rightClick = 1;
                break;
                case SDL_BUTTON_MIDDLE:
                player->middleClick = 1;
                break;
            }
            break;
        case SDL_MOUSEBUTTONUP:  //Temporary Control System
            switch (event.button.button) {
                case SDL_BUTTON_LEFT:
                player->leftClick = 0;
                break;
                case SDL_BUTTON_RIGHT:
                player->rightClick = 0;
                break;
                case SDL_BUTTON_MIDDLE:
                player->middleClick = 0;
                break;
            }
            break;
    }
}

#endif