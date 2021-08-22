#include <SDL.h>
#include <stdio.h>
#include <string>

#include <pathfinder.hpp>
#include <vector2.hpp>
#include <tilemap.hpp>
#include <constants.hpp>

Pathfinder::Pathfinder(Tilemap* tilemap, Vector2 start_p, Vector2 end_p) {
    start = tilemap -> getTile(start_p);
    end = tilemap -> getTile(end_p);
};

void Pathfinder::startFind() {
    start-> setColor(COLOR_START);
    end-> setColor(COLOR_END);

    end->type = TYPE_NONE;
    start->type = TYPE_NONE;

    addOpen(start);
    running = true;
};

bool Pathfinder::isRunning() {
    return running;
};

bool Pathfinder::isStartOrEnd(Tile* tile) {
    return tile->position.compare(start->position) || tile->position.compare(end->position);
}

void Pathfinder::addClosed(Tile* tile) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(COLOR_CLOSED);
    }
    closedList.push_back(tile);
};

void Pathfinder::removeClosed(Tile* tile) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(COLOR_NONE);
    }
    closedList.erase(std::remove(closedList.begin(), closedList.end(), tile), closedList.end());
};

void Pathfinder::addOpen(Tile* tile) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(COLOR_OPEN);
    }
    openList.push_back(tile);
};

void Pathfinder::addOpen(Tile* tile, int position) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(COLOR_OPEN);
    }
    openList.insert(openList.begin() + position, tile);
};

void Pathfinder::removeOpen(Tile* tile) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(COLOR_NONE);
    }
    openList.erase(std::remove(openList.begin(), openList.end(), tile), openList.end());
};

void Pathfinder::reconstructPath(Tile* tile) {
    Tile* actualTile = tile;
    while (actualTile != start) {
        if (actualTile != end) {
            actualTile->setColor(COLOR_PATH);
        }

        path.insert(path.begin(),actualTile);
        actualTile = actualTile->getParent();

    }
};

void Pathfinder::update(Tilemap* tilemap) {

    if(openList.size() == 0) {
        running = false;
        SDL_Log("caminho impossível");
        return;
    }

    Tile * current = openList.front();

    if (current->position.compare(end->position)) {
        running = false;
        SDL_Log("Caminho encontrado");
        reconstructPath(current);
        return;
    }
    removeOpen(current);
    addClosed(current);
    for(unsigned long i = 0; i < current -> neighbors.size(); i++) {
        Tile * neighbor = tilemap -> getTile(current -> getNeighbor(i));

        if (!findInVector(closedList,neighbor) && neighbor->type == TYPE_NONE) {
            
            if(findInVector(openList,neighbor)) {
                continue;
            }
            neighbor->addParent(current);

            float H = neighbor -> calcH(end -> position);
            float F = neighbor -> calcF();
            
            for (unsigned long j = 0; j < openList.size(); j++) {
                Tile * openTile = openList[j];

                if (F <= openTile -> getF()) {
                    addOpen(neighbor, j);
                    break;
                }
            }
            addOpen(neighbor);
            
        }
    }
    // running = false;
};


bool Pathfinder::findInVector(std::vector<Tile*> vector, Tile* tile) {
    return std::find(vector.begin(), vector.end(), tile) != vector.end();
} ;