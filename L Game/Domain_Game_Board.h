/**
    This is the interface for the Game Board module from the Domain layer.
    The module is responsible with everything related to the game board.
**/

#pragma once

#include "Domain_Cell.h"
#include "Domain_Player.h"
#include "Domain_Coin.h"

#define USI unsigned short int



class GameBoard
{
    public:
        std::vector < std::pair <USI, USI> > prevCoordinates;
        // The back-end representation of the board
        unsigned short int boardData[4][4];

        // The red player (1) is the first.
        unsigned short int currentPlayer = 1;

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

        void bluePlayerMoves ();

        /**
            Checks whether the coordinates can represent a valid move on the game board.
            Input:
                - "gameBoard": the game board
                - "currentPlayer": the current player
                - "coordinates": the coordinates
            Output:
                - true: if the coordinates represent a valid move on the game board
                - false: otherwise
        **/
        bool checkMove (std::vector < std::pair <USI, USI> > coordinates, std::vector < std::pair <USI, USI> > prevCoordinates);

        /**
            It performs the current move of the current player, considering that all validations were already done.
            Input:
                - "gameBoard": the game board
                - "currentPlayer": the current player
                - "newCoordinates": the new coordinates of the current player
            Output:
                - "gameBoard": the updated game board
        **/
        void makeMove (std::vector < std::pair <USI, USI> > newCoordinates);

        /**
            Checks whether all the cells are good or not (black or the current player).
            Input:
                - "gameBoard": the game board
                - "coordinates": the coordinates of the squares
            Output:
                - true: if all the cells are good (black or the current player)
                - false: otherwise
        **/
        bool goodCells (std::vector < std::pair <USI, USI> > coordinates);

        /**
            Gets the orientation for the possible "L".
            Input:
                - "gameBoard": the game board
                - "coordinates": the coordinates of the squares
            Output:
                - "orientation": a pair containing:
                    - "orientation.first": the orientation for the possible "L"
                        - 0: if the orientation for the possible "L" is neither horizontal, nor vertical
                        - 1: if the orientation for the possible "L" is horizontal
                        - 2: if the orientation for the possible "L" is vertical
                    - "orientation.second": the number of the line or the column that constitutes the body of "L"
        **/
        std::pair <USI, USI> getOrientation (std::vector < std::pair <USI, USI> > coordinates);

        /**
            It checks if there is a gap between the three elements of the possible "L".
            Input:
                - "gameBoard": the game board
                - "orientation": the orientation for the possible "L"
                - "currentPlayer": the current player
            Output:
                - true: if there is a gap
                - false: otherwise
        **/
        bool hasGap (std::vector < std::pair <USI, USI> > coordinates);

        /**
            Gets the start and end positions for the body of the "L" form.
            Input:
                - "gameBoard": the game board
                - "orientation": the orientation of "L"
                - "currentPlayer": the current player
            Output:
                - "startEndPositions": a pair consisting of:
                    - "startEndPositions.first": the start position
                    - "startEndPositions.second": the end position
        **/
        std::pair <USI, USI> getStartEndPositions (std::vector < std::pair <USI, USI> > coordinates);

        /**
            Checks whether the other square from the possible "L" is on a valid position.
            Input:
                - "gameBoard": the game board
                - "orientation": the orientation of the possible "L"
                - "startEndPositions": the start and end positions for the body of the possible "L"
                - "currentPlayer": the current player
            Output:
                - true: if the other square is on a proper position
                - false: otherwise
        **/
        bool onValidPosition (std::vector < std::pair <USI, USI> > coordinates);

        void moveCoin();

        void drawButton(int color);

        bool checkWinner(unsigned short int aa[4][4],int color,int player,std::vector<std::pair<USI, USI> > &positions);
};
