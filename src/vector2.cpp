#include <vector2.hpp>
#include <cstdint>
#include <math.h>

Vector2::Vector2(double x_p, double y_p) {
    x = x_p;
    y = y_p;
}

Vector2 Vector2::sub(Vector2 vect) {
    return Vector2(x - vect.x, y - vect.y);
}
Vector2 Vector2::add(Vector2 vect) {
    return Vector2(x + vect.x, y + vect.y);
}

double Vector2::distance(Vector2 vect) {
    return sqrt(pow(x - vect.x, 2) + pow(y - vect.y, 2));
};

bool Vector2::compare(Vector2 vect) {
    if(vect.x == x && vect.y == y) {
        return true;
    } else {
        return false;
    }
};


Vector2 Vector2::UP(0, 1);
Vector2 Vector2::DOWN(0, -1);
Vector2 Vector2::LEFT(-1, 0);
Vector2 Vector2::RIGHT(1, 0);
Vector2 Vector2::ZERO(0, 0);