/**
    This is the implementation for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#include "Domain_Player.h"

#include <vector>
#include <fstream>

void Player::updatePositions(int cellNo,unsigned short int x,unsigned short int y)
{
    if(cellNo<=3)
    {
        std::ofstream g("test.txt");
        this->positions.at(cellNo).first = x;
        this->positions.at(cellNo).second = y;
    }
}
