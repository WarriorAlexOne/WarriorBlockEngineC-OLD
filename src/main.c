#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

#include "tools/strtools.h"
#include "controls.h"
#include "player.h"

char versionNumber[35] = "WarriorBlockEngine 0.2.1";  //Extra Memory Allocated for extra letters.
SDL_Window* window;
SDL_Renderer* renderer;
int lastFrameTime = 0;
int frameTarget = 60;  //Default is 60.
float gameTime = 1.0;  //Smaller number means slower game. Default is 1.

//Forward Declarations
void fpsLoop ();
void render(Player player1);
int startSDL();


int main (int argc, char **argv) {
    //Variables
    float deltaTime = gameTime/frameTarget;
    int quit = 0;
    int* pquit = &quit;

    startSDL();


    //Main Loop
    while (!quit) {
        fpsLoop();
        input(pplayer,pquit);
        render(player);
        playerLoop(pplayer,deltaTime);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void fpsLoop () {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTime + (1000/frameTarget)));  //Limits game to frames/second
    lastFrameTime = SDL_GetTicks();
}

void render (Player player1) {  //Renderer & Shape Drawer
    SDL_SetRenderDrawColor(renderer, 2, 32, 100, 255);
    SDL_RenderClear(renderer);

    SDL_Rect playerDraw = {player1.x, player1.y, player1.sizeX, player1.sizeY};  //Create Player

    SDL_SetRenderDrawColor(renderer, 217, 177, 107, 255);
    SDL_RenderFillRect(renderer, &playerDraw);

    SDL_RenderPresent(renderer);
}

int startSDL () {  //Start Window Creation & Renderer Creation
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL Initialization Failed: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow(
        versionNumber,  //Title
        SDL_WINDOWPOS_CENTERED,  //X Position
        SDL_WINDOWPOS_CENTERED,  //Y Position
        800,  //X Size
        600,  //Y Size
        SDL_WINDOW_SHOWN |  //Flags (Properties Of Window)*/
        SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        printf("Window Creation Failed: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        printf("Renderer Creation Failed: %s\n", SDL_GetError());
        return 0;
    }

    return printf("Initialization Complete\n");
}

