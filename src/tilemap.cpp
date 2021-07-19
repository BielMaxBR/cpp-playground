#include <cstdint>
#include <vector>
#include <iostream>
#include <SDL.h>

#include <tile.h>
#include <tilemap.h>
#include <vector2.h>

Tilemap::Tilemap(uint64_t width, uint64_t height) {
    grid.reserve(width);
    for (size_t x = 0; x < width; x++) {

        grid.push_back(std::vector<Tile>());
        grid[x].reserve(height);

        for (size_t y = 0; y < height; y++) {

            grid[x].push_back(Tile(x, y));
        }
    }
}

Tile Tilemap::getTile(uint64_t x, uint64_t y) {
    return grid[x][y];
}