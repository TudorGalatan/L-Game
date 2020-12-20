/**
    This is the implementation for the Player Versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#include "Player_Versus_Player.h"
#include "Controller.h"



void startPlayerVsPlayerGame ()
{
    GameBoard gameBoard;

    // false - the red player
    // true - the blue player
    bool player = false;

    // Clear the window.
    cleardevice();

    // Draw the game board.board.cell[0][0].getPosition("ox")   ???
    gameBoard.drawBoard();
    readData(gameBoard.boardData, gameBoard);

    printBoard(gameBoard.boardData);
    gameBoard.loadNewGame();

    // Temporary: just for testing
    delay(300);

    while (true)
    {
        switch (player)
        {
            // The red player's turn
            case false:
                gameBoard.redPlayerMoves();
                player = true;
                break;

            // The blue player's turn
            default:
                // To add.
                while(1)
                    delay(1);
                break;
        }
    }
}
