#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "variables.h"

//Window Constants
char versionNumber[35] = "WarriorBlockEngine 0.2.3";  //Extra Memory Allocated for extra letters.
SDL_Window* window;
SDL_Renderer* renderer;
int windowDefaultSizeX = 1760;
int windowDefaultSizeY = 960;

//Frame Constants
short frameTarget = 60;  //Default is 60.
double gameTime = 1.0;  //Smaller number means slower game. Default is 1.

#endif