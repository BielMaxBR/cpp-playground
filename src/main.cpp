#include <stdio.h>
#include <cstdint>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <vector>
#include <emscripten.h>
#include <emscripten/html5.h>

#include <window.h>
#include <tilemap.h>
#include <tile.h>
#include <vector2.h>
#include <pathfinder.h>
#include <constants.h>

#define TILESIZE 12
#define WIDTH 50
#define HEIGHT 50

Window window;

Tilemap tilemap(WIDTH, HEIGHT);
Pathfinder finder(&tilemap, Vector2(0, 0), Vector2(WIDTH - 7, HEIGHT - 20));

bool gameRunning = true;

void gameLoop() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT: {
            gameRunning = false;
            break;
        }
        }
    }

    if (finder.isRunning()) {
        finder.update(&tilemap);
    }

    window.clear();

    for (uint64_t x = 0; x < WIDTH; x++) {
        for (uint64_t y = 0; y < HEIGHT; y++) {
            Tile tile = * tilemap.getTile(x, y);

            window.renderTile(x, y, TILESIZE, tile.getColor());
        }
    }

    window.display();

}

int main(int argc, char * argv[]) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    window.create("SDL2 playground", 600, 600);
    SDL_Log("janela criada");

    srand(time(NULL));

    finder.startFind();
    
    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(gameLoop, 0, 1);
    #else
    while (gameRunning) {
        gameLoop();
        SDL_Delay(16);
    }
    #endif

    window.cleanUp();
    SDL_Quit();

    return 0;
}