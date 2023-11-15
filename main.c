#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

#include "player.h"

SDL_Window* window;
SDL_Renderer* renderer;
int quit = 0;
int lastFrameTime = 0;
int frameRate = 60;

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Rect;

//Forward Declarations
void fpsLoop (Player* player1);
void input (Player* player1);
void render(Player player1);
Rect defineRect(int x, int y, int w, int h);
SDL_Rect drawRect(Rect rect);
int startSDL();


int main (int argc, char **argv) {
    Player player = {0,0,500,500};
    Player* pplayer = &player;
    startSDL();


    //Main Loop
    while (!quit) {
        fpsLoop(pplayer);
        input(pplayer);
        render(player);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void fpsLoop (Player* player1) {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTime + (1000/frameRate)));
    lastFrameTime = SDL_GetTicks();
    playerLoop();
}

void input (Player* player1) {  //Various Inputs
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            quit = 1;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    quit = 1;
                    break;
                case SDLK_w:
                    player1->y--;
                    break;
                case SDLK_a:
                    player1->x--;
                    break;
                case SDLK_s:
                    player1->y++;
                    break;
                case SDLK_d:
                    player1->x++;
                    break;
            }
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {

            }
    }
}

void render (Player player1) {  //Renderer & Shape Drawer
    SDL_SetRenderDrawColor(renderer, 2, 32, 100, 255);
    SDL_RenderClear(renderer);

    Rect playerRect = defineRect(player1.x, player1.y, player1.sizeX, player1.sizeY);  //Define Player Dimensions
    SDL_Rect playerDraw = drawRect(playerRect);  //Create Player

    SDL_SetRenderDrawColor(renderer, 217, 177, 107, 255);
    SDL_RenderFillRect(renderer, &playerDraw);

    SDL_RenderPresent(renderer);
}

Rect defineRect (int x, int y, int w, int h) {  //Create Rectangle
    Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return rect;
}

SDL_Rect drawRect (Rect rect) {
    SDL_Rect sdlRect;
    sdlRect.x = rect.x;
    sdlRect.y = rect.y;
    sdlRect.w = rect.w;
    sdlRect.h = rect.h;
    return sdlRect;
}

int startSDL () {  //Start Window Creation & Renderer Creation
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL Initialization Failed: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow(
        "SDLWarrior Window!!!",  //Title
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

