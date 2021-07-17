#include <SDL.h>
#include <cstdint>

#include <vector2.h>
#include <tile.h>

Tile::Tile() : position(0, 0) {

}

Tile::Tile(Vector2 position_p): position(position_p.x, position_p.y) {

}

Tile::Tile(uint64_t x, uint64_t y) : position(x, y){

}