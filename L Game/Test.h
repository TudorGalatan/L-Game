/**
    This is the interface for the Test module.
    The module is responsible with testing the functionalities of the application.
**/

#pragma once

#include <assert.h>
#include "Domain_Game_Board.h"



class Test
{
    private:

        GameBoard gameBoard;

        /**
            Tests the "checkMove" function from the "Game Board" module.
            Input:
                - none
            Output:
                - the application runs normally, if the "checkMove" function works correctly
                - an assertion failure dialog box appears on the screen, otherwise
        **/
        void checkMove ();

        /**
            Tests the "goodCells" function from the "Game Board" module.
            Input:
                - none
            Output:
                - the application runs normally, if the "goodCells" function works correctly
                - an assertion failure dialog box appears on the screen, otherwise
        **/
        bool goodCells ();

        /**
            Tests the "getOrientation" function from the "Game Board" module.
            Input:
                - none
            Output:
                - the application runs normally, if the "getOrientation" function works correctly
                - an assertion failure dialog box appears on the screen, otherwise
        **/
        std::pair <unsigned short int, unsigned short int> getOrientation ();

        /**
            Tests the "hasGap" function from the "Game Board" module.
            Input:
                - none
            Output:
                - the application runs normally, if the "hasGap" function works correctly
                - an assertion failure dialog box appears on the screen, otherwise
        **/
        bool hasGap ();

        /**
            Tests the "getStartEndPositions" function from the "Game Board" module.
            Input:
                - none
            Output:
                - the application runs normally, if the "getStartEndPositions" function works correctly
                - an assertion failure dialog box appears on the screen, otherwise
        **/
        std::pair <unsigned short int, unsigned short int> getStartEndPositions ();

        /**
            Tests the "onValidPosition" function from the "Game Board" module.
            Input:
                - none
            Output:
                - the application runs normally, if the "onValidPosition" function works correctly
                - an assertion failure dialog box appears on the screen, otherwise
        **/
        bool onValidPosition ();

    public:

        /**
            Runs all the tests.
            Input:
                - none
            Output:
                - runs all the tests
        **/
        void runAll ();
};
