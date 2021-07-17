#pragma once

#include <vector>
#include <cstdint>

#include <tile.h>

class Tilemap {
    private:
        std::vector<std::vector<Tile>> grid;
    public:
        Tilemap(uint64_t width, uint64_t height);
        Tile getTile(uint64_t x, uint64_t y);
};