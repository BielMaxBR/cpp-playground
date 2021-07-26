#include <SDL.h>
#include <stdio.h>


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

void Pathfinder::update(Tilemap* tilemap) {

    Tile * current = openList.front();

    if (current->position.compare(end->position)) {
        running = false;
        return;
    }
    removeOpen(current);
    addClosed(current);
    for(unsigned long i = 0; i < current -> neighbors.size(); i++) {
        Tile * neighbor = tilemap -> getTile(current -> getNeighbor(i));

        if (std::find(openList.begin(), openList.end(), neighbor) == openList.end() && std::find(closedList.begin(), closedList.end(), neighbor) == closedList.end()) {

            float H = neighbor -> calcH(end -> position);
            float F = neighbor -> calcF();
                for (unsigned long j = 0; j < openList.size(); j++) {
                    Tile * openTile = openList[j];

                    if (F < openTile -> getF()) {
                        addOpen(neighbor, j);
                        return;
                    }
                }
                addOpen(neighbor);
            
        }
    }
    // running = false;
};