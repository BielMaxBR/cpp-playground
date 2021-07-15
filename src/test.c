#include <SDL.h>
#include <emscripten.h>
#include <stdlib.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;

void drawRandomPixels() {
    if (SDL_MUSTLOCK(surface)) SDL_LockSurface(surface);

    Uint8 * pixels = surface->pixels;
    
    for (int i=0; i < 1048576; i++) {
        char randomByte = rand() % 255;
        pixels[i] = randomByte;
    }

    if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

    SDL_Texture *screenTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(screenTexture);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
    surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);
    
    emscripten_set_main_loop(drawRandomPixels, 0, 1);
}