#include <stdio.h>
#include <SDL2/SDL.h>

#define TILESIZE 10
#define WIDTH 50
#define HEIGHT 50

SDL_Color grid[WIDTH][HEIGHT];

bool gameRunning = true;

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
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
    
	/*SDL_Rect rec;
	
	rec.x = 10;
	rec.y = 20;
	rec.w = TILESIZE;
	rec.h = TILESIZE;
		
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rec);
 
    SDL_RenderPresent(renderer);
	SDL_UpdateWindowSurface(window);
	
	SDL_Delay(50000);*/
	
	grid[0][0].r = 255;
	
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
     	        
     	        SDL_Rect tile = {x*TILESIZE,y*TILESIZE,TILESIZE,TILESIZE};
     	        
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
