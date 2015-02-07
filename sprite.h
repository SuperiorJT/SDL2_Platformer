//
//  sprite.h
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/6/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#ifndef __SDL_Game_Sample__sprite__
#define __SDL_Game_Sample__sprite__

#ifdef WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <stdio.h>

struct sprite {
    SDL_Surface* image;
    SDL_Rect* sprite;
    
    void (*moveX)(int);
    void (*moveY)(int);
};

#endif /* defined(__SDL_Game_Sample__sprite__) */
