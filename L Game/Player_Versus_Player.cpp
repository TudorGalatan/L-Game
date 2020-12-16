/**
    This is the implementation for the Player versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#include "Player_Versus_Player.h"

#include <graphics.h>
#include <iostream>
#include <Windows.h>



/**
    Start the game in the player versus player game mode.
    Input:
        - none
    Output:
        - starts the game in the player versus player game mode
**/
void startMultiplayerGame ()
{
    Cell cell[4][4];
    bool player = false;    // False -> The Red Player; True -> The Blue Player

    // Clear the window.
    cleardevice();

    // Draw the game board.
    drawBoard(cell);

    // Temporary: just for testing
    delay(1000);

    while (true)
    {
        switch (player)
        {
            // The Red Player's Turn
            case false:
                redMove(cell);
                break;

            // The blue player's turn
            default:
            {
                // To add.
            }
        }

        // Change player.
        player = !player;
    }
}



/**
    Sets the colour of a cell.
    Input:
        - "color": the color of the cell
    Output:
        - sets the colour of the cell to its new, given value
**/
void Cell::setColor (int color)
{
    cellColor = color;
    setfillstyle(SOLID_FILL, color);
    floodfill(posX, posY, WHITE);
}



/**
    Draws a cell.
    Input:
        - "left": the left margin of the cell
        - "up": the upper margin of the cell
        - "right": the right margin of the cell
        - "bottom": the bottom margin of the cell
    Output:
        - draws the cell
**/
void Cell::drawCell (int left, int up, int right, int bottom)
{
    rectangle(left, up, right, bottom);
}



/**
    Updates the size of the cell.
    Input:
        - "newSize": the new size of the cell
    Output:
        - updates the cell size
**/
int Cell::changeCellSize (int newSize)
{
    newSize = newSize;
    return newSize;
}



/**
    ???
    Input:
        - "pX":
        - "pY":
    Output:
        -
**/
void Cell::setPosition (int pX, int pY)
{
    posX = pX;
    posY = pY;
}



/**
    Gets the colour of the cell.
    Input:
        - none
    Output:
        - the colour of the cell
**/
int Cell::getColor ()
{
    return cellColor;
}



/**
    Draws a coin.
    Input:
        - none
    Output:
        - draws the coin
**/
void Coin::drawCoin ()///we have to change this function to be more flexible-----> pls ask me wtf i meant by that
{                                                       /// WTF DID YOU MEAN???????
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;
    int posX = height / 4 + cellSize + cellSize / 2;
    int posY = height / 4 - cellSize + cellSize / 2;
    circle(posX, posY, getCoinSize());
    setfillstyle(SOLID_FILL, YELLOW);

    // Colour the cell.
    floodfill(posX, posY, WHITE);
}



/**
    Draws the game board.
    Input:
        - "cell": ???
    Output:
        - draws the game board
**/
void drawBoard (Cell cell[][4])
{
    Coin firstCoin, secondCoin;
    int xCoord = 0, yCoord = 0;
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;
    cellSize = cell[xCoord][yCoord].changeCellSize(cellSize);///change the value in the class

    for (int i = height / 4 + cellSize; i <= height / 4 + 4 * cellSize; i += cellSize)
    {
        for (int j = height / 4 - cellSize; j <= height / 4 + 2 * cellSize; j += cellSize)
        {
            cell[xCoord][yCoord].drawCell(i, j,i + cellSize, j + cellSize);///draw the cell
            cell[xCoord][yCoord].setPosition(i + cellSize / 2, j + cellSize / 2);
            cell[xCoord][yCoord].setColor(BLACK);///set the black color to the cells
            xCoord++;
        }
        xCoord = 0;
        yCoord++;
    }

    // Draw the coins.
    firstCoin.drawCoin();
        // Second coin?

    // Draw the red player.
    cell[1][0].setColor(RED);
    for (int i=0; i<3; i++)
        cell[2][i].setColor(RED);

    // Draw the blue player.
    cell[2][3].setColor(BLUE);
    for (int i=1; i<=3; i++)
        cell[1][i].setColor(BLUE);
}



/**
    ???
    Input:
        - "cell": ???
    Output:
        - ???
**/
void redMove (Cell cell[][4])
{
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        int playerColor = RED;
        for (unsigned short int line = 0; line < 4; line++)
            for (unsigned short int column = 0; column < 4; column++)
                if (cell[line][column].getColor() == RED)
                    cell[line][column].setColor(BLACK);
    }
}
