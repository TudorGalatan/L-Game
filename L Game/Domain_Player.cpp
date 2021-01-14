/**
    This is the implementation for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#include "Domain_Player.h"

#include <vector>
#include <fstream>


void Player::updatePositions (unsigned short int cellNumber, unsigned short int line, unsigned short int column)
{
    if (cellNumber < 4)
    {
        this->positions[cellNumber].first = line;
        this->positions[cellNumber].second = column;
    }
}
