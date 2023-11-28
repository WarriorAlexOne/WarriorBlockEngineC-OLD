#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "variables.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "tools/strtools.h"
#include "tools/detection.h"
#include "controls.h"
#include "player.h"
#include "walls.h"

//Forward Declarations
void fpsLoop ();
void render (Player player1);
int startSDL();
void mouseInput (Player* player);


int main (int argc, char **argv) {
    startSDL();
    initControls();


    //Main Loop
    while (!quit) {
        fpsLoop();
        render(player);
        updateControls();
        mouseInput(pplayer);
        playerLoop(pplayer);
        detectionLoop(window);
        printf("CameraX: %lf\n",cameraX); //Debugging Print
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}


void fpsLoop () {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTime + (1000/frameTarget)));  //Limits game to frames/second
    lastFrameTime = SDL_GetTicks();
}

void render (Player player1) {  //Renderer & Shape Drawer
    SDL_SetRenderDrawColor(renderer, 2, 32, 100, 255);
    SDL_RenderClear(renderer);

    SDL_Rect testRect = {500-cameraX,500,50,50};
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &testRect);

    SDL_Rect playerDraw = {player1.transform.position.x, player1.transform.position.y, player1.transform.size.x, player1.transform.size.y};  //Define Player
    SDL_SetRenderDrawColor(renderer, 217, 177, 107, 255);  //Player Color
    SDL_RenderFillRect(renderer, &playerDraw);  //Draw Player

    SDL_RenderPresent(renderer);
}

int startSDL () {  //Initialize and create everything necessary.
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {  //Automatically initialized. If a fault is detected, the program ends.
        printf("SDL Initialization Failed: %s\n", SDL_GetError());
        return 0;
    }

    if (IMG_Init(IMG_INIT_PNG != IMG_INIT_PNG)) {  //Image Lib Initialized
        printf("Image Initialization Failed: %s\n", SDL_GetError());
        return 0;
    }

    if (TTF_Init() == -1) {  //Text Lib Initialized
        printf("TTF Initialization Failed: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow(  //Creating & Setting The Window Properties
        versionNumber,  //Title
        SDL_WINDOWPOS_CENTERED,  //X Position
        SDL_WINDOWPOS_CENTERED,  //Y Position
        windowDefaultSizeX,  //X Size
        windowDefaultSizeY,  //Y Size
        SDL_WINDOW_SHOWN |  //Flags (Properties Of Window)*/
        SDL_WINDOW_RESIZABLE
    );
    if (!window) {  //If Window Creation failed, end program.
        printf("Window Creation Failed: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);  //SDL Renderer Creation
    if (!renderer) {  //If Renderer fails, end program.
        printf("Renderer Creation Failed: %s\n", SDL_GetError());
        return 0;
    }

    return printf("Initialization Complete\n");  //If SDL loads without error, program starts.
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

