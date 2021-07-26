#pragma once

#include <cstdint>

class Vector2 {
    public: 
        double x;
        double y;
        Vector2(double x_p, double y_p);

        Vector2 sub(Vector2 vect);
        Vector2 add(Vector2 vect);
        
        double distance(Vector2 vect);

        bool compare(Vector2 vect);
};