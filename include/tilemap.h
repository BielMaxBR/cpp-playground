#pragma once


class Tilemap {
    private:
        int grid[][];
    public:
        Tilemap(int width, int height);
        createGrid(int rows, int columns);
};