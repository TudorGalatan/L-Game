/**
    This is the interface for the Game Board module from the Domain layer.
    The module is responsible with everything related to the game board.
**/

#pragma once

#include "Domain_Cell.h"
#include "Domain_Player.h"
#include "Domain_Coin.h"



class GameBoard
{
    public:

        // ???
        unsigned short int boardData[4][4];

        // ???
        Cell cell[4][4];

        // Just one coin?
        Coin coin;

        // The players
        Player redL, blueL;

        /**
            Draws the game board.
            Input:
                - none
            Output:
                - draws the game board
        **/
        void drawBoard (GameBoard& gameBoard);

        /**
            Load new game.
            Input:
                -
            Output:
                -
        **/
        void loadNewGame (GameBoard& board);    // Why the parameter?

        /**
            ???
            Input:
                - the board of the game
            Output:
                - nuj stai sa vedem
        **/
        void redPlayerMoves (GameBoard& gameBoard);
};
