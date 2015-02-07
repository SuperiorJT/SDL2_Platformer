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

	void (*destroy)(void* self);
    
    void (*moveX)(void* self, int magnitude);
    void (*moveY)(void* self, int magnitude);
};

typedef struct sprite Sprite;

Sprite* Sprite_init(SDL_Surface* temp, const char* bmp);

#endif /* defined(__SDL_Game_Sample__sprite__) */
