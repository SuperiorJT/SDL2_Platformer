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

void Sprite_moveX(void* self, int magnitude) {
	Sprite* this = self;
	if (this->sprite != NULL) {
		this->sprite->x += magnitude;
	}
	else {
		printf("Error: SDL_Rect is null");
	}
}

void Sprite_moveY(void* self, int magnitude) {
	Sprite* this = self;
	if (this->sprite != NULL) {
		this->sprite->y += magnitude;
	}
	else {
		printf("Error: SDL_Rect is null");
	}
}

Sprite* Sprite_init(SDL_Surface* temp, const char* bmp) {
	Sprite* this = malloc(sizeof(Sprite));
	temp = SDL_LoadBMP(bmp);
	this->image = SDL_ConvertSurfaceFormat(temp, SDL_PIXELFORMAT_RGB24, 0);
	SDL_FreeSurface(temp);
	this->sprite->x = 0;
	this->sprite->y = 0;
	this->destroy = &Sprite_destroy;
	this->moveX = &Sprite_moveX;
	this->moveY = &Sprite_moveY;
	return this;
}