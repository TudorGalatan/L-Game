/**
    This is the implementation for the Controller layer.
    The Controller layer is responsible with coordinating the application.
**/

#include <fstream>
#include <iostream>
#include <vector>

#include "Controller.h"



/**
    Here are the main instructions of the application.
    Input:
        - none
    Output:
        - none
**/
void runApplication ()
{
    // Read the data from the input file.
    unsigned short int gameBoard[4][4];
    unsigned short int player = 1;    // 1 = the red player | 2 = the blue player
    readData(gameBoard);

    /* Temporary (Just Testing Right Now) */

    // Get Coordinates
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;
    getNewCoordinates(coordinates);

    // Check Move
    std::cout << checkMove(gameBoard, player, coordinates);
}



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
void readData (unsigned short int gameBoard[][4])
{
    std::ifstream inputFile("Input.in");
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
            inputFile >> gameBoard[line][column];
    inputFile.close();
}



/**
    Prints the game board on the screen.
    Input:
        - "gameBoard": the game board
    Output:
        - none
**/
void printBoard (unsigned short int gameBoard[][4])
{
    for (unsigned short int line = 0; line < 4; line++)
    {
        for (unsigned short int column = 0; column < 4; column++)
            std::cout << gameBoard[line][column] << ' ';
        std::cout << '\n';
    }
}



/**
    Get the coordinates of the new "L" from the user.
    Input:
        - none
    Output:
        - "coordinates": the line and column coordinates of the new "L"
**/
void getNewCoordinates (std::vector < std::pair <unsigned short int, unsigned short int> >& coordinates)
{
    std::cout << "\nGive the coordinates of your new L:\n";

    for (unsigned short int square = 0; square < 4; square++)
    {
        unsigned short int line, column;
        std::cin >> line >> column;
        coordinates.push_back(std::make_pair(line, column));
    }
}



/**
    Checks whether the coordinates can represent a valid move on the game board. So it checks if it is an "L".
    Input:
        - "gameBoard": the game board
        - "currentPlayer": the current player
        - "coordinates": the coordinates
    Output:
        - true: if the coordinates represent a valid move on the game board
        - false: otherwise
**/
bool checkMove (unsigned short int gameBoard[][4], unsigned short int currentPlayer, std::vector < std::pair <unsigned short int, unsigned short int> > coordinates)
{
    bool horizontalOrientation = false, verticalOrientation = false;

    // The frequency of X and Y indexes.
    unsigned short int frequencyOfX[4] = {0};
    unsigned short int frequencyOfY[4] = {0};

    // Calculate how many times X and Y repeats.
    for (unsigned short int index = 0; index < 4; index++)
    {
        frequencyOfX[coordinates[index].first]++;
        frequencyOfY[coordinates[index].second]++;
    }

    unsigned short int line = 4, column = 4;

    // Check if any orientation (horizontal or vertical) applies.
    for (unsigned short int index = 0; index < 4; index++)
    {
        // We have a horizontal orientation for "L" if there
        // are 3 equal coordinates for x.
        if (frequencyOfX[index] == 3)
        {
            horizontalOrientation = true;
            line = index;
        }

        // We have a vertical orientation for "L" if there
        // are 3 equal coordinates for y.
        if (frequencyOfY[index] == 3)
        {
            verticalOrientation = true;
            column = index;
        }
    }

    // If we have no orientation, then it is not an "L".
    if (horizontalOrientation == false && verticalOrientation == false)
        return false;

    // If we have a horizontal orientation for "L".
    if (horizontalOrientation)
    {
        // If the first element on the line and the last element on the line are
        // reresented by the same player, then we have a gap in the middle and
        // it cannot be an "L".
        if (gameBoard[line][0] == currentPlayer && gameBoard[line][3] == currentPlayer)
            return false;

        // Find the starting position of the horizontal line.
        unsigned short int startPosition = 0;
        if (gameBoard[line][0] != currentPlayer)
            startPosition = 1;
        unsigned short int endPosition = startPosition + 2;

        bool squaresWithSameValue = 0;

        if (line - 1 >= 0 && gameBoard[line - 1][startPosition] == currentPlayer)
            squaresWithSameValue++;

        if (line + 1 <= 3 && gameBoard[line + 1][startPosition] == currentPlayer)
            squaresWithSameValue++;

        if (line - 1 >= 0 && gameBoard[line - 1][endPosition] == currentPlayer)
            squaresWithSameValue++;

        if (line - 1 >= 0 && gameBoard[line - 1][endPosition] == currentPlayer)
            squaresWithSameValue++;

        // If the other square is not in one of the valid positions, then
        // it cannot be an "L".
        if (squaresWithSameValue == 0)
            return false;
    }

    // If we have a vertical orientation for "L".
    if (verticalOrientation)
    {
        // If the first element on the column and the last element on the column are
        // reresented by the same player, then we have a gap in the middle and
        // it cannot be an "L".
        if (gameBoard[0][column] == currentPlayer && gameBoard[3][column] == currentPlayer)
            return false;

        // Find the starting position of the vertical line.
        unsigned short int startPosition = 0;
        if (gameBoard[0][column] != currentPlayer)
            startPosition = 1;
        unsigned short int endPosition = startPosition + 2;

        bool squaresWithSameValue = 0;

        if (column - 1 >= 0 && gameBoard[startPosition][column - 1] == currentPlayer)
            squaresWithSameValue++;

        if (column + 1 <= 3 && gameBoard[startPosition][column + 1] == currentPlayer)
            squaresWithSameValue++;

        if (column - 1 >= 0 && gameBoard[endPosition][column - 1] == currentPlayer)
            squaresWithSameValue++;

        if (column - 1 >= 0 && gameBoard[endPosition][column + 1] == currentPlayer)
            squaresWithSameValue++;

        // If the other square is not in one of the valid positions, then
        // it cannot be an "L".
        if (squaresWithSameValue == 0)
            return false;
    }

    return true;
}



/**
    It performs the current move of the current player, considering that all validations were already done.
    Input:
        - "gameBoard": the game board
        - "currentPlayer": the current player
        - "newCoordinates": the new coordinates of the current player
    Output:
        - "gameBoard": the updated game board
**/
void makeMove (unsigned short int gameBoard[][4], unsigned short int currentPlayer, std::vector < std::pair <unsigned short int, unsigned short int> > newCoordinates)
{
    // Delete the current squares of the current player.
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
            if (gameBoard[line][column] == currentPlayer)
                gameBoard[line][column] = 0;

    // Add the player on the new position.
    for (unsigned short int square = 0; square < 4; square++)
    {
        unsigned short int line = newCoordinates[square].first;
        unsigned short int column = newCoordinates[square].second;
        gameBoard[line][column] = currentPlayer;
    }
}
