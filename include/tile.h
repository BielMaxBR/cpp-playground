#pragma once

#include <vector2.h>

class Tile {
    private: 
        float G;
        float H;
        float F;
        Vector2 neighbors[4];
        Vector2 parent;
        Vector2 position;
    
    public: 
        Tile(Vector2 position_p, Vector2 parent_p);
        calcH(Vector2 finish);
        calcF();
}