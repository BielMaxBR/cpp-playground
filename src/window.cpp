#include <SDL2/SDL.h>
#include <iostream>

#include "window.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Window::Window() {

}

void Window::create(const char* p_title, int p_w, int p_h) {
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


void Window::clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Window::renderTile(int x, int y, int tilesize, SDL_Color color) {
    SDL_Rect tile = {x*tilesize+1,y*tilesize+1,tilesize-2,tilesize-2};
            
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderFillRect(renderer, &tile);
}

void Window::display() {
	SDL_RenderPresent(renderer);
}

void Window::cleanUp() {
	SDL_DestroyWindow(window);
}