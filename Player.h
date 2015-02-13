//
//  Player.h
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/9/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#ifndef __SDL_Game_Sample__Player__
#define __SDL_Game_Sample__Player__

#include <stdio.h>
#include "sprite.h"
#include "numbers.h"

typedef struct Player Player;

struct Player {
    Sprite* sprite;
    State* state;
    SDL_Rect* prevRect;
    SDL_bool jumping;
    long jumpCounter;
    
    void (*destroy)(void* self);
    
    void (*handleCollision)(void* player, void* selfRect, void* otherRect);
    
    void (*jump)(void* self, float dt);
    void (*move)(void* self, float x, float dt);
    
    void (*update)(void* self, float dt);
};

Player* Player_init(SDL_Renderer* renderer, const char* bmp);
#endif /* defined(__SDL_Game_Sample__Player__) */
