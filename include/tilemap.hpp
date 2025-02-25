#pragma once

#include <SDL.h>
#include <cstdint>
#include <vector>

#include <tile.hpp>

class Tilemap {
private:
  Tile *current;
  std::vector<std::vector<Tile *>> cells;

  std::vector<Tile *> activeList;

public:
  std::vector<std::vector<Tile *>> grid;
  bool generating;
  Tilemap(uint64_t width, uint64_t height);

  Tile *getTile(uint64_t x, uint64_t y);
  Tile *getTile(Vector2 position);

  void setColor(Vector2 position, SDL_Color color);

  void generateMap();

  void update();

  bool isRunning();
};