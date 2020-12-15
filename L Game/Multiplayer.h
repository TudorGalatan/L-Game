#pragma once

#include <graphics.h>

class LObj///the L object on the board
{
    private:
        unsigned short color;
        unsigned short shape;///when we'll extend the game we'll add more shapes
};

class Cell///a cell on the board
{
    private:
        int dim = 200;///200 x 200 px each cell
    public:
        void setColor(int xCoord,int yCoord, int color);///set the color of the cell
        void drawCell(int left,int up,int right,int bottom);
        int changeCellSize(int newSize);

};

void drawBoard();
void startMultiplayerGame();
