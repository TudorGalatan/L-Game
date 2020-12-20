/**
    This is the implementation for the Controller module.
    The module is responsible with coordinating the application.
**/

#include "Controller.h"
#include "Player_Versus_Player.h"

#include <fstream>
#include <iostream>



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



bool checkMove (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > coordinates)
{
    // If all 4 cells are identical to the previous move of the player, then it's not an allowed move.
    if (sameAsPrevious(gameBoard, currentPlayer, coordinates))
        return false;

    // If not all cells are empty, then it cannot be a valid move.
    if (emptyCells(gameBoard, coordinates) == false)
        return false;

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

    // We have an "L" form with empty cells only, so it is a valid move.
    return true;
}



bool sameAsPrevious (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > coordinates)
{
    unsigned short int sameCells = 0;

    for (unsigned short int cell = 0; cell < 4; cell++)
    {
        unsigned short int line = coordinates[cell].first;
        unsigned short int column = coordinates[cell].second;

        if (gameBoard[line][column] == currentPlayer)
            sameCells++;
    }

    // We have 4 cells identical to the previous move of the player.
    if (sameCells == 4)
        return true;

    // It is not the same move.
    return false;
}



bool emptyCells (USI gameBoard[][4], std::vector < std::pair <USI, USI> > coordinates)
{
    for (unsigned short int cell = 0; cell < 4; cell++)
    {
        unsigned short int line = coordinates[cell].first;
        unsigned short int column = coordinates[cell].second;

        // We have a non-empty cell.
        if (gameBoard[line][column] != 0)
            return false;
    }

    // We have empty cells only.
    return true;
}



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
