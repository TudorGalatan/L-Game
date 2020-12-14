#pragma once

class LObj///the L object on the board
{
    private:
        unsigned short color;
        unsigned short shape;///when we'll extend the game we'll add more shapes
};


void drawBoard();
void startMultiplayerGame();
