/**
    This is the implementation for the Controller layer.
    The Controller layer is responsible with coordinating the application.
**/

#include "Controller.h"
#include <fstream>
#include <iostream>


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
void readData (USI gameBoard[][4])
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
void printBoard (USI gameBoard[][4])
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
void getNewCoordinates (std::vector < std::pair <USI, USI> >& coordinates)
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
bool checkMove (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > coordinates)
{
    std::pair <USI, USI> orientation = getOrientation(gameBoard, coordinates);

    // If we have neither a horizontal, nor a vertical orientation, then it is not an "L".
    if (orientation.first == 0)
        return false;

    // If there is a gap between the three squares that should form an "L", then it cannot be an "L".
    if (hasGap(gameBoard, orientation, currentPlayer))
        return false;

    // Get the start and end positions for the body of the "L" form.
    std::pair <USI, USI> startEndPositions = getStartEndPositions(gameBoard, orientation, currentPlayer);

    // If the fourth square of the possible "L" is not on a valid position, then it cannot be an "L".
    if (onValidPosition(gameBoard, orientation, startEndPositions, currentPlayer) == 0)
        return false;

    // We have an "L" form, so it is a valid move.
    return true;
}



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
std::pair <USI, USI> getOrientation (USI gameBoard[][4], std::vector < std::pair <USI, USI> > coordinates)
{
    // The frequency of the lines and columns of the coordinates for the possible "L"
    unsigned short int frequencyOfLine[4] = { 0 };
    unsigned short int frequencyOfColumn[4] = { 0 };

    // Calculate how many times a line or a column appears in the coordinates.
    for (unsigned short int square = 0; square < 4; square++)
    {
        frequencyOfLine[coordinates[square].first]++;
        frequencyOfColumn[coordinates[square].second]++;
    }

    unsigned short int line = 4, column = 4;

    std::pair <USI, USI> orientation;

    // Firstly, we assume that we have neither a horizontal, nor a vertical orientation.
    orientation.first = 0;
    orientation.second = 0;

    // Check if there is a horizontal or a vertical orientation.
    for (unsigned short int square = 0; square < 4; square++)
    {
        // We have a horizontal orientation if there are 3 equal line coordinates.
        if (frequencyOfLine[square] == 3)
        {
            orientation.first = 1;
            orientation.second = square;
        }

        // We have a vertical orientation if there are 3 equal column coordinates.
        if (frequencyOfColumn[square] == 3)
        {
            orientation.first = 2;
            orientation.second = square;
        }
    }

    return orientation;
}



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
bool hasGap (USI gameBoard[][4], std::pair <USI, USI> orientation, USI currentPlayer)
{
        // We have a horizontal orientation.
        if (orientation.first == 1)
        {
            unsigned short int line = orientation.second;
            if (gameBoard[line][0] == currentPlayer && gameBoard[line][3] == currentPlayer)
                return true;
        }

        // We have a vertical orientation.
        unsigned short int column = orientation.second;
        if (gameBoard[0][column] == currentPlayer && gameBoard[3][column] == currentPlayer)
            return true;

        // We don't have a gap.
        return false;
}



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
std::pair <USI, USI> getStartEndPositions (USI gameBoard[][4], std::pair <USI, USI> orientation, USI currentPlayer)
{
    // We assume the start position is 0.
    unsigned short int startPosition = 0;

    // We have a horizontal orientation.
    if (orientation.first == 1)
    {
        unsigned short int line = orientation.second;
        if (gameBoard[line][0] != currentPlayer)
            startPosition = 1;
    }

    // We have a vertical orientation.
    else
    {
        unsigned short int column = orientation.second;
        if (gameBoard[0][column] != currentPlayer)
            startPosition = 1;
    }

    unsigned short int endPosition = startPosition + 2;

    std::pair <USI, USI> startEndPositions;
    startEndPositions.first = startPosition;
    startEndPositions.second = endPosition;

    return startEndPositions;
}



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
bool onValidPosition (USI gameBoard[][4], std::pair <USI, USI> orientation, std::pair <USI, USI> startEndPositions, USI currentPlayer)
{
    unsigned short int startPosition = startEndPositions.first;
    unsigned short int endPosition = startEndPositions.second;

    std::vector < std::pair <USI, USI> > possibleCoordinates;

    // We have a horizontal orientation.
    if (orientation.first == 1)
    {
        unsigned short int line = orientation.second;
        possibleCoordinates.push_back(std::make_pair(line - 1, startPosition));
        possibleCoordinates.push_back(std::make_pair(line + 1, startPosition));
        possibleCoordinates.push_back(std::make_pair(line - 1, endPosition));
        possibleCoordinates.push_back(std::make_pair(line + 1, endPosition));
    }

    // We have a vertical orientation.
    else
    {
        unsigned short int column = orientation.second;
        possibleCoordinates.push_back(std::make_pair(startPosition, column - 1));
        possibleCoordinates.push_back(std::make_pair(startPosition, column + 1));
        possibleCoordinates.push_back(std::make_pair(endPosition, column - 1));
        possibleCoordinates.push_back(std::make_pair(endPosition, column + 1));
    }


    for (unsigned short int possibleSquare = 0; possibleSquare < possibleCoordinates.size(); possibleSquare++)
    {
        unsigned short int line = possibleCoordinates.at(possibleSquare).first;
        unsigned short int column = possibleCoordinates.at(possibleSquare).second;

        if (gameBoard[line][column] == currentPlayer)
            return true;
    }

    // The other square is not on a valid position.
    return false;
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
void makeMove (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > newCoordinates)
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
