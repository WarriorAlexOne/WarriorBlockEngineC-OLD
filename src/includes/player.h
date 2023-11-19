#ifndef PLAYER_H
#define PLAYER_H

#include "controls.h"

//Player Values
typedef struct {
    float x;
    float y;
    float sizeX;
    float sizeY;
} Player;

//Forward Declarations
float playerLoop (Player* player, float deltaTime);

float playerLoop (Player* player, float deltaTime) {

}

#endif