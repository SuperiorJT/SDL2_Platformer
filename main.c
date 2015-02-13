#define SDL_MAIN_HANDLED
#define SCREEN_w 640
#define SCREEN_h 480
#define SCREEN_SCALE 1
#define SCREEN_NAME "Prototype"

#ifdef WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include "Player.h"
#include "Block.h"

void game_init(void);
void game_quit(void);

static struct {
    SDL_bool running;
    struct {
        unsigned int w;
        unsigned int h;
        const char* name;
        SDL_Window* window;
        SDL_Renderer* renderer;
    } screen;
    void (*init)(void);
    void (*quit)(void);
} Game = {
    SDL_FALSE,
    {
        SCREEN_SCALE*SCREEN_w,
        SCREEN_SCALE*SCREEN_h,
        SCREEN_NAME,
        NULL,
        NULL
    },
    game_init,
    game_quit
};

void game_init(void) {
    printf("game_init()\n");
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0) {
        printf("SDL error -> %s\n", SDL_GetError());
        exit(1);
    }
    
    unsigned int w = Game.screen.w;
    unsigned int h = Game.screen.h;
    const char* name = Game.screen.name;
    
    Game.screen.window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    Game.screen.renderer = SDL_CreateRenderer(Game.screen.window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(Game.screen.renderer, 0xFF, 0x00, 0xFF, 0xFF);
    
    Game.running = SDL_TRUE;
}

void game_quit(void) {
    printf("game_quit()\n");
    SDL_DestroyWindow(Game.screen.window);
    SDL_DestroyRenderer(Game.screen.renderer);
    
    Game.screen.window = NULL;
    Game.screen.renderer = NULL;
    
    SDL_Quit();
    Game.running = SDL_FALSE;
}

void generateDemo(Block* blocks[]) {
    int floorY = 448;
    int blockIndex = 0;
    for (int i = 0; i < Game.screen.w; i += 32) {
        blocks[blockIndex] = Block_init(Game.screen.renderer, "block.bmp", i, floorY);
        blockIndex++;
    }
}

void renderBlocks(Block* blocks[]) {
    for (int i = 0; i < 20; i++) {
        SDL_RenderCopy(Game.screen.renderer, blocks[i]->sprite->image, NULL, blocks[i]->sprite->rect);
    }
}

void updatePlayer(Player* player, const Uint8* keystate, float timeStep) {
    if (keystate[SDL_SCANCODE_LEFT]) {
        player->move(player, -.05, timeStep);
    }
    if (keystate[SDL_SCANCODE_RIGHT]) {
        player->move(player, .05, timeStep);
    }
    if (!keystate[SDL_SCANCODE_RIGHT] && !keystate[SDL_SCANCODE_LEFT]) {
        player->move(player, 0, timeStep);
    }
    if (keystate[SDL_SCANCODE_SPACE]) {
        player->jump(player, timeStep);
    }
    player->update(player, timeStep);
}

void checkCollisions(Player* player, Block* blocks[]) {
    for (int i = 0; i < 20; i++) {
        player->handleCollision(player, player->sprite->rect, blocks[i]->sprite->rect);
    }
}

int main(int argc,char *argv[])
{
    Game.init();
    
    printf("running = %d\n", Game.running);
    
    Player* player = Player_init(Game.screen.renderer, "player.bmp");
    Block* blocks[20];
    
    generateDemo(blocks);
    
    SDL_Event event;
    const Uint8* keystate;
    
    float prevUpdate = (float)(SDL_GetTicks() / 1000.0f);
    float accumulator = 0.0f;
    const float tickRate = 1.0f / 60.0f;
    
    while(Game.running) {
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    Game.running = SDL_FALSE;
                    break;
            }
        }
        
        float thisUpdate = ((float)SDL_GetTicks() / 1000.0f) - (float)prevUpdate;
        if (thisUpdate > 0.25f) {
            thisUpdate = 0.25f;
        }
        accumulator += thisUpdate;
        prevUpdate = (float)thisUpdate;
        //printf("step: %f\n", timeStep);
        keystate = SDL_GetKeyboardState(NULL);
        while (accumulator >= tickRate) {
            updatePlayer(player, keystate, tickRate);
            checkCollisions(player, blocks);
            accumulator -= tickRate;
            //printf("rate: %f, step: %f, acc: %f\n", tickRate, thisUpdate, accumulator);
        }
        SDL_RenderClear(Game.screen.renderer);
        renderBlocks(blocks);
        SDL_RenderCopy(Game.screen.renderer, player->sprite->image, NULL, player->sprite->rect);
        SDL_RenderPresent(Game.screen.renderer);
        
    }
    
    printf("running = %d\n", Game.running);
    
    Game.quit();
    
    return 0;

}
