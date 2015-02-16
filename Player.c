//
//  Player.c
//  SDL-Game-Sample
//
//  Created by Justin Miller on 2/9/15.
//  Copyright (c) 2015 Justin Miller. All rights reserved.
//

#include "Player.h"
#include "numbers.h"
#include "Collision.h"

#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32
#define PLAYER_GRAVITY .1
#define PLAYER_JUMP 27.5
#define PLAYER_MAX_SPEED .25
#define PLAYER_START_SPEED .5

void Player_destroy(void* self) {
    Player* this = self;
    this->sprite->destroy(this->sprite);
    if (this != NULL) {
        free(this);
    }
}

void Player_handleCollision(void* playerObject, void* selfRect, void* otherRect) {
    Player* player = playerObject;
    SDL_Rect* playerRect = selfRect;
    SDL_Rect* other = otherRect;
    
    if (collision(playerRect, other)) {
        CollisionSide side = getCollisionSide(player->prevRect, other);
        switch (side) {
            case BOTTOM:
                player->state->pos.y = other->y - playerRect->h;
                playerRect->y = round(player->state->pos.y);
                player->jumping = SDL_FALSE;
                player->jumpCounter = 0;
                player->state->vel.y = 0;
                //printf("gets Bottom");
                break;
            case TOP:
                player->state->pos.y = other->y + other->h;
                playerRect->y = round(player->state->pos.y);
                player->state->vel.y = 0;
                //printf("gets Top");
                break;
            case LEFT:
                //printf("gets Left");
                break;
            case RIGHT:
                //printf("gets Right");
                break;
            default:
                break;
        }
    }
}

void Player_jump(void* self, float dt) {
    Player* this = self;
    if (this->jumping == SDL_FALSE) {
        this->state->vel.y -= PLAYER_JUMP * dt;
        this->jumping = SDL_TRUE;
    }
    if (this->jumpCounter == 100 && this->jumping == SDL_TRUE) {
        this->state->vel.y -= PLAYER_JUMP/2.5 * dt;
    }
    this->jumpCounter++;
}

void Player_move(void* self, float x, float dt) {
    Player* this = self;
    if (this->jumping == SDL_TRUE) {
        x = x * 0.85;
    }
    this->state->vel.x += x * dt;
    if (x == 0 && this->jumping == SDL_FALSE) {
        if (this->state->vel.x > 0) {
            this->state->vel.x -= .05 * dt;
        }
        if (this->state->vel.x < 0) {
            this->state->vel.x += .05 * dt;
        }
        if (this->state->vel.x < .01 && this->state->vel.x > 0) {
            this->state->vel.x = 0;
        }
        if (this->state->vel.x > -.01 && this->state->vel.x < 0) {
            this->state->vel.x = 0;
        }
    }
}

void Player_update(void* self, float dt) {
    Player* this = self;
    this->prevRect->x = this->sprite->rect->x;
    this->prevRect->y = this->sprite->rect->y;
    this->state->vel.y += PLAYER_GRAVITY * dt;
    if (this->state->vel.x > PLAYER_MAX_SPEED) {
        this->state->vel.x = PLAYER_MAX_SPEED;
    }
    if (this->state->vel.x < -PLAYER_MAX_SPEED) {
        this->state->vel.x = -PLAYER_MAX_SPEED;
    }
    this->state->pos.x += this->state->vel.x;
    this->state->pos.y += this->state->vel.y;
    if (this->jumping == SDL_TRUE) {
        printf("jumping, %li", this->jumpCounter);
    }
    this->sprite->rect->x = round(this->state->pos.x);
    this->sprite->rect->y = round(this->state->pos.y);
}

Player* Player_init(SDL_Renderer* renderer, const char* bmp) {
    Player* this = malloc(sizeof(Player));
    this->sprite = Sprite_init(renderer, bmp);
    this->sprite->rect->w = PLAYER_WIDTH;
    this->sprite->rect->h = PLAYER_HEIGHT;
    this->prevRect = calloc(1, sizeof(SDL_Rect));
    this->prevRect->w = PLAYER_WIDTH;
    this->prevRect->h = PLAYER_HEIGHT;
    this->state = calloc(1, sizeof(State));
    this->destroy = &Player_destroy;
    this->jump = &Player_jump;
    this->jumpCounter = 0;
    this->move = &Player_move;
    this->update = &Player_update;
    this->handleCollision = &Player_handleCollision;
    return this;
}