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
            Gets the initial configuration of the game board from the input file.
            Input:
                - none
            Output:
                - gets the initial configuration of the game board from the input file
            Observations:
                - 0: empty square
                - 1: the red player
                - 2: the blue player
                - 3: coin
        **/
        void getInitialConfiguration ();

        /**
            Saves the current configuration of the game board in a text file.
            Input:
                - none
            Output:
                - saves the current configuration of the game board in a text file
        **/
        void saveCurrentConfiguration ();

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
