#pragma once

#include <cstdint>

class Vector2 {
    public: 
        static Vector2 UP;
        static Vector2 DOWN;
        static Vector2 LEFT;
        static Vector2 RIGHT;
        static Vector2 ZERO;


        double x;
        double y;
        Vector2(double x_p, double y_p);

        Vector2 sub(Vector2 vect);
        Vector2 add(Vector2 vect);
        
        double distance(Vector2 vect);

        bool compare(Vector2 vect);
};