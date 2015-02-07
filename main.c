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
#include "sprite.h"

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

int main(int argc,char *argv[])
{
    Game.init();
    
    printf("running = %d\n", Game.running);
    
    SDL_Event event;
    
    while(Game.running) {
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    Game.running = SDL_FALSE;
                    break;
            }
        }
        SDL_RenderClear(Game.screen.renderer);
        SDL_RenderPresent(Game.screen.renderer);
    }
    
    printf("running = %d\n", Game.running);
    
    Game.quit();
    
    return 0;

}
