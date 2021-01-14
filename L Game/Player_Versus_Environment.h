/**
    This is the interface for the Player versus Environment game mode module.
    The module is responsible with the player versus environment game mode.
**/

#pragma once

#include "Domain_Game_Board.h"


class PlayerVersusEnvironment
{
    private:

        GameBoard gameBoard;

    public:

        /**
            Starts a new game in the player versus environment mode.
            Input:
                - none
            Output:
                - starts a new game in the player versus environment mode
        **/
        void startGame ();
};
