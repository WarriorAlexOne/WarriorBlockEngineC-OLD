#ifndef PLAYER_H
#define PLAYER_H

//Player Values
typedef struct {
    float x;
    float y;
    float sizeX;
    float sizeY;
    int up;
    int left;
    int down;
    int right;
} Player;

Player player = {
    0,  //x
    0,  //y
    500,  //sizeX
    500,  //sizeY
    0,  //up
    0,  //left
    0,  //down
    0  //right
};
Player* pplayer = &player;

//Forward Declarations
float playerLoop (Player* player, float deltaTime);


float playerLoop (Player* player, float deltaTime) {
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
}

#endif