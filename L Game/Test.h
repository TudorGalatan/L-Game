/**
    This is the interface for the Test module.
    The module is responsible with testing the functionalities of the application.
**/

#pragma once

#include <assert.h>
#include "Domain_Game_Board.h"



class Test
{
    public:

        // A game board
        GameBoard gameBoard;

        /**
            Runs all the tests.
            Input:
                - none
            Output:
                - runs all the tests
        **/
        void runAll ();

        /**
            Tests the "checkMove" function from the "Game Board" module.
            Input:
                - none
            Output:
                - nothing happens, if the "checkMove" function works correctly
                - assertion fail, otherwise
        **/
        void checkMove ();

        /**
            Tests the "goodCells" function from the "Game Board" module.
            Input:
                - none
            Output:
                - nothing happens, if the "goodCells" function works correctly
                - assertion fail, otherwise
        **/
        bool goodCells ();

        /**
            Tests the "getOrientation" function from the "Game Board" module.
            Input:
                - none
            Output:
                - nothing happens, if the "getOrientation" function works correctly
                - assertion fail, otherwise
        **/
        std::pair <USI, USI> getOrientation ();

        /**
            Tests the "hasGap" function from the "Game Board" module.
            Input:
                - none
            Output:
                - nothing happens, if the "hasGap" function works correctly
                - assertion fail, otherwise
        **/
        bool hasGap ();

        /**
            Tests the "getStartEndPositions" function from the "Game Board" module.
            Input:
                - none
            Output:
                - nothing happens, if the "getStartEndPositions" function works correctly
                - assertion fail, otherwise
        **/
        std::pair <USI, USI> getStartEndPositions ();

        /**
            Tests the "onValidPosition" function from the "Game Board" module.
            Input:
                - none
            Output:
                - nothing happens, if the "onValidPosition" function works correctly
                - assertion fail, otherwise
        **/
        bool onValidPosition ();
};
