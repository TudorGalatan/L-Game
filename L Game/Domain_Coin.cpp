/**
    This is the implementation for the Coin module from the Domain layer.
    The module is responsible with everything related to a coin.
**/

#include "Domain_Coin.h"


int Coin::getXIndex()
{
    return this->xIndex;
}


int Coin::getYIndex()
{
    return this->yIndex;
}


void Coin::setXIndex(int value)
{
    this->xIndex = value;
}


void Coin::setYIndex(int value)
{
    this->yIndex = value;
}


void Coin::deleteCoin(int xCoord,int yCoord)
{
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,5);
    circle(xCoord, yCoord, 100);
    setfillstyle(SOLID_FILL, BLACK);
    // Colour the cell.
    floodfill(xCoord, yCoord, BLACK);
}


void Coin::drawCoin (int xCoord, int yCoord)
{
    setcolor(WHITE);
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;
    setlinestyle(SOLID_LINE,0,5);
    circle(xCoord, yCoord, 100);
    setfillstyle(SOLID_FILL, YELLOW);
    // Colour the cell.
    floodfill(xCoord, yCoord, WHITE);
}


int Coin::getCoinSize ()
{
    return this->coinSize;
}
