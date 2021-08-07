#pragma once

#include <SDL.h>
#include <cstdint>
#include <vector>
#include <string>

#include <vector2.hpp>
#include <constants.hpp>

class Tile {
    private: 
        double G = 1.0;
        double H = 0;
        double F = 0;
        Tile* parent;
        
    public: 
        Vector2 position;    
        int type = TYPE_WALL;
        SDL_Color color = COLOR_WALL;
        std::vector<Vector2> neighbors;

        typedef bool (*callbackFunc)(Vector2);

        Tile();
        Tile(Vector2 position_p);
        Tile(uint64_t x, uint64_t y);

        void setColor(SDL_Color color_p);
        SDL_Color getColor();

        void addParent(Tile* tile);
        Tile* getParent();

        void addNeighbor(Vector2 neighbor);
        Vector2 getNeighbor(int index);

        std::vector<Vector2> getAllNeighbors();
        std::vector<Vector2> getAllNeighbors(Tile::callbackFunc callback);

        double calcH(Vector2 finish);
        double calcF();

        double getF();
};