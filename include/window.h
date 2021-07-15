#pragma once
#include <SDL2/SDL.h>

class Window 
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Window();
	void create(const char* p_title, int p_w, int p_h);
	void clear();
	void renderTile(int x, int y, int tilesize, SDL_Color color);
	void display();
	void cleanUp();
};