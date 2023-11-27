#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "../tools/detection.h"
#include "../tools/vector.h"
#include "../tools/transform.h"
#include "controls.h"


//Player Values
typedef struct {
    //Coords
    Transform transform;
    //Controls
    short up;
    short left;
    short down;
    short right;
    short leftClick;
    short rightClick;
    short middleClick;
    //Status
    short dragged;
} Player;

Player player = {
//Coords
    {{100,100},{500,500},{0,0}},
//Controls
    0,  //up
    0,  //left
    0,  //down
    0,  //right
    0,  //leftClick
    0, //rightClick
    0,  //middleClick
//Status
    0  //dragged
};
Player* pplayer = &player;

//Forward Declarations
float playerLoop (Player* player, float deltaTime);


float playerLoop (Player* player, float deltaTime) {
    //Temporary Movement
    if (checkPressed(SDL_SCANCODE_W)) {  //Up
        player->transform.position.y -= 5;
    }
    if (checkPressed(SDL_SCANCODE_A)) {  //Left
        player->transform.position.x -= 5;
    }
    if (checkPressed(SDL_SCANCODE_S)) {  //Down
        player->transform.position.y += 5;
    }
    if (checkPressed(SDL_SCANCODE_D)) {  //Right
        player->transform.position.x += 5;
    }
    //Mouse Drag
    if (collisionDetection(player->transform.position.x,player->transform.position.y,player->transform.size.x,player->transform.size.y,mouseX,mouseY,0,0) && player->leftClick) {
        player->dragged = 1;
    }
    if (player->dragged) {
        player->transform.position.x = mouseX-player->transform.size.x/2;
        player->transform.position.y = mouseY-player->transform.size.y/2;
        if (!player->leftClick) player->dragged = 0;  //Cheeky Nested If. Nothing to see here, move along.
    }
}

#endif