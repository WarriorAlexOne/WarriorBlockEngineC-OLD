#ifndef PLAYER_H
#define PLAYER_H

#include "../tools/detection.h"

//Player Values
typedef struct {
    //Coords
    float x;
    float y;
    float sizeX;
    float sizeY;
    //Controls
    int up;
    int left;
    int down;
    int right;
    int leftClick;
    int rightClick;
    int middleClick;
    //Status
    int dragged;
} Player;

Player player = {
//Coords
    0,  //x
    0,  //y
    500,  //sizeX
    500,  //sizeY
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
    if (player->up) {
        player->y -= 5;
    }
    if (player->left) {
        player->x -= 5;
    }
    if (player->down) {
        player->y += 5;
    }
    if (player->right) {
        player->x += 5;
    }
    //Mouse Drag
    if (collisionDetection(player->x,player->y,player->sizeX,player->sizeY,mouseX,mouseY,0,0) && player->leftClick) {
        player->dragged = 1;
    }
    if (player->dragged) {
        player->x = mouseX-player->sizeX/2;
        player->y = mouseY-player->sizeY/2;
        if (!player->leftClick) player->dragged = 0;  //Cheeky Nested If. Nothing to see here, move along.
    }
}

#endif