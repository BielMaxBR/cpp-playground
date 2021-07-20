#include <pathfinder.h>
#include <vector2.h>
#include <tilemap.h>
#include <constants.h>

Pathfinder::Pathfinder(Tilemap *tilemap, Vector2 start_p, Vector2 end_p) {
    start = tilemap->getTile(start_p);
    end = tilemap->getTile(end_p);

    tilemap->setColor(Vector2(0,0), START);
    tilemap->setColor(end_p, END);
}