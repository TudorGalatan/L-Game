/**
    This file includes the implementation of the Controller layer.
    The Controller layer is responsible with controlling the application.
**/

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
    unsigned short int board[4][4];
    unsigned short int player = 1;    // 1 = the red player | 2 = the blue player
    readData(board);

    /* Temporary (Just Testing Right Now) */

    // Get Coordinates
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;
    getNewCoordinates(coordinates);

    // Check Move
    std::cout << checkMove(board, player, coordinates);
}



/**
    Reads the data from the file.
    Input:
        - "board": the game board
    Output:
        - none
    Observations:
        - 0: empty square
        - 1: the red player
        - 2: the blue player
        - 3: coin
**/
void readData (unsigned short int board[][4])
{
    std::ifstream inputFile("Input.in");
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
            inputFile >> board[line][column];
    inputFile.close();
}



/**
    Prints the game board on the screen.
    Input:
        - board: the game board
    Output:
        - none
**/
void printBoard (unsigned short int board[][4])
{
    for (unsigned short int line = 0; line < 4; line++)
    {
        for (unsigned short int column = 0; column < 4; column++)
            std::cout << board[line][column] << ' ';
        std::cout << '\n';
    }
}



/**
    Get the coordinates of the new "L" from the user.
    Input:
        - none
    Output:
        - "coordinates": the x and y coordinates of the new "L"
**/
void getNewCoordinates (std::vector < std::pair <unsigned short int, unsigned short int> >& coordinates)
{
    std::cout << "\nGive the coordinates of your new L:\n";

    for (unsigned short int index = 0; index < 4; index++)
    {
        unsigned short int x, y;
        std::cin >> x >> y;
        coordinates.push_back(std::make_pair(x, y));
    }
}



/**
    Checks whether the coordinates can represent a valid move on the board.
    It checks if it is an "L".
    Input:
        - "board": the game board
        - "currentPlayer": the current player
        - "coordinates": the coordinates
    Output:
        - true: if the coordinates represent a valid move on the board
        - false: otherwise
**/
bool checkMove (unsigned short int board[][4], unsigned short int currentPlayer, std::vector < std::pair <unsigned short int, unsigned short int> > coordinates)
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
        if (board[line][0] == currentPlayer && board[line][3] == currentPlayer)
            return false;

        // Find the starting position of the horizontal line.
        unsigned short int startPosition = 0;
        if (board[line][0] != currentPlayer)
            startPosition = 1;
        unsigned short int endPosition = startPosition + 2;

        bool squaresWithSameValue = 0;

        if (line - 1 >= 0 && board[line - 1][startPosition] == currentPlayer)
            squaresWithSameValue++;

        if (line + 1 <= 3 && board[line + 1][startPosition] == currentPlayer)
            squaresWithSameValue++;

        if (line - 1 >= 0 && board[line - 1][endPosition] == currentPlayer)
            squaresWithSameValue++;

        if (line - 1 >= 0 && board[line - 1][endPosition] == currentPlayer)
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
        if (board[0][column] == currentPlayer && board[3][column] == currentPlayer)
            return false;

        // Find the starting position of the vertical line.
        unsigned short int startPosition = 0;
        if (board[0][column] != currentPlayer)
            startPosition = 1;
        unsigned short int endPosition = startPosition + 2;

        bool squaresWithSameValue = 0;

        if (column - 1 >= 0 && board[startPosition][column - 1] == currentPlayer)
            squaresWithSameValue++;

        if (column + 1 <= 3 && board[startPosition][column + 1] == currentPlayer)
            squaresWithSameValue++;

        if (column - 1 >= 0 && board[endPosition][column - 1] == currentPlayer)
            squaresWithSameValue++;

        if (column - 1 >= 0 && board[endPosition][column + 1] == currentPlayer)
            squaresWithSameValue++;

        // If the other square is not in one of the valid positions, then
        // it cannot be an "L".
        if (squaresWithSameValue == 0)
            return false;
    }

    return true;
}



/**
    It performs the move of the current player, considering that all validations were already done.
    Input:
        - "board": the game board
        - "currentPlayer": the current player
        - "coordinates": the coordinates
    Output:
        - "board": the updated board
**/
void makeMove (unsigned short int board[][4], unsigned short int currentPlayer, std::vector < std::pair <unsigned short int, unsigned short int> > coordinates)
{
    // Delete the current squares of the current player.
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
            if (board[line][column] == currentPlayer)
                board[line][column] = 0;

    // Add the player on the new position.
    for (unsigned short int square = 0; square < 4; square++)
    {
        unsigned short int line = coordinates[square].first;
        unsigned short int column = coordinates[square].second;
        board[line][column] = currentPlayer;
    }
}
