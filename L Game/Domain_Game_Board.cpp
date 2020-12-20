/**
    This is the implementation for the Game Board module from the Domain layer.
    The module is responsible with everything related to the game board.
**/

#include "Domain_Game_Board.h"
#include "Domain_Cell.h"
#include "Domain_Player.h"
#include "Controller.h"

#include <fstream>
#include <iostream>
#include <vector>

void GameBoard::drawBoard (GameBoard &board)
{
    int xCoord = 0, yCoord = 0;

    // Get the size of the screen
    int width = getmaxx();
    int height = getmaxy();

    int cellSize = (height - 200) / 4;

    board.cell[xCoord][yCoord].changeCellSize(cellSize);

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
*/

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

            for(int i = 0; i < 4 && tst == false; i++)
            {
                for(int j = 0; j < 4 && tst == false; j++)
                    if(this->cell[i][j].isInside(xCoordinate,yCoordinate) && this->boardData[i][j] == 0)
                    {
                        this->boardData[i][j] = 1;
                        this->cell[i][j].setColor(RED);
                        ++clicks;
                        this->redL.updatePositions(clicks - 1,i,j);
                        g<<i<<' '<<j<<'\n';
                        tst = true;
                        break;
                    }
            }
            if(clicks == 4 && checkMove(this->boardData,1,this->redL.positions))///if the L is valid
            {
                return;
            }
            ///otherwise
            else if(clicks == 4 && !checkMove(this->boardData,1,this->redL.positions))
                clicks = 0;
            delay(202);
        }


    }

}
