/**
    This is the implementation for the Coin module from the Domain layer.
    The module is responsible with everything related to a coin.
**/

#include "Domain_Coin.h"



void Coin::drawCoin (int xCoord, int yCoord)
{
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;
    circle(xCoord, yCoord, getCoinSize());
    setfillstyle(SOLID_FILL, YELLOW);

    // Colour the cell.
    floodfill(xCoord, yCoord, WHITE);
}



int Coin::getCoinSize ()
{
    return this->coinSize;
}
