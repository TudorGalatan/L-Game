#include "Multiplayer.h"

#include <graphics.h>
#include <iostream>
#include <windows.h>

void startMultiplayerGame()
{
    cleardevice();
    drawBoard();
    while(true)
        continue;
}

void Cell::setColor(int color)///set the color of the cell
{
    setfillstyle(SOLID_FILL, color);///set the fill style
    floodfill(posX,posY,WHITE);///color the cell
}
void Cell::drawCell(int left,int up,int right,int bottom)
{
    rectangle(left,up,right,bottom);
}

int Cell::changeCellSize(int newSize)
{
    dim = newSize;
    return dim;
}
void Cell::setPosition(int pX,int pY)
{
    posX = pX;
    posY = pY;
}
void drawBoard()
{
    Cell cell[4][4];
    int xCoord = 0, yCoord = 0;
    int height = 1080;
    int cellSize = (height - 200) / 4;///calculate the size of a cell
    cellSize = cell[xCoord][yCoord].changeCellSize(cellSize);///change the value in the class
    for(int i = height / 4 + cellSize; i <= height / 4 + 4 * cellSize; i += cellSize)
    {
        for(int j = height / 4 - cellSize; j <= height / 4 + 2 * cellSize; j += cellSize)
        {
            cell[xCoord][yCoord].drawCell(i, j,i + cellSize, j + cellSize);///draw the cell
            cell[xCoord][yCoord].setPosition(i + cellSize / 2, j + cellSize / 2);
            cell[xCoord][yCoord].setColor(BLACK);///set the black color to the cells
            xCoord++;
        }
        xCoord = 0;
        yCoord++;
    }
    ///Draw the red L.
    cell[1][0].setColor(RED);
    for(int i=0;i<3;i++)
        cell[2][i].setColor(RED);
    ///Draw the blue L.
    cell[2][3].setColor(BLUE);
    for(int i=1;i<=3;i++)
        cell[1][i].setColor(BLUE);
}
