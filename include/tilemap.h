#pragma once

#include <tile.h>

class Tilemap {
    private:
        Tile grid[][];
    public:
        Tilemap(int width, int height);
};