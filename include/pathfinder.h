#pragma once

#include <vector>

#include <tile.h>

class Pathfinder {
    private:
        std::vector<Tile> openList;
        std::vector<Tile> closedList;
        Tile start;
        Tile end;
    public:
        Pathfinder(Tile start_p, Tile end_p);
};