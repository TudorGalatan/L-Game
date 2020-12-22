/**
    This is the implementation for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#include "Domain_Player.h"
#include <vector>



void Player::updateCoordinates (unsigned short int cellNumber, unsigned short int line, unsigned short int column)
{
    this->coordinates[cellNumber].first = line;
    this->coordinates[cellNumber].second = column;
}
