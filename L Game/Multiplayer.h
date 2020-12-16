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
    public:
         int dim;///200 x 200 px each cell
         int posX, posY;
    public:
        void setPosition(int pX,int pY)
        {
            posX = pX;
            posY = pY;
        }

        void setColor(int color);///set the color of the cell
        void drawCell(int left,int up,int right,int bottom);
        int changeCellSize(int newSize);

};

void drawBoard();
void startMultiplayerGame();
