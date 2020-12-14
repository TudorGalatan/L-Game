#pragma once

class LObj///the L object on the board
{
    private:
        unsigned short color;
        unsigned short shape;///when we'll extend the game we'll add more shapes
};

class Cell
{
    private:
        int dim = 200;///200 x 200 px each cell
    public:
        void changeColor(int player)
        {

        }

};

void drawBoard();
void startMultiplayerGame();
