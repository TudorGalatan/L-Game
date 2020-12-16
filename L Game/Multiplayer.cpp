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

void Cell::setColor(int xCoord,int yCoord, int color)///set the color of the cell
{
    setfillstyle(SOLID_FILL, color);///set the fill style
    floodfill(xCoord,yCoord,WHITE);///color the cell
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

void drawBoard()
{
    Cell cell;
    int len = GetSystemMetrics(SM_CXSCREEN);
    int wid = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (wid - 200) / 4;///calculate the size of a cell
    cellSize = cell.changeCellSize(cellSize);///change the value in the class
    for(int i = wid / 4 + cellSize; i <= wid / 4 + 4 * cellSize; i += cellSize)
        for(int j = wid / 4 - cellSize; j <= wid / 4 + 2 * cellSize; j += cellSize)
        {
            cell.drawCell(i, j,i + cellSize, j + cellSize);///draw the cell
            cell.setColor(i + cellSize / 2, j + cellSize / 2, rand() % 10 + 1);///E CV MIC GRESIT AICI LA COLORAT
        }
}
