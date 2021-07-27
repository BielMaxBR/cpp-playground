#include <SDL.h>
#include <stdio.h>
#include <string>

#include <pathfinder.h>
#include <vector2.h>
#include <tilemap.h>
#include <constants.h>

Pathfinder::Pathfinder(Tilemap* tilemap, Vector2 start_p, Vector2 end_p) {
    start = tilemap -> getTile(start_p);
    end = tilemap -> getTile(end_p);

    start -> setColor(START);
    end -> setColor(END);
};

void Pathfinder::startFind() {
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
        tile->setColor(CLOSED);
    }
    closedList.push_back(tile);
};

void Pathfinder::removeClosed(Tile* tile) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(NONE);
    }
    closedList.erase(std::remove(closedList.begin(), closedList.end(), tile), closedList.end());
};

void Pathfinder::addOpen(Tile* tile) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(OPEN);
    }
    openList.push_back(tile);
};

void Pathfinder::addOpen(Tile* tile, int position) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(OPEN);
    }
    openList.insert(openList.begin() + position, tile);
};

void Pathfinder::removeOpen(Tile* tile) {
    if (!isStartOrEnd(tile)) {
        tile->setColor(NONE);
    }
    openList.erase(std::remove(openList.begin(), openList.end(), tile), openList.end());
};

void Pathfinder::reconstructPath(Tile* tile) {
    Tile* actualTile = tile;
    while (actualTile != start) {
        if (actualTile != end) {
            actualTile->setColor(PATH);
        }

        path.insert(path.begin(),actualTile);
        actualTile = actualTile->getParent();

    }
};

void Pathfinder::update(Tilemap* tilemap) {

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

        if (!findInVector(closedList,neighbor) && neighbor->type != "wall") {

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