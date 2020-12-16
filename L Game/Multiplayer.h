#pragma once

#include <graphics.h>

class LObj///the L object on the board
{
    private:
        unsigned short color;///4 is RED, 1 is BLUE
        unsigned short shape;///when we'll extend the game we'll add more shapes
};

class Coin
{
    private:
        int coinSize;
    public:
        void drawCoin();
};

class Cell///a cell on the board
{
    public:
         int dim;///200 x 200 px each cell
         int posX, posY;///we store the positions used in setPosition()
    public:
        void setPosition(int pX,int pY);///set the position to help the setColor function fill the right cell
        void setColor(int color);///set the color of the cell
        void drawCell(int left,int up,int right,int bottom);///draw the rectangle
        int changeCellSize(int newSize);///change the size of the cell (not used yet)
};

void drawBoard();
void startMultiplayerGame();
