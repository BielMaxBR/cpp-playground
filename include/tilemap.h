#pragma once

#include <tile.h>
#include <vector>

class Tilemap {
    private:
        std::vector<std::vector<Tile>> grid;
    public:
        Tilemap(int64_t width, int64_t height);
        Tile getTile(int64_t x, int64_t y);
};