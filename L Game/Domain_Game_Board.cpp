/**
    This is the implementation for the Game Board module from the Domain layer.
    The module is responsible with everything related to the game board.
**/

#include "Domain_Game_Board.h"



void GameBoard::drawBoard (GameBoard &board)    /// EXplain please
{
    int xCoord = 0, yCoord = 0;
    int width = getmaxx();      /// What does this do?
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
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)

            // Colour the red player.
            if (board.boardData[line][column] == 1)
                board.cell[line][column].setColor(RED);

            // Colour the blue player.
            else if (board.boardData[line][column] == 2)
                board.cell[line][column].setColor(BLUE);

            // Colour the coins.
            else if (board.boardData[line][column] == 3)
            {
                /// This CARNATZ must be eaten piece by piece.
                board.coin.drawCoin(board.cell[line][column].getPosition("ox"), board.cell[line][column].getPosition("oy"));
            }
}



void GameBoard::redPlayerMoves (GameBoard& gameBoard)
{
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        for (unsigned short int line = 0; line < 4; line++)
            for (unsigned short int column = 0; column < 4; column++)
                if (gameBoard.boardData[line][column] == 1)
                {
                    // Delete the last occupied position.
                    gameBoard.boardData[line][column] = 0;

                    // Set the colour of the previously occupied cell to black to show that it's a free cell now.
                    gameBoard.cell[line][column].setColor(BLACK);
                }

        while (true)
        {
            int playerColor = RED;
            POINT mousePosition;
            mousePosition.x = mousex();     /// ??? What is the function doing?
            mousePosition.y = mousey();
        }
    }
}
