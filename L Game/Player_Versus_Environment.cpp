/**
    This is the implementation for the Player versus Environment game mode module.
    The module is responsible with the player versus environment game mode.
**/

#include "Player_Versus_Environment.h"



void PlayerVersusEnvironment::startGame ()
{
    /*
        false - the red player
        true - the blue player
    */
    bool player = false;

    // Clear the window.
    cleardevice();

    // Draw the game board.
    gameBoard.drawBoard();

    // Get the initial configuration of the game board.
    this->gameBoard.getInitialConfiguration();

    // Save the current configuration of the game board.
    this->gameBoard.saveCurrentConfiguration();

    // Load a new game.
    gameBoard.loadNewGame();

    // Temporary - just for testing
    delay(300);

    // Run the game.
    while (true)
        switch (player)
        {
            // The red player's turn
            case false:
                gameBoard.redPlayerMoves();
                player = true;
                break;
        }
}
