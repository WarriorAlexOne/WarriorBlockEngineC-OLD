#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

#include "tools/strtools.h"
#include "tools/detection.h"
#include "controls.h"
#include "player.h"
#include "walls.h"

//Window Variables
char versionNumber[35] = "WarriorBlockEngine 0.2.2.1";  //Extra Memory Allocated for extra letters.
SDL_Window* window;
SDL_Renderer* renderer;
int windowDefaultSizeX = 1760;
int windowDefaultSizeY = 960;
int quit = 0;
int* pquit = &quit;
//Frame Variables
double lastFrameTime = 0;
short frameTarget = 60;  //Default is 60.
double gameTime = 1.0;  //Smaller number means slower game. Default is 1.

//Forward Declarations
void fpsLoop ();
void render (Player player1);
int startSDL();
void mouseInput (Player* player);


int main (int argc, char **argv) {
    //Variables
    double deltaTime = gameTime/frameTarget;

    startSDL();
    initControls();
    //Main Loop
    while (!quit) {
        fpsLoop();
        render(player);
        updateControls();
        mouseInput(pplayer);
        playerLoop(pplayer,deltaTime);
        detectionLoop(window);
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

    SDL_Rect testRect = {500,500,50,50};
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &testRect);

    SDL_Rect playerDraw = {player1.transform.position.x, player1.transform.position.y, player1.transform.size.x, player1.transform.size.y};  //Define Player
    SDL_SetRenderDrawColor(renderer, 217, 177, 107, 255);  //Player Color
    SDL_RenderFillRect(renderer, &playerDraw);  //Draw Player

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
        windowDefaultSizeX,  //X Size
        windowDefaultSizeY,  //Y Size
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

void mouseInput (Player* player) {  //Mouse Inputs (Very temporary. Will be changed soon)
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) *pquit = 1;  //X Button. Could be fun to play with.

    switch (event.type) {
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

