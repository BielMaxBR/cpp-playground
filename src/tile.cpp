#include <SDL.h>

#include <vector2.h>
#include <tile.h>

Tile::Tile() {
    Vector2 position(0, 0);
}

Tile::Tile(Vector2 position_p) {
    position = position_p;
}