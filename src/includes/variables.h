#ifndef VARIABLES_H
#define VARIABLES_H

#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

//Window Variables
int quit = 0;
int* pquit = &quit;

//Frame Variables
double lastFrameTime = 0;

//Camera Variables
double cameraX;
double cameraY;

#endif