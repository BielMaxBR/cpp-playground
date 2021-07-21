#pragma once

#include <vector>

#include <tile.h>
#include <tilemap.h>

class Pathfinder {
    private:
        std::vector<Tile> openList;
        std::vector<Tile> closedList;
        Tile start;
        Tile end;
        bool running = false;
    public:
        Pathfinder(Tilemap *tilemap, Vector2 start_p, Vector2 end_p);
        
        void startFind();
        bool isRunning();

        void addClosed(Tile tile);

        void update(Tilemap *tilemap);
};