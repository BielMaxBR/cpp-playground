#pragma once

#include <SDL.h>
#include <cstdint>
#include <vector>

#include <vector2.h>

class Tile {
    private: 
        double G = 1.0;
        double H = 0;
        double F = 0;
        Tile *parent;
        
    public: 
        Vector2 position;    
        std::vector<Vector2> neighbors;
        SDL_Color color = {255, 255, 255, 255};

        Tile();
        Tile(Vector2 position_p);
        Tile(uint64_t x, uint64_t y);

        void setColor(SDL_Color color_p);
        SDL_Color getColor();

        void addNeighbor(Vector2 neighbor);
        Vector2 getNeighbor(int index);

        double calcH(Vector2 finish);
        double calcF();

        double getF();
};