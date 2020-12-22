/**
    This is the implementation for the Player versus Environment game mode module.
    The module is responsible with the player versus environment game mode.
**/

#include "Player_Versus_Environment.h"



void PlayerVersusEnvironment::startGame ()
{
    cleardevice();

    this->gameBoard.getInitialConfiguration();
    this->gameBoard.saveCurrentConfiguration();
    this->gameBoard.drawBoard();
    this->gameBoard.loadNewGame();

    delay(300);

    /*
        false - the red player
        true - the blue player
    */
    bool player = false;

    // Run the game.
    while (true)
        switch (player)
        {
            // The red player's turn
            case false:
                gameBoard.redPlayerMoves();
                player = true;
                break;

            // The blue player's turn
            default:
                while (true)
                    delay(1);
                player = false;
        }
}
