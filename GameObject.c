//
//  GameObject.c
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/13/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#include "GameObject.h"

//void Block_destroy(void* self) {
//    GameObject* this = self;
//    this->sprite->destroy(this->sprite);
//    if (this != NULL) {
//        free(this);
//    }
//}
//
//void Block_update(void* self) {
//    GameObject* this = self;
//    this->sprite->rect->x = round(this->state->pos.x);
//    this->sprite->rect->y = round(this->state->pos.y);
//}
//
//GameObject* Block_init(SDL_Renderer* renderer, const char* bmp, int x, int y) {
//    GameObject* this = malloc(sizeof(GameObject));
//    this->sprite = Sprite_init(renderer, bmp);
//    this->sprite->rect->w = 32;
//    this->sprite->rect->h = 32;
//    this->sprite->rect->x = x;
//    this->sprite->rect->y = y;
//    this->state = calloc(1, sizeof(State));
//    this->destroy = &Block_destroy;
//    this->update = &Block_update;
//    return this;
//}