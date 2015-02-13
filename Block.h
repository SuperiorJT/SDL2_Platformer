//
//  Block.h
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/11/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#ifndef __SDL_Game_Sample__Block__
#define __SDL_Game_Sample__Block__

#include <stdio.h>
#include "sprite.h"
#include "numbers.h"

typedef struct Block Block;

struct Block {
    Sprite* sprite;
    State* state;
    
    void (*destroy)(void* self);
    
    void (*update)(void* self);
};

Block* Block_init(SDL_Renderer* renderer, const char* bmp, int x, int y);

#endif /* defined(__SDL_Game_Sample__Block__) */
