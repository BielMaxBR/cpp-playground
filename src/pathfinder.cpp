#include <SDL.h>
#include <stdio.h>


#include <pathfinder.h>
#include <vector2.h>
#include <tilemap.h>
#include <constants.h>

Pathfinder::Pathfinder(Tilemap *tilemap, Vector2 start_p, Vector2 end_p) {
    start = tilemap->getTile(start_p);
    end = tilemap->getTile(end_p);

    // tilemap->setColor(start_p, START);
    // tilemap->setColor(end_p, END);
    start->setColor(START);
    end->setColor(END);
};

void Pathfinder::startFind() {
    addClosed(start);
    running = true;
};

bool Pathfinder::isRunning() {
    return running;
};

void Pathfinder::addClosed(Tile* tile) {
    closedList.push_back(tile);
};

void Pathfinder::removeClosed(Tile* tile) {
    closedList.erase(std::remove(closedList.begin(), closedList.end(), tile), closedList.end());
};

void Pathfinder::addOpen(Tile* tile) {
    openList.push_back(tile);
 };


void Pathfinder::removeOpen(Tile* tile) {
    openList.erase(std::remove(openList.begin(), openList.end(), tile), openList.end());
};

void Pathfinder::update(Tilemap *tilemap) {

    for(unsigned long i = 0; i < openList.size(); i++) {
        Tile* tile = openList[i];
        for(unsigned long j = 0; j < tile->neighbors.size(); j++) {
            Tile* neighbor = tilemap->getTile(tile->getNeighbor(j));

            neighbor->setColor(OPEN);
            addOpen(neighbor);
        }
    }
    running = false;
};