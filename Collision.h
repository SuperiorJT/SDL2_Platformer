//
//  Collision.h
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/11/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#ifndef __SDL_Game_Sample__Collision__
#define __SDL_Game_Sample__Collision__

#include <stdio.h>
#include "sprite.h"
#include "numbers.h"


/**
 *  \brief Enum specifying side a collision occurs
 *
 *  \sa collision
 *  \sa getCollisionSide
 */
enum CollisionSide {
    TOP, RIGHT, BOTTOM, LEFT, UNKNOWN
};

typedef enum CollisionSide CollisionSide;

/**
 *  \brief returns SDL_TRUE if a collision occurs between
 *       two SDL_Rects
 */
SDL_bool collision(SDL_Rect* a, SDL_Rect* b);

/**
 *  \brief returns the CollisionSide of which the collision
 *         occurs between two SDL_Rects
 *
 *  \sa CollisionSide
 */
CollisionSide getCollisionSide(SDL_Rect* a, SDL_Rect* b);

#endif /* defined(__SDL_Game_Sample__Collision__) */
