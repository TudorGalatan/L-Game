/**
    This is the implementation for the Cell module from the Domain layer.
    The module is responsible with everything related to a cell from the game board.
**/

#include <graphics.h>
#include <fstream>
#include "Domain_Cell.h"



void Cell::drawCell (int left, int up, int right, int bottom)
{
    setlinestyle(SOLID_FILL,0,5);
    rectangle(left, up, right, bottom);
}



int Cell::getCellSize ()
{
    return this->dim;
}



int Cell::getColor ()
{
    return this->cellColor;
}



void Cell::setColor (int color)
{
    this->cellColor = color;
    setfillstyle(SOLID_FILL, color);
    floodfill(this->posX, this->posY, WHITE);
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
    this->posX = pX;
    this->posY = pY;
}



void Cell::changeCellSize (int newSize)
{
    this->dim = newSize;
}


void Cell::setBounds (int l, int t)
{
    this->left = l;
    this->top = t;
}

int Cell::getTopValue()
{
    return this->top;
}

int Cell::getLeftValue()
{
    return this->left;
}

bool Cell::isInside (double xCoord, double yCoord)
{
    std::ofstream g("test.txt");
    double top = this->getTopValue();
    double left = this->getLeftValue();
    int cellSize = 200; /// !!!!!!!!!!! function that returns the cell size has problems!!!---------------------------------------------------------------------------------------
    if(xCoord >= left && xCoord <= left + cellSize && yCoord >= top && yCoord <= top + cellSize)
        return true;
    return false;
}
