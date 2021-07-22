#include <SDL.h>

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

void Pathfinder::update(Tilemap *tilemap) {

    for(unsigned long i = 0; i < closedList.size(); i++) {
        Tile tile = *closedList[i];

        for(unsigned long j = 0; j < tile.neighbors.size(); j++) {
            Tile* neighbor = tilemap->getTile(tile.getNeighbor(j));

            neighbor->setColor(OPEN);
            //SDL_Log("neighbor pos: %llu %llu",neighbor.position.x, neighbor.position.y);
        }
    }
    running = false;
};