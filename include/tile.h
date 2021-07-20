#pragma once

#include <SDL.h>
#include <cstdint>
#include <vector>

#include <vector2.h>

class Tile {
    private: 
        float G;
        float H;
        float F;
        Vector2 *parent;
        Vector2 position;    
        
    public: 
        std::vector<Vector2> neighbors;
        SDL_Color color = {255, 255, 255, 255};

        Tile();
        Tile(Vector2 position_p);
        Tile(uint64_t x, uint64_t y);

        void setColor(SDL_Color color_p);

        void addNeighbor(Vector2 neighbor);
        Vector2 getNeighbor(int index);

        float calcH(Vector2 finish);
        float calcF();
};