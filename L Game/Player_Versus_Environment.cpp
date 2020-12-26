/**
    This is the implementation for the Player versus Environment game mode module.
    The module is responsible with the player versus environment game mode.
**/

#include "Player_Versus_Environment.h"

#include <iostream>
#include <fstream>


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
                if(gameBoard.findMove(this->gameBoard.boardData,1,1,pos) == 0)
                {
                    cleardevice();
                    int xCoord = getmaxx()/2,yCoord=getmaxy()/2;
                    for(int i=10;i<=2000;i+=10)
                    {///aici o sa fie cv animatie de win
                        setcolor(WHITE);
                        outtextxy(xCoord-50,yCoord-10,"BLUE WINS");
                        setcolor(BLUE);
                        setlinestyle(SOLID_LINE,0,5);
                        circle(xCoord, yCoord, i);
                        setfillstyle(SOLID_FILL, BLUE);
                        floodfill(xCoord, yCoord, WHITE);
                    }
                }
                break;
            case true://BLUE
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
                        std::cout<<pos[i].first<<' '<<pos[i].second<<'\n';
                        this->gameBoard.boardData[pos[i].first][pos[i].second] = 2;
                        this->gameBoard.cell[pos[i].first][pos[i].second].setColor(BLUE);
                        this->gameBoard.blueL.positions[i].first = pos[i].first;
                        this->gameBoard.blueL.positions[i].second = pos[i].second;
                    }
                    std::cout<<"\nEND\n";
                    //std::cout<<pos.size();
                }
                else
                {
                    cleardevice();
                    int xCoord = getmaxx()/2,yCoord=getmaxy()/2;
                    for(int i=10;i<=2000;i+=5)
                    {///aici o sa fie cv animatie de win
                        outtextxy(xCoord-50,yCoord-10,"RED WINS");
                        //setcolor(RED);
                        setlinestyle(SOLID_LINE,0,5);
                        circle(xCoord-50, yCoord - 50, i);
                        setfillstyle(SOLID_FILL, RED);
                        floodfill(xCoord, yCoord, RED);
                    }
                }

        }
}
