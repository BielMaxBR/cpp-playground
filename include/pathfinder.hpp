#pragma once

#include <vector>

#include <tile.hpp>
#include <tilemap.hpp>

class Pathfinder {
    private:
        std::vector<Tile*> openList;
        std::vector<Tile*> closedList;
        Tile* start;
        Tile* end;
        bool running = false;
    public:
        std::vector<Tile*> path;
        Pathfinder(Tilemap* tilemap, Vector2 start_p, Vector2 end_p);
        
        void startFind();
        bool isRunning();

        bool isStartOrEnd(Tile* tile);

        void addClosed(Tile* tile);
        void removeClosed(Tile* tile);

        void addOpen(Tile* tile);
        void addOpen(Tile* tile, int position);
        void removeOpen(Tile* tile);

        void reconstructPath(Tile* tile);

        void update(Tilemap* tilemap);

        bool findInVector(std::vector<Tile*> vector, Tile* tile);
};