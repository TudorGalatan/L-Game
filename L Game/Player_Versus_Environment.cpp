/**
    This is the implementation for the Player versus Environment game mode module.
    The module is responsible with the player versus environment game mode.
**/

#include "Player_Versus_Environment.h"

#include <iostream>
#include <time.h>


void PlayerVersusEnvironment::startGame ()
{
    /*
        false - the red player
        true - the blue player
    */
    bool player = false;

    int gameMode = 2;
    std::vector < std::pair < USI, USI > > pos;

    cleardevice();

    this->gameBoard.getInitialConfiguration();
    this->gameBoard.saveCurrentConfiguration();
    this->gameBoard.drawBoard();
    this->gameBoard.loadNewGame();

    delay(300);

    // Run the game.
    while (true)
        switch (player)
        {
            // It's red player's turn.
            case false:
                gameBoard.currentPlayer = 1;
                gameBoard.redPlayerMoves();
                player = true;

                // The blue player won.
                if (this->gameBoard.findMove(this->gameBoard.boardData, 1, 1, pos) == false && player == false)
                {
                    for (unsigned short int line = 0; line < 4; line++)
                        for (unsigned short int column = 0; column < 4; column++)
                            if (this->gameBoard.boardData[line][column] == 1)
                            {
                                this->gameBoard.cell[line][column].setColour(LIGHTBLUE);
                                delay(500);
                            }

                    delay(1000);
                    cleardevice();

                    setfillstyle(SOLID_FILL,BLUE);
                    floodfill(10, 10, 1);
                    settextjustify(CENTER_TEXT, CENTER_TEXT);
                    outtextxy(getmaxx() / 2, getmaxy() / 2, "Blue player won.");
                }
                break;

            // It's blue player's turn.
            default:

                // Easy mode
                if (gameMode == 1)
                {
                    gameBoard.currentPlayer = 2;
                    player = false;
                    pos.clear();

                    if (gameBoard.findMove(this->gameBoard.boardData, 2, 2, pos) == 1)
                    {
                        for (unsigned short int line = 0; line < 4; line++)
                        {
                            for (unsigned short int column = 0; column < 4; column++)
                                if (this->gameBoard.boardData[line][column] == 2)
                                {
                                    this->gameBoard.cell[line][column].setColour(BLACK);
                                    this->gameBoard.boardData[line][column] = 0;
                                }
                            this->gameBoard.blueL.setCoordinatesOfCell(line, 10, 10);
                        }
                        for (int i = 0; i < pos.size(); i++)
                        {
                            this->gameBoard.boardData[pos[i].first][pos[i].second] = 2;
                            this->gameBoard.cell[pos[i].first][pos[i].second].setColour(BLUE);
                            this->gameBoard.blueL.setCoordinatesOfCell(i, pos[i].first, pos[i].second);
                        }
                    }

                    else
                    {
                        for (unsigned short int line = 0; line < 4; line++)
                            for (unsigned short int column = 0; column < 4; column++)
                                if (this->gameBoard.boardData[line][column]==1)
                                {
                                    this->gameBoard.cell[line][column].setColour(LIGHTRED);
                                    delay(500);
                                }

                        delay(1000);
                        cleardevice();

                        setfillstyle(SOLID_FILL, RED);
                        floodfill(10, 10, 1);
                        settextjustify(CENTER_TEXT, CENTER_TEXT);
                        outtextxy(getmaxx() / 2, getmaxy() / 2, "Red player won.");
                    }
                }

                // Hard mode
                else if (gameMode == 2)
                {
                    gameBoard.currentPlayer = 2;
                    player = false;
                    pos.clear();

                    if (gameBoard.findBestMove(this->gameBoard.boardData, 2, 2, pos) == 1)
                    {
                        for (unsigned short int line = 0; line < 4; line++)
                        {
                            for (unsigned short int column = 0; column < 4; column++)
                                if (this->gameBoard.boardData[line][column] == 2)
                                {
                                    this->gameBoard.cell[line][column].setColour(BLACK);
                                    this->gameBoard.boardData[line][column] = 0;
                                }
                            this->gameBoard.blueL.setCoordinatesOfCell(line, 10, 10);
                        }
                        for (int i = 0; i < pos.size(); i++)
                        {
                            this->gameBoard.boardData[pos[i].first][pos[i].second] = 2;
                            this->gameBoard.cell[pos[i].first][pos[i].second].setColour(BLUE);
                            this->gameBoard.blueL.setCoordinatesOfCell(i, pos[i].first, pos[i].second);
                        }
                    }
                    else
                    {
                        for (unsigned short int line = 0; line < 4; line++)
                            for (unsigned short int column = 0; column < 4; column++)
                                if (this->gameBoard.boardData[line][column] == 1)
                                {
                                    this->gameBoard.cell[line][column].setColour(LIGHTRED);
                                    delay(500);
                                }

                        delay(50000);
                        cleardevice();

                        setfillstyle(SOLID_FILL, RED);
                        floodfill(10, 10, 1);
                        settextjustify(CENTER_TEXT, CENTER_TEXT);
                        outtextxy(getmaxx() / 2, getmaxy() / 2, "Red player won.");
                    }
                }
        }
}
