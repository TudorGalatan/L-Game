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
        if(this->gameBoard.checkWinner(this->gameBoard.boardData,1,1,positions)== false && player == false)
        {
            for(int i=0;i<positions.size();i++)
                g<<positions[i].first<<' '<<positions[i].second<<'\n';
            delay(2000);
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
        else if(this->gameBoard.checkWinner(this->gameBoard.boardData,2,2,positions)==false && player == true)
        {for(int i=0;i<positions.size();i++)
                g<<positions[i].first<<' '<<positions[i].second<<'\n';
            delay(2000);
            int xCoord = getmaxx()/2,yCoord=getmaxy()/2;
            for(int i=10;i<=2000;i+=4)
            {///si aici o sa fie cv animatie de win
                setcolor(WHITE);
                outtextxy(xCoord-50,yCoord-10,"RED WINS");
                setcolor(RED);
                setlinestyle(SOLID_LINE,0,5);
                circle(xCoord, yCoord, i);
                setfillstyle(SOLID_FILL, RED);
                floodfill(xCoord, yCoord, WHITE);
            }
        }
    }
}
