/**
    This is the implementation for the Player versus Environment game mode module.
    The module is responsible with the player versus environment game mode.
**/

#include "Player_Versus_Environment.h"
#include "Controller.h"



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

    // Read the initial configuration of the table.
    readData(gameBoard.boardData, gameBoard);

    // Save the current game board configuration.
    printBoard(gameBoard.boardData);

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
