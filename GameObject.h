//
//  GameObject.h
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/13/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#ifndef __SDL_Game_Sample__GameObject__
#define __SDL_Game_Sample__GameObject__

#include <stdio.h>
#include "sprite.h"
#include "numbers.h"

enum GameObjectType {
    ENEMY, BLOCK, PLATFORM, POWERUP
};
typedef enum GameObjectType GameObjectType;

typedef struct GameObject GameObject;

struct GameObject {
    Sprite* sprite;
    State* state;
    GameObjectType* type;
    char* tag;
    
    void (*destroy)(void* self);
    
    void (*update)(void* self);
};

#endif /* defined(__SDL_Game_Sample__GameObject__) */
