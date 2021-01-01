/**
    This is the interface for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#pragma once

#include <vector>

#define USI unsigned short int



class Player
{
    private:

        std::vector < std::pair <USI, USI> > coordinates;

    public:

        /**
            Gets the coordinates of the player.
            Input:
                - none
            Output:
                - the coordinates of the player
        **/
        std::vector < std::pair <USI, USI> > getCoordinates ();

        /**
            Gets the line coordinate of a given cell.
            Input:
                - "cellNumber": the number of the cell
            Output:
                - the line coordinate of the given cell
        **/
        USI getLineCoordinateOfCell (USI cellNumber);

        /**
            Gets the column coordinate of a given cell.
            Input:
                - "cellNumber": the number of the cell
            Output:
                - the column coordinate of the given cell
        **/
        USI getColumnCoordinateOfCell (USI cellNumber);

        /**
            Sets the coordinates of the player.
            Input:
                - "newCoordinates": the new coordinates of the player
            Output:
                - the coordinates of the player are set
        **/
        std::vector < std::pair <USI, USI> > setCoordinates (std::vector < std::pair <USI, USI> > newCoordinates);

        /**
            Updates the coordinates of a specified cell.
            Input:
                - "cellNumber": the number of the cell
                - "newLine": the new line coordinate of the cell
                - "newColumn": the new column coordinate of the cell
            Output:
                - the coordinates of the specified cell are updated
        **/
        void setCoordinatesOfCell (USI cellNumber, USI newLine, USI newColumn);
};
