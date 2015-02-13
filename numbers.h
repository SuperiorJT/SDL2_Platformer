//
//  numbers.h
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/9/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#ifndef __SDL_Game_Sample__numbers__
#define __SDL_Game_Sample__numbers__

#define round(x) ((x)>=0?(Uint32)((x)+0.5):(Uint32)((x)-0.5))
#define abs(x) ((x)<0?(x * -1):(x))

#include <stdio.h>

struct Vector {
    float x;
    float y;
};

typedef struct Vector Vector;

struct State {
    Vector pos; // position
    Vector vel; // velocity
};

typedef struct State State;

#endif /* defined(__SDL_Game_Sample__numbers__) */
