#include <tile.h>
#include <tilemap.h>
#include <vector2.h>

Tilemap::Tilemap(int64_t width, int64_t height) {
    for(int64_t x = 0; x < width; x++) {
        for(int64_t y = 0; y < height; y++) {

            Vector2 vector(x, y);
             
            grid[x][y] = Tile(vector);
        }
    }
}

Tile Tilemap::getTile(int64_t x, int64_t y) {
    return grid[x][y];
}