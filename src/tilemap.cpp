#include <cstdint>
#include <vector>
#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

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
                newTile->addNeighbor(newTile->position.add(Vector2::DOWN));
            }
            if(y < height-1) {
                newTile->addNeighbor(newTile->position.add(Vector2::UP));
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
    std::vector<std::vector<Tile*>> cells;

    std::vector<Tile*> activeList;

    cells.reserve(round(grid.size()/2));

    for(size_t x = 0; x < grid.size(); x+=2) {
        cells.push_back(std::vector<Tile*>());
        cells[cells.size()-1].reserve(round(grid[x].size()/2));
        
        for(size_t y = 0; y < grid[x].size(); y+=2) {
            Tile* cell = getTile(x, y);

            cells[cells.size()-1].push_back(cell);
        }
    }

    Tile* current = cells[0][0];
    current->setColor(COLOR_NONE);
    current->type = TYPE_NONE;
    
    activeList.push_back(current);
        

    bool generating = true;
    // loop
    while (generating) {
        std::vector<Tile*> avaliableNeighbors;

        for(size_t i = 0; i < current->neighbors.size(); i++) {
            Vector2 direction = current->position.sub(current->neighbors[i]);
            Tile* cellNeighbor = cells[round(current->position.sub(direction).x/2)][round(current->position.sub(direction).y/2)];
            cellNeighbor->setColor(COLOR_NONE);
        }
        generating = false;
    }   

};