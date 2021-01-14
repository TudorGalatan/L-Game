/**
    This is the interface for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#pragma once

#include <vector>


class Player
{
    public:

        std::vector < std::pair <unsigned short int, unsigned short int> > positions;

        void updatePositions (unsigned short int cellNumber, unsigned short int line, unsigned short int column);
};
