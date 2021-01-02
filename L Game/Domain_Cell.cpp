/**
    This is the implementation for the Cell module from the Domain layer.
    The module is responsible with everything related to a cell from the game board.
**/

#include <graphics.h>

#include "Domain_Cell.h"


Cell::Cell ()
{
    this->dimension = 200;
    this->colour = BLACK;
}


unsigned short int Cell::getDimension ()
{
    return this->dimension;
}


void Cell::setDimension (unsigned short int newDimension)
{
    this->dimension = newDimension;
}


unsigned short int Cell::getColour ()
{
    return this->colour;
}


void Cell::setColour (unsigned short int newColour)
{
    this->colour = newColour;
    setfillstyle(SOLID_FILL, this->colour);
    floodfill(this->horizontalPosition, this->verticalPosition, WHITE);
}


unsigned short int Cell::getTopMargin ()
{
    return this->topMargin;
}


unsigned short int Cell::getLeftMargin ()
{
    return this->leftMargin;
}


void Cell::setTopLeftMargins (unsigned short int newTopMargin, unsigned short int newLeftMargin)
{
    this->topMargin = newTopMargin;
    this->leftMargin = newLeftMargin;
}


short int Cell::getPosition (char* axis)
{
    if (strcmp(axis, "ox") == 0)
        return this->horizontalPosition;

    else if (strcmp(axis, "oy") == 0)
        return this->verticalPosition;

    return -1;
}


void Cell::setPosition (unsigned short int newHorizontalPosition, unsigned short int newVerticalPosition)
{
    this->horizontalPosition = newHorizontalPosition;
    this->verticalPosition = newVerticalPosition;
}


bool Cell::isInside (double horizontalCoordinate, double verticalCoordinate)
{
    // The point is inside the cell.
    if (horizontalCoordinate >= this->leftMargin && horizontalCoordinate <= this->leftMargin + this->dimension &&
       verticalCoordinate >= this->topMargin && verticalCoordinate <= this->topMargin + this->dimension)
        return true;

    // The point is outside the cell.
    return false;
}


void Cell::drawCell (USI left, USI up, USI right, USI bottom)
{
    setlinestyle(SOLID_FILL, 0, 5);
    rectangle(left, up, right, bottom);
}
