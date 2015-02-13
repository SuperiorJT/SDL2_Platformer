//
//  sprite.c
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/6/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#include "sprite.h"

void Sprite_destroy(void* self) {
	Sprite* this = self;
	if (this != NULL) {
		free(this);
	}
	else {
		printf("Error: Sprite is already NULL");
	}
}

Sprite* Sprite_init(SDL_Renderer* renderer, const char* bmp) {
	Sprite* this = malloc(sizeof(Sprite));
    SDL_Surface* temp = SDL_LoadBMP(bmp);
    this->image = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
    this->rect = calloc(1, sizeof(SDL_Rect));
	this->destroy = &Sprite_destroy;
	return this;
}