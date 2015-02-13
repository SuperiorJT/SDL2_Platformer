//
//  Collision.c
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/11/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#include "Collision.h"

SDL_bool collision(SDL_Rect* a, SDL_Rect* b) {
    
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    leftA = a->x;
    rightA = a->x + a->w;
    topA = a->y;
    bottomA = a->y + a->h;
    
    leftB = b->x;
    rightB = b->x + b->w;
    topB = b->y;
    bottomB = b->y + b->h;
    
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        //printf("Top");
        return SDL_FALSE;
    }
    
    if( topA >= bottomB )
    {
        //printf("Bottom");
        return SDL_FALSE;
    }
    
    if( rightA <= leftB )
    {
        //printf("Left");
        return SDL_FALSE;
    }
    
    if( leftA >= rightB )
    {
        //printf("Right");
        return SDL_FALSE;
    }
    
    //If none of the sides from A are outside B
    return SDL_TRUE;
}

CollisionSide getCollisionSide(SDL_Rect* a, SDL_Rect* b) {
    if (a->y <= b->y - (b->h / 2)) {
        return BOTTOM;
    }
    if (a->y >= b->y + (b->h / 2)) {
        return TOP;
    }
    if (a->x < b->x) {
        return LEFT;
    }
    if (a->x > b->x) {
        return RIGHT;
    }
    printf("Error: Collision side not detected\n");
    return NULL;
}