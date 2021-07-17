#include <stdio.h>
#include <cstdint>
#include <SDL.h>
#include <emscripten.h>
#include <emscripten/html5.h>

#include <window.h>
#include <tilemap.h>
#include <tile.h>
#include <vector2.h>

#define TILESIZE 12
#define WIDTH 50
#define HEIGHT 50

Window window;

Tilemap tilemap(WIDTH, HEIGHT);


const SDL_Color NONE = {255, 255, 255, 255};
const SDL_Color WALL = {0, 0, 0, 255};
const SDL_Color START = {50, 255, 50, 255};
const SDL_Color END = {255, 50, 50, 255};
const SDL_Color OPEN = {50, 252, 249, 255};
const SDL_Color CLOSED = {50, 138, 252, 255};
const SDL_Color PATH = {50, 252, 138, 255};


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
    window.clear();
    
    
    for (uint64_t x = 0; x  < WIDTH; x++) {
        for (uint64_t y = 0; y < HEIGHT; y++) {
            Tile tile = tilemap.getTile(x, y);

            SDL_Color color = tile.color;
            
            window.renderTile(x, y, TILESIZE, color);
        }
    }
    
    
    window.display();
	     
}

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}
	
	window.create("SDL2 playground", 600, 600);
    printf("janela criada");

   

	#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(gameLoop, 0, 1);
	#else
	while (gameRunning) 
	{
    	gameLoop();
    	SDL_Delay(16);
	}
	#endif
	
    window.cleanUp();
	SDL_Quit();
	
	return 0;
}
