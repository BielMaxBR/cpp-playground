#pragma once

#include <cstdint>

class Vector2 {
    public: 
        uint64_t x;
        uint64_t y;
        Vector2(uint64_t x_p, uint64_t y_p);

        Vector2 sub(Vector2 vect);
        Vector2 add(Vector2 vect);
};