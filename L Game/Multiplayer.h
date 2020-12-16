#pragma once

#include <graphics.h>

#define SIZE 4

class LObj///the L object on the board
{
    private:
        unsigned short color;///4 is RED, 1 is BLUE
        unsigned short shape;///when we'll extend the game we'll add more shapes
        unsigned short positions[SIZE][SIZE];///positions occupied by the 'L' object
    public:
        int clickPosition()///THIS FUNCTION SHOULD RETURN THE NUMBER OF THE CELL WE CLICKED ON
        {
            int x,y;
            getmouseclick(VK_LBUTTON,x,y);
            ///TODO: check the clicked position and return the number of the cell the user clicked.
        }
};

class Coin
{
    private:
        int coinSize = 100;
    public:
        void drawCoin();
        int getCoinSize(){return coinSize;};
};

class Cell///a cell on the board
{
    private:
         int dim;///200 x 200 px each cell
         int posX, posY;///we store the positions used in setPosition()
         int cellColor;///stores the color of the cell
    public:
        void setPosition(int pX,int pY);///set the position to help the setColor function fill the right cell
        void setColor(int color);///set the color of the cell
        int getColor();///returns the color of the cell
        void drawCell(int left,int up,int right,int bottom);///draw the rectangle
        int changeCellSize(int newSize);///change the size of the cell (not used yet)
};

void redMove(Cell cell[][4]);
void drawBoard(Cell cell[][4]);
void startMultiplayerGame();
