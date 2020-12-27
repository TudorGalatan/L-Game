/**
    This is the implementation for the Player Versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#include "Player_Versus_Player.h"

#include <fstream>

void PlayerVersusPlayer::startGame ()
{
    std::ofstream g("test.in");
    std::vector<std::pair<USI, USI> > positions;
    // false - the red player
    // true - the blue player
    bool player = false;

    // Clear the window.
    cleardevice();

    // Draw the game board.board.cell[0][0].getPosition("ox")   ???
    this->gameBoard.drawBoard();

    // Get the initial configuration of the game board.
    this->gameBoard.getInitialConfiguration();

    // Save the current configuration of the game board.
    this->gameBoard.saveCurrentConfiguration();

    this->gameBoard.loadNewGame();

    // Temporary: just for testing
    delay(300);

    while (true)
    {
        switch (player)
        {
        // The red player's turn
        case false:
            this->gameBoard.currentPlayer=1;
            this->gameBoard.redPlayerMoves();
            player = true;
            break;

        // The blue player's turn
        default:
            this->gameBoard.currentPlayer=2;
            this->gameBoard.bluePlayerMoves();
            player = false;
            break;
        }
        this->gameBoard.saveCurrentConfiguration();
        if(this->gameBoard.findMove(this->gameBoard.boardData,1,1,positions)== false && player == false)
        {
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    if(this->gameBoard.boardData[i][j]==2)
                    {
                        this->gameBoard.cell[i][j].setColor(LIGHTBLUE);
                        delay(500);
                    }
            delay(1000);
            cleardevice();
            setfillstyle(SOLID_FILL,BLUE);
            floodfill(10,10,1);
            outtextxy(getmaxx()/2-100,getmaxy()/2,"BLUE PLAYER WINS");
        }
        else if(this->gameBoard.findMove(this->gameBoard.boardData,2,2,positions)==false && player == true)
        {
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    if(this->gameBoard.boardData[i][j]==1)
                    {
                        this->gameBoard.cell[i][j].setColor(LIGHTRED);
                        delay(500);
                    }
            delay(1000);
            cleardevice();
            setfillstyle(SOLID_FILL,RED);
            floodfill(10,10,1);
            outtextxy(getmaxx()/2-100,getmaxy()/2,"RED PLAYER WINS");
        }
    }
}
