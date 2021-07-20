#include <SDL.h>

#include <pathfinder.h>
#include <vector2.h>
#include <tilemap.h>
#include <constants.h>

Pathfinder::Pathfinder(Tilemap *tilemap, Vector2 start_p, Vector2 end_p) {
    start = tilemap->getTile(start_p);
    end = tilemap->getTile(end_p);

    tilemap->setColor(Vector2(0,0), START);
    tilemap->setColor(end_p, END);
};

void Pathfinder::startFind() {
    addClosed(start);
    // running = true;
    SDL_Log("%llu", closedList.size());
};

bool Pathfinder::isRunning() {
    return running;
};

void Pathfinder::addClosed(Tile tile) {
    closedList.push_back(tile);
};

void Pathfinder::update(Tilemap tilemap) {
    for(unsigned long i = 0; i < closedList.size(); i++) {
        Tile tile = closedList[i];
        for(unsigned long j = 0; j < tile.neighbors.size(); j++) {
            Vector2 neighbor = tile.getNeighbor(j);
            tilemap.getTile(neighbor).setColor(OPEN);
            SDL_Log("%lu %llu %llu",j,neighbor.x, neighbor.y);
        }
    }
    running = false;
};