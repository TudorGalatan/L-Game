/**
    This is the implementation for the Cell module from the Domain layer.
    The module is responsible with everything related to a cell from the game board.
**/

#include <graphics.h>
#include "Domain_Cell.h"



void Cell::drawCell (int left, int up, int right, int bottom)
{
    rectangle(left, up, right, bottom);
}



int Cell::getCellSize ()
{
    return dim;
}



int Cell::getColor ()
{
    return cellColor;
}



void Cell::setColor (int color)
{
    cellColor = color;
    setfillstyle(SOLID_FILL, color);
    floodfill(posX, posY, WHITE);
}



int Cell::getPosition (char* axis)
{
    if (strcmp(axis, "ox") == 0)
        return posX;

    else if (strcmp(axis, "oy") == 0)
        return posY;

    return -1;
}



void Cell::setPosition (int pX, int pY)
{
    posX = pX;
    posY = pY;
}



void Cell::changeCellSize (int newSize)
{
    this->dim = newSize;
}
