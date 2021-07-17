#pragma once

#include <SDL.h>
#include <cstdint>

#include <vector2.h>

class Tile {
    private: 
        float G;
        float H;
        float F;
        Vector2 *neighbors[4];
        Vector2 *parent;
        Vector2 position;    
    public: 
        SDL_Color color = {255, 255, 255, 255};

        Tile();
        Tile(Vector2 position_p);
        Tile(uint64_t x, uint64_t y);

        float calcH(Vector2 finish);
        float calcF();
};