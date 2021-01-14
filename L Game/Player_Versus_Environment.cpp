/**
    This is the implementation for the Player versus Environment game mode module.
    The module is responsible with the player versus environment game mode.
**/

#include "Player_Versus_Environment.h"

#include <iostream>
#include <fstream>
#include <time.h>


void PlayerVersusEnvironment::startGame ()
{
    std::ofstream g("test.txt");

    std::vector < std::pair < USI, USI > >pos;
    /*
        false - the red player
        true - the blue player
    */
    bool player = false;

    // Clear the window.
    cleardevice();

    // Draw the game board.
    gameBoard.drawBoard();

    // Get the initial configuration of the game board.
    this->gameBoard.getInitialConfiguration();

    // Save the current configuration of the game board.
    this->gameBoard.saveCurrentConfiguration();

    // Load a new game.
    gameBoard.loadNewGame();

    // Temporary - just for testing
    delay(300);

    // Run the game.
    while (true)
        switch (player)
        {
            // The red player's turn
            case false://RED
                gameBoard.currentPlayer = 1;
                gameBoard.redPlayerMoves();
                player = true;
                if(this->gameBoard.findMove(this->gameBoard.boardData,1,1,pos)== false && player == false)
                {
                    for(int i=0;i<4;i++)
                        for(int j=0;j<4;j++)
                            if(this->gameBoard.boardData[i][j]==1)
                            {
                                this->gameBoard.cell[i][j].setColor(LIGHTBLUE);
                                delay(500);
                            }
                    delay(1000);
                    cleardevice();
                    setfillstyle(SOLID_FILL,BLUE);
                    floodfill(10,10,1);
                    settextjustify(CENTER_TEXT,CENTER_TEXT);
                    outtextxy(getmaxx()/2,getmaxy()/2,"BLUE PLAYER WINS");
                }
                break;
            case true://BLUE
                if(this->gameMode == 1)///easy
                {
                    gameBoard.currentPlayer = 2;
                    player = false;
                    pos.clear();
                    if(gameBoard.findMove(this->gameBoard.boardData,2,2,pos) == 1)
                    {
                        for(int z=0;z<4;z++)
                        {
                            for(int z2=0;z2<4;z2++)
                                if(this->gameBoard.boardData[z][z2] == 2)
                                {
                                    this->gameBoard.cell[z][z2].setColor(BLACK);
                                    this->gameBoard.boardData[z][z2] = 0;
                                }
                            this->gameBoard.blueL.positions[z].first = 10;
                            this->gameBoard.blueL.positions[z].second = 10;
                        }
                        for(int i=0;i<pos.size();i++)
                        {
                            this->gameBoard.boardData[pos[i].first][pos[i].second] = 2;
                            this->gameBoard.cell[pos[i].first][pos[i].second].setColor(BLUE);
                            this->gameBoard.blueL.positions[i].first = pos[i].first;
                            this->gameBoard.blueL.positions[i].second = pos[i].second;
                        }

                    }
                    else
                    {
                        for(int i=0;i<4;i++)
                            for(int j=0;j<4;j++)
                                if(this->gameBoard.boardData[i][j]==1)
                                {
                                    this->gameBoard.cell[i][j].setColor(LIGHTRED);
                                    delay(500);
                                }
                        delay(1000);
                        cleardevice();
                        setfillstyle(SOLID_FILL,RED);
                        floodfill(10,10,1);
                        settextjustify(CENTER_TEXT,CENTER_TEXT);
                        outtextxy(getmaxx()/2,getmaxy()/2,"RED PLAYER WINS");
                    }
                }
                else if (this->gameMode == 2)///hard
                {
                    gameBoard.currentPlayer = 2;
                    player = false;
                    pos.clear();
                    if(gameBoard.findBestMove(this->gameBoard.boardData,2,2,pos) == 1)
                    {
                        for(int z=0;z<4;z++)
                        {
                            for(int z2=0;z2<4;z2++)
                                if(this->gameBoard.boardData[z][z2] == 2)
                                {
                                    this->gameBoard.cell[z][z2].setColor(BLACK);
                                    this->gameBoard.boardData[z][z2] = 0;
                                }
                            this->gameBoard.blueL.positions[z].first = 10;
                            this->gameBoard.blueL.positions[z].second = 10;
                        }
                        for(int i=0;i<pos.size();i++)
                        {
                            this->gameBoard.boardData[pos[i].first][pos[i].second] = 2;
                            this->gameBoard.cell[pos[i].first][pos[i].second].setColor(BLUE);
                            this->gameBoard.blueL.positions[i].first = pos[i].first;
                            this->gameBoard.blueL.positions[i].second = pos[i].second;
                        }

                    }
                    else
                    {
                        for(int i=0;i<4;i++)
                            for(int j=0;j<4;j++)
                                if(this->gameBoard.boardData[i][j]==1)
                                {
                                    this->gameBoard.cell[i][j].setColor(LIGHTRED);
                                    delay(500);
                                }
                        delay(50000);
                        cleardevice();
                        setfillstyle(SOLID_FILL,RED);
                        floodfill(10,10,1);
                        settextjustify(CENTER_TEXT,CENTER_TEXT);
                        outtextxy(getmaxx()/2,getmaxy()/2,"RED PLAYER WINS");
                    }
                }
        }
}
