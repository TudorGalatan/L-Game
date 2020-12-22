/**
    This is the implementation for the Game Board module from the Domain layer.
    The module is responsible with everything related to the game board.
**/

#include "Domain_Game_Board.h"
#include "Domain_Cell.h"
#include "Domain_Player.h"

#include <fstream>
#include <iostream>
#include <vector>



void GameBoard::getInitialConfiguration ()
{
    std::ifstream inputFile("Input.in");

    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
        {
            unsigned short int cell;
            inputFile >> cell;
            this->boardData[line][column] = cell;
        }

    inputFile.close();
}



void GameBoard::saveCurrentConfiguration ()
{
    std::ofstream saveFile("Playground.txt");

    for (unsigned short int line = 0; line < 4; line++)
    {
        for (unsigned short int column = 0; column < 4; column++)
            saveFile << this->boardData[line][column] << ' ';
        saveFile << '\n';
    }
}



void GameBoard::drawBoard ()
{
    int xCoord = 0, yCoord = 0;

    // Get the size of the screen
    int width = getmaxx();
    int height = getmaxy();

    int cellSize = (height - 200) / 4;

    this->cell[xCoord][yCoord].changeCellSize(cellSize);

    // Draw every cell.
    for (int i = width / 2 - 2 * cellSize; i <= width / 2 + cellSize; i += cellSize)
    {
        for (int j = height / 4 - cellSize; j <= height / 4 + 2 * cellSize; j += cellSize)
        {
            this->cell[xCoord][yCoord].drawCell(i, j,i + cellSize, j + cellSize);///draw the cell
            this->cell[xCoord][yCoord].setPosition(i + cellSize / 2, j + cellSize / 2);///coordonates for the floodfill
            this->cell[xCoord][yCoord].setBounds(i,j);///saves the left and top in this object
            this->cell[xCoord][yCoord].setColor(BLACK);///set the black color to the cells
            xCoord++;
        }
        xCoord = 0;
        yCoord++;
    }
}



/**
    Loads the game with the values from boardData.txt
**/
void GameBoard::loadNewGame ()
{
    int start = 0;
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)

            // Colour the red player.
            if (this->boardData[line][column] == 1)
            {
                this->cell[line][column].setColor(RED);
                this->redL.positions.push_back(std::make_pair(line, column));
                ++start;
            }

    // Colour the blue player.
            else if (this->boardData[line][column] == 2)
                this->cell[line][column].setColor(BLUE);

    // Colour the coins.
            else if (this->boardData[line][column] == 3)
                this->coin.drawCoin(this->cell[line][column].getPosition("ox"), this->cell[line][column].getPosition("oy"));
}



/*bool GameBoard::checkLShape(Player player,int color)
{
    return 1;//checkMove(this->boardData,color,player.positions);
}*/



void GameBoard::redPlayerMoves ()
{
    std::ofstream g("test.txt");
    unsigned short int clicks = 0;///counts the clicks (you need 4 clicks to draw the letter 'L')
    bool tst = false;
    while(clicks < 4)
    {
        if(GetAsyncKeyState(VK_RBUTTON))///on right mouse click deletes the red 'L'
        {
            clicks = 0;
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(this->boardData[i][j] == 1)
                    {
                        this->boardData[i][j] = 0;
                        this->cell[i][j].setColor(BLACK);
                    }
        }
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(clicks == 0)
            {
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(this->boardData[i][j] == 1)
                        {
                            this->boardData[i][j] = 0;
                            this->cell[i][j].setColor(BLACK);
                        }
            }
            tst = false;
            HWND hwnd = GetForegroundWindow();
            POINT cursorPosition;

            // Get the mouse position.
            GetCursorPos(&cursorPosition);
            // Get the mouse position on the window.
            ScreenToClient(hwnd,&cursorPosition);

            double xCoordinate = cursorPosition.x;
            double yCoordinate = cursorPosition.y;

            for(int i = 0; i < 4 && clicks<=4; i++)
            {
                for(int j = 0; j < 4 && tst == false; j++)
                    if(this->cell[i][j].isInside(xCoordinate,yCoordinate) && this->boardData[i][j] == 0)
                    {
                        this->boardData[i][j] = 1;
                        this->cell[i][j].setColor(RED);
                        ++clicks;
                        this->redL.updatePositions(clicks - 1,i,j);

                        tst = true;
                        break;
                    }
            }
            if(clicks == 4 && this->checkMove(this->redL.positions))///if the L is valid
            {

                return;
            }
            else if(clicks == 4 && !this->checkMove(this->redL.positions))
            {
                for(int i = 0;i < 4; i++)
                    g<<this->redL.positions.at(i).first<<' '<<this->redL.positions.at(i).second<<'\n';
                clicks = 0;
            }
            ///otherwise
            delay(202);
        }
    }
}



