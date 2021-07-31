#include <cstdint>
#include <vector>
#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>

#include <tile.hpp>
#include <tilemap.hpp>
#include <vector2.hpp>
#include <constants.hpp>

Tilemap::Tilemap(uint64_t width, uint64_t height) {
    srand(time(NULL));

    grid.reserve(width);
    for (size_t x = 0; x < width; x++) {

        grid.push_back(std::vector<Tile*>());
        grid[x].reserve(height);

        for (size_t y = 0; y < height; y++) {
            Tile* newTile = new Tile(x, y);

            if(x > 0) {
                newTile->addNeighbor(newTile->position.add(Vector2::LEFT));
            }
            if(x < width-1) {
                newTile->addNeighbor(newTile->position.add(Vector2::RIGHT));
            }
            if(y > 0) {
                newTile->addNeighbor(newTile->position.add(Vector2::UP));
            }
            if(y < height-1) {
                newTile->addNeighbor(newTile->position.add(Vector2::DOWN));
            }

            grid[x].push_back(newTile);
        }
    }
}

Tile* Tilemap::getTile(uint64_t x, uint64_t y) {
    return grid[x][y];
}
Tile* Tilemap::getTile(Vector2 position) {
    return grid[position.x][position.y];
}

void Tilemap::setColor(Vector2 position, SDL_Color color) {
    grid[position.x][position.y]->setColor(color);
}

void Tilemap::generateMap() {

};