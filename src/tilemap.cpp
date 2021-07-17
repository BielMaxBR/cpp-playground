#include <cstdint>
#include <vector>
#include <iostream>

#include <tile.h>
#include <tilemap.h>
#include <vector2.h>

Tilemap::Tilemap(uint64_t width, uint64_t height) {
    grid.reserve(width * 2);
    for (size_t x = 0; x < width * 2; x++) {

        grid.push_back(std::vector<Tile>());
        grid[x].reserve(height * 2);

        for (size_t y = 0; y < height * 2; y++) {

            grid[x].push_back(Tile(x, y));
        }
    }
}

Tile Tilemap::getTile(uint64_t x, uint64_t y) {
    return grid[x][y];
}