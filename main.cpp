#include <stdio.h>
#include <SDL.h>
#include <emscripten.h>
#include <emscripten/html5.h>

#define TILESIZE 12
#define WIDTH 50
#define HEIGHT 50

SDL_Color grid[WIDTH][HEIGHT];

const SDL_Color NONE = {255,255,255,255};
const SDL_Color WALL = {0,0,0,255};
const SDL_Color START = {50,255,50,255};
const SDL_Color END = {255,50,50,255};


bool gameRunning = true;

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_Window *window = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	
	if (window == NULL)
	{
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return 1;
	}
	
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
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
	
	while (gameRunning) {
        SDL_Event event;
	    while (SDL_PollEvent(&event))    {
        	switch (event.type) {
        	    case SDL_QUIT:    {
              		gameRunning = false;
          		break;
        	    }
        	}
     	}
     	
     	for (int x = 0; x  < WIDTH; x++) {
     	    for (int y = 0; y < HEIGHT; y++) {
     	        SDL_Color color = grid[x][y];
     	        
     	        SDL_Rect tile = {x*TILESIZE+1,y*TILESIZE+1,TILESIZE-1,TILESIZE-1};
     	        
     	        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
     	        SDL_RenderFillRect(renderer, &tile);
     	    }
     	}
     	
     	SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
	     
	    SDL_Delay(16);
     	    
 	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
