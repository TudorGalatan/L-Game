/**
    This is the implementation for the Player versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#include "Player_Versus_Player.h"
#include "Controller.h"

#include <graphics.h>
#include <iostream>
#include <Windows.h>



void startPlayerVsPlayerGame ()
{
    GameBoard board;

    // false - the red player
    // true - the blue player
    bool player = false;

    // Clear the window.
    cleardevice();

    // Draw the game board.board.cell[0][0].getPosition("ox")
    board.drawBoard(board);
    readData(board.boardData, board);

    printBoard(board.boardData);
    board.loadNewGame(board);

    // Temporary: just for testing
    delay(300);

    while (true)
    {
        switch (player)
        {
            // The red player's turn
            case false:
                board.redMove(board);
                break;

            // The blue player's turn
            default:
            {
                // To add.
            }
        }

        // Change player.
        player = !player;
    }
}
