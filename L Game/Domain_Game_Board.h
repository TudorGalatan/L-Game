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

        // The back-end representation of the board
        unsigned short int boardData[4][4];

        // The front-end representation of the board
        Cell cell[4][4];

        // The coins
        Coin coin, firstCoin, secondCoin;

        // The players
        Player redL, blueL;

        /**
            Draws the game board.
            Input:
                - none
            Output:
                - draws the game board
        **/
        void drawBoard ();

        /**
            Load the game.
            Input:
                -
            Output:
                -
        **/
        void loadNewGame ();

        /**
            ???
            Input:
                - the board of the game
            Output:
                - nuj stai sa vedem
        **/
        void redPlayerMoves ();

        /**
            ???
        **/
        bool checkLShape (int color);
};
