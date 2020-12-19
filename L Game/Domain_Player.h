/**
    This is the interface for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#pragma once

#include <graphics.h>

#define SIZE 4



class Player
{
    private:

        // The colour of the player:
        // 1 / BLUE - the blue player
        // 4 / RED - the red player
        unsigned short int color;

        // The shape of what ???
        unsigned short int shape;

        // The coordinates of the cells occupied by the player
        unsigned short int positions[SIZE][SIZE];   // why not a vector of pairs?

    public:

        /**
            Returns the number of the cell we have clicked on (1 - 16).
            Input:
                - none
            Output:
                - returns the number of the cell we have clicked on
        **/
        int clickPosition ();
};
