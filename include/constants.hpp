#pragma once

#include <SDL.h>

const SDL_Color COLOR_NONE = {255, 255, 255, 255};
const SDL_Color COLOR_WALL = {0, 0, 0, 255};
const SDL_Color COLOR_START = {50, 255, 50, 255};
const SDL_Color COLOR_END = {255, 50, 50, 255};
const SDL_Color COLOR_OPEN = {214, 219, 61, 255};
const SDL_Color COLOR_CLOSED = {48, 70, 240, 255};
const SDL_Color COLOR_PATH = {188, 61, 219, 255};

const int TYPE_NONE = 0;
const int TYPE_WALL = 1;