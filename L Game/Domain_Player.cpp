/**
    This is the implementation for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#include "Domain_Player.h"



std::vector < std::pair <USI, USI> > Player::getCoordinates ()
{
    return this->coordinates;
}



USI Player::getLineCoordinateOfCell (USI cellNumber)
{
    return this->coordinates[cellNumber].first;
}



USI Player::getColumnCoordinateOfCell (USI cellNumber)
{
    return this->coordinates[cellNumber].second;
}



std::vector < std::pair <USI, USI> > Player::setCoordinates (std::vector < std::pair <USI, USI> > newCoordinates)
{
    this->coordinates = newCoordinates;
}



void Player::setCoordinatesOfCell (USI cellNumber, USI newLine, USI newColumn)
{
    this->coordinates[cellNumber].first = newLine;
    this->coordinates[cellNumber].second = newColumn;
}
