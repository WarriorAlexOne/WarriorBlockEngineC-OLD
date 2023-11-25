#ifndef DETECTION_H
#define DETECTION_H

#include <SDL2/SDL.h>

int windowSizeX;
int windowSizeY;
int mouseX;
int mouseY;

int detectionLoop (SDL_Window* window);
int collisionDetection (int x1, int y1, int sizeX1, int sizeY1, int x2, int y2, int sizeX2, int sizeY2);

int detectionLoop (SDL_Window* window) {
    SDL_GetWindowSize(window, &windowSizeX, &windowSizeY);
    SDL_GetMouseState(&mouseX, &mouseY);
}

int collisionDetection (int x1, int y1, int sizeX1, int sizeY1, int x2, int y2, int sizeX2, int sizeY2) {
    return x1 < x2 + sizeX2 && x1 + sizeX1 > x2 && y1 < y2 + sizeY2 && y1 + sizeY1 > y2;
}

#endif