#ifndef PLAYER_H
#define PLAYER_H

#include "../tools/detection.h"
#include "../tools/vector.h"
#include "../tools/transform.h"

//Player Values
typedef struct {
    //Coords
    Transform transform;
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
        player->transform.position.x -= 5;
    }
    if (player->left) {
        player->transform.position.x -= 5;
    }
    if (player->down) {
        player->transform.position.y += 5;
    }
    if (player->right) {
        player->transform.position.y += 5;
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