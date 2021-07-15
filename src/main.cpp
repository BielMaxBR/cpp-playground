#include <stdio.h>
#include <SDL.h>
#include <emscripten.h>
#include <emscripten/html5.h>

#include <window.h>

#define TILESIZE 12
#define WIDTH 50
#define HEIGHT 50

Window window;

SDL_Color grid[WIDTH][HEIGHT];

const SDL_Color NONE = {255,255,255,255};
const SDL_Color WALL = {0,0,0,255};
const SDL_Color START = {50,255,50,255};
const SDL_Color END = {255,50,50,255};


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
    
    for (int x = 0; x  < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            SDL_Color color = grid[x][y];
            
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

	for (int x = 0; x  < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
             if(x==y) {
                 grid[x][y] = WALL;
            } else {
	            grid[x][y] = NONE;
	        }
        
        }
	}
	
	grid[0][0] = START;
	grid[WIDTH-1][HEIGHT-1] = END;
	
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
