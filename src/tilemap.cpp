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
            Tile newTile(x, y);

            if(x > 0) {
                newTile.addNeighbor(Vector2(-1, 0));
            }
            if(x < width-1) {
                newTile.addNeighbor(Vector2(1, 0));
            }
            if(y > 0) {
                newTile.addNeighbor(Vector2(0, 1));
            }
            if(y < height-1) {
                newTile.addNeighbor(Vector2(0, -1));
            }

            grid[x].push_back(newTile);
        }
    }
}

Tile Tilemap::getTile(uint64_t x, uint64_t y) {
    return grid[x][y];
}
Tile Tilemap::getTile(Vector2 position) {
    return grid[position.x][position.y];
}

void Tilemap::setColor(Vector2 position, SDL_Color color) {
    grid[position.x][position.y].setColor(color);
}