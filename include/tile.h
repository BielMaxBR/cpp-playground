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
        
    public: 
        Vector2 position;    
        std::vector<Vector2> neighbors;
        SDL_Color color = {255, 255, 255, 255};

        Tile();
        Tile(Vector2 position_p);
        Tile(uint64_t x, uint64_t y);

        void setColor(SDL_Color color_p);
        SDL_Color getColor();

        void addNeighbor(Vector2 neighbor);
        Vector2 getNeighbor(int index);

        float calcH(Vector2 finish);
        float calcF();
};