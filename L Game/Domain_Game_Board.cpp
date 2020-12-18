/**
    This is the implementation for the Game Board module from the Domain layer.
    The module is responsible with everything related to the game board.
**/

#include "Domain_Game_Board.h"



void GameBoard::drawBoard (GameBoard &board)
{
    int xCoord = 0, yCoord = 0;
    int width = getmaxx();
    int height = getmaxy();
    int cellSize = (height - 200) / 4;
    int position = width / 2 - (3 * cellSize) / 2;
    cellSize = board.cell[xCoord][yCoord].changeCellSize(cellSize); ///change the value in the class

    for (int i = width / 2 - 2 * cellSize; i <= width / 2 + cellSize; i += cellSize)
    {
        for (int j = height / 4 - cellSize; j <= height / 4 + 2 * cellSize; j += cellSize)
        {
            board.cell[xCoord][yCoord].drawCell(i, j,i + cellSize, j + cellSize);///draw the cell
            board.cell[xCoord][yCoord].setPosition(i + cellSize/2, j + cellSize/2);
            board.cell[xCoord][yCoord].setColor(BLACK);///set the black color to the cells
            xCoord++;
        }
        xCoord = 0;
        yCoord++;
    }
}



void GameBoard::loadNewGame (GameBoard &board)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            if (board.boardData[i][j] == 1)
                board.cell[i][j].setColor(RED);
            else if (board.boardData[i][j] == 2)
                board.cell[i][j].setColor(BLUE);
            else if (board.boardData[i][j] == 3)
                    board.coin.drawCoin(board.cell[i][j].getPosition("ox"),board.cell[i][j].getPosition("oy"));
        }
}



void GameBoard::redMove (GameBoard& gameBoard)
{
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (gameBoard.boardData[i][j] == 1)
                {
                    gameBoard.boardData[i][j] = 0; // deletes the positions occupied by his previous move
                    gameBoard.cell[i][j].setColor(BLACK); // sets the color of the occupied cell to BLACK to show that it's a free cell
                }
        while (1)
        {
            int playerColor = RED;
            POINT mousePos; // we'll save the cursor position in mousePos
            mousePos.x = mousex(); // get the OX coordonate
            mousePos.y = mousey(); // get the OY coordonate

        }
    }
}
