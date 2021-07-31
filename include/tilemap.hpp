#pragma once

#include <vector>
#include <cstdint>
#include <SDL.h>

#include <tile.hpp>

class Tilemap {
    public:
        std::vector<std::vector<Tile*>> grid;

        Tilemap(uint64_t width, uint64_t height);

        Tile* getTile(uint64_t x, uint64_t y);
        Tile* getTile(Vector2 position);
        
        void setColor(Vector2 position, SDL_Color color);

        void generateMap();
};