bool GameBoard::checkMove (std::vector < std::pair <USI, USI> > coordinates)
{
    // All the cells must be free (black or the current player).
    if (this->goodCells(coordinates) == false)
        return false;

    // If all 4 cells are identical to the previous move of the player, then it's not an allowed move.
    //if (this->sameAsPrevious(coordinates))
    //    return false;

    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

    // If we have neither a horizontal, nor a vertical orientation, then it is not an "L".
    if (orientation.first == 0)
        return false;

    // If there is a gap between the three squares that should form an "L", then it cannot be an "L".
    if (this->hasGap(coordinates))
        return false;

    // Get the start and end positions for the body of the "L" form.
    std::pair <USI, USI> startEndPositions = this->getStartEndPositions(coordinates);

    // If the fourth square of the possible "L" is not on a valid position, then it cannot be an "L".
    if (this->onValidPosition(coordinates) == 0)
        return false;

    // We have an "L" form with empty cells only, so it is a valid move.
    return true;
}



void GameBoard::makeMove (std::vector < std::pair <USI, USI> > newCoordinates)
{
    // Delete the current squares of the current player.
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
            if (this->boardData[line][column] == this->currentPlayer)
                this->boardData[line][column] = 0;

    // Add the player on the new position.
    for (unsigned short int square = 0; square < 4; square++)
    {
        unsigned short int line = newCoordinates[square].first;
        unsigned short int column = newCoordinates[square].second;
        this->boardData[line][column] = this->currentPlayer;
    }
}



bool GameBoard::sameAsPrevious (std::vector < std::pair <USI, USI> > coordinates)
{
    unsigned short int sameCells = 0;

    for (unsigned short int cell = 0; cell < 4; cell++)
    {
        unsigned short int line = coordinates[cell].first;
        unsigned short int column = coordinates[cell].second;

        if (this->boardData[line][column] == this->currentPlayer)
            sameCells++;
    }

    // We have 4 cells identical to the previous move of the player.
    if (sameCells == 4)
        return true;

    // It is not the same move.
    return false;
}



bool GameBoard::goodCells (std::vector < std::pair <USI, USI> > coordinates)
{
    unsigned short int goodCells = 0;
    for (unsigned short int cell = 0; cell < 4; cell++)
    {
        unsigned short int line = coordinates.at(cell).first;
        unsigned short int column = coordinates.at(cell).second;

        if (this->boardData[line][column] == this->currentPlayer || this->boardData[line][column] == 0)
            goodCells++;
    }

    if (goodCells != 4)
        return false;

    return true;
}



std::pair <USI, USI> GameBoard::getOrientation (std::vector < std::pair <USI, USI> > coordinates)
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



bool GameBoard::hasGap (std::vector < std::pair <USI, USI> > coordinates)
{
    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

    // We have a horizontal orientation.
    if (orientation.first == 1)
    {
        unsigned short int line = orientation.second;
        if (this->boardData[line][0] == this->currentPlayer && this->boardData[line][3] == this->currentPlayer)
            return true;
    }

    // We have a vertical orientation.
    unsigned short int column = orientation.second;
    if (this->boardData[0][column] == this->currentPlayer && this->boardData[3][column] == this->currentPlayer)
        return true;

    // We don't have a gap.
    return false;
}



std::pair <USI, USI> GameBoard::getStartEndPositions (std::vector < std::pair <USI, USI> > coordinates)
{
    // We assume the start position is 0.
    unsigned short int startPosition = 0;

    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

    // We have a horizontal orientation.
    if (orientation.first == 1)
    {
        unsigned short int line = orientation.second;
        if (this->boardData[line][0] != this->currentPlayer)
            startPosition = 1;
    }

    // We have a vertical orientation.
    else
    {
        unsigned short int column = orientation.second;
        if (this->boardData[0][column] != this->currentPlayer)
            startPosition = 1;
    }

    unsigned short int endPosition = startPosition + 2;

    std::pair <USI, USI> startEndPositions;
    startEndPositions.first = startPosition;
    startEndPositions.second = endPosition;

    return startEndPositions;
}



bool GameBoard::onValidPosition (std::vector < std::pair <USI, USI> > coordinates)
{
    unsigned short int startPosition = this->getStartEndPositions(coordinates).first;
    unsigned short int endPosition = this->getStartEndPositions(coordinates).second;

    std::vector < std::pair <USI, USI> > possibleCoordinates;

    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

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

        if (this->boardData[line][column] == this->currentPlayer)
            return true;
    }

    // The other square is not on a valid position.
    return false;
}
