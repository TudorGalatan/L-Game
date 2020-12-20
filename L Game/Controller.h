/**
    This is the interface for the Controller module.
    The module is responsible with coordinating the application.
**/

#pragma once

#include "Player_Versus_Player.h"
#include <vector>

#define USI unsigned short int



/**
    Reads the data from the input file.
    Input:
        - "gameBoard": the game board
    Output:
        - none
    Observations:
        - 0: empty square
        - 1: the red player
        - 2: the blue player
        - 3: coin
**/
void readData (USI gameBoard[][4], GameBoard& board);



/**
    Prints the game board on the screen.
    Input:
        - "gameBoard": the game board
    Output:
        - none
**/
void printBoard (USI gameBoard[][4]);



/**
    Get the coordinates of the new "L" from the user.
    Input:
        - none
    Output:
        - "coordinates": the line and column coordinates of the new "L"
**/
void getNewCoordinates (std::vector < std::pair <USI, USI> >& coordinates);



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
bool checkMove (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > coordinates);



/**
    Checks whether all the cells are empty or not.
    Input:
        - "gameBoard": the game board
        - "coordinates": the coordinates of the squares
    Output:
        - true: if all the cells are empty
        - false: otherwise
**/
bool emptyCells (USI gameBoard[][4], std::vector < std::pair <USI, USI> > coordinates);



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
std::pair <USI, USI> getOrientation (USI gameBoard[][4], std::vector < std::pair <USI, USI> > coordinates);



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
bool hasGap (USI gameBoard[][4], std::pair <USI, USI> orientation, USI currentPlayer);



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
std::pair <USI, USI> getStartEndPositions (USI gameBoard[][4], std::pair <USI, USI> orientation, USI currentPlayer);



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
bool onValidPosition (USI gameBoard[][4], std::pair <USI, USI> orientation, std::pair <USI, USI> startEndPositions, USI currentPlayer);



/**
    It performs the current move of the current player, considering that all validations were already done.
    Input:
        - "gameBoard": the game board
        - "currentPlayer": the current player
        - "newCoordinates": the new coordinates of the current player
    Output:
        - "gameBoard": the updated game board
**/
void makeMove (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > newCoordinates);
