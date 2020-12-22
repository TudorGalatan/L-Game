/**
    This is the interface for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#pragma once

#include <vector>

#define USI unsigned short int



class Player
{
    public:

    // The coordinates of the cells that form the player on the game board
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;

    /**
        Updates the coordinates of a cell of the player.
        Input:
            - "cellNumber": the number of the cell
            - "line": the new line
            - "column": the new column
        Output:
            - updates the coordinates of a cell of the player
    **/
    void updateCoordinates (unsigned short int cellNumber, unsigned short int line, unsigned short int column);
};
