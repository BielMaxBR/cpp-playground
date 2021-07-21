#include <vector2.h>
#include <cstdint>

Vector2::Vector2(uint64_t x_p, uint64_t y_p) {
    x = x_p;
    y = y_p;
}

Vector2 Vector2::sub(Vector2 vect) {
    return Vector2(x-vect.x, y-vect.y);
}
Vector2 Vector2::add(Vector2 vect) {
    return Vector2(x+vect.x, y+vect.y);
}