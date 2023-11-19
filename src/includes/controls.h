#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL2/SDL.h>
#include "player.h"

int keyW = 0;
int keyA = 0;
int keyS = 0;
int keyD = 0;


void input (Player* player);

void input (Player* player) {  //Various Inputs
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    player->y -= 5;
                    break;
                case SDLK_a:
                    player->x -= 5;
                    break;
                case SDLK_s:
                    player->y += 5;
                    break;
                case SDLK_d:
                    player->x += 5;
                    break;
            }
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {

            }
    }
}

#endif