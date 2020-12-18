/**
    This is the interface for the Player versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#pragma once

#include <graphics.h>
#include <fstream>

#define SIZE 4

/**
    Defines a player.
**/
class Player///the L object on the board (actually, a player)
{
    private:
        unsigned short color; ///4 is RED, 1 is BLUE // player, not colour
        unsigned short shape; ///when we'll extend the game we'll add more shapes
        unsigned short positions[SIZE][SIZE]; ///positions occupied by the 'L' object

    public:
        int clickPosition () ///THIS FUNCTION SHOULD RETURN THE NUMBER OF THE CELL WE CLICKED ON
        {
            int x, y;
            getmouseclick(VK_LBUTTON, x, y);
            ///TODO: check the clicked position and return the number of the cell the user clicked.
        }
};



/**
    Defines a coin.
**/
class Coin
{
    private:
        int coinSize = 100;

    public:
        void drawCoin (int xCoord, int yCoord);
        int getCoinSize () {return coinSize;};
};



/**
    Defines a cell.
**/
class Cell
{
    private:
         int dim; ///200 x 200 px each cell
         int posX=666, posY=666; ///we store the positions used in setPosition(), the 'spawn' position.
         int cellColor; ///stores the color of the cell

    public:
        void setPosition (int pX, int pY); ///set the position to help the setColor function fill the right cell
        int getPosition (char* axis);
        void setColor (int color); ///set the color of the cell
        int getColor (); ///returns the color of the cell
        void drawCell (int left, int up, int right, int bottom); ///draw the rectangle
        int changeCellSize (int newSize); ///change the size of the cell (not used yet)
        int getCellSize(){return dim;}
};

/**
    Defines the board.
*/

class GameBoard
{
    public:
        unsigned short int boardData[4][4];
        Cell cell[4][4];
        Coin coin;
        Player redL,blueL;
        void loadNewGame(GameBoard& board);
        void redMove (GameBoard& gameBoard);
        void drawBoard (GameBoard& gameBoard);
};

void startMultiplayerGame ();///starts the player vs player mode
