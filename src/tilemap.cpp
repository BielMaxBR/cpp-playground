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
    std::vector<std::vector<Tile*>> cells;

    cells.reserve(round(grid.size()/2));

    for(size_t x = 0; x < grid.size(); x+=2) {
        cells.push_back(std::vector<Tile*>());
        cells[cells.size()-1].reserve(round(grid[x].size()/2));
        
        for(size_t y = 0; y < grid[x].size(); y+=2) {
            Tile* cell = getTile(x, y);

            cells[cells.size()-1].push_back(cell);
        }
    }

    for(size_t x = 0; x < cells.size(); x++) {

        for(size_t y = 0; y < cells[x].size(); y++) {

            cells[x][y]->type = TYPE_NONE;
            cells[x][y]->setColor(COLOR_NONE);
        }
    }
    Tile* current = cells[0][0];

    std::vector<Vector2> neighborsCells;

    bool callbackFunc(Vector2 neighborPosition) {
        Tile* neighborCell = getTile(neighborPosition);

        if(neighborCell->type == TYPE_WALL) {
            neighborCell->type = TYPE_NONE;
            neighborCell->setColor(COLOR_NONE);
            return true;
        }
        return false;
    }

    neighborsCells = current->getAllNeighbors(callbackFunc);
    
    if(neighborsCells.size() > 0) {
        int num = rand() % neighborsCells.size();
        //Tile* chosen = cells[neighborsCells[num]->position.x][neighborsCells[num]->position.y];

    }
};