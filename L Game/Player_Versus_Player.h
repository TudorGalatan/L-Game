/**
    This is the interface for the Player Versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#pragma once

#include "Domain_Game_Board.h"



class PlayerVersusPlayer
{
    private:

        GameBoard gameBoard;

    public:

        /**
            Starts the game in the player versus player game mode.
            Input:
                - none
            Output:
                - starts the game in the player versus player game mode
        **/
        void startGame ();
};
