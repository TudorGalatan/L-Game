/**
    This is the implementation for the Player Versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#include "Player_Versus_Player.h"


void PlayerVersusPlayer::startGame ()
{
    /*
        false - the red player
        true - the blue player
    */
    bool player = false;

    std::vector <std::pair <unsigned short int, unsigned short int> > positions;

    cleardevice();

    this->gameBoard.getInitialConfiguration();
    this->gameBoard.saveCurrentConfiguration();
    this->gameBoard.drawBoard();
    this->gameBoard.loadNewGame();

    delay(300);

    // Run the game.
    while (true)
    {
        switch (player)
        {
            // It's red player's turn.
            case false:
                this->gameBoard.currentPlayer = 1;
                this->gameBoard.redPlayerMoves();
                player = true;
                break;

            // It's blue player's turn.
            default:
                this->gameBoard.currentPlayer = 2;
                this->gameBoard.bluePlayerMoves();
                player = false;
                break;
        }

        this->gameBoard.saveCurrentConfiguration();

        // The blue player won.
        if (this->gameBoard.findMove(this->gameBoard.data, 1, 1, positions) == false && player == false)
        {
            for (unsigned short int line = 0; line < 4; line++)
                for (unsigned short int column = 0; column < 4; column++)
                    if (this->gameBoard.data[line][column] == 2)
                    {
                        this->gameBoard.cells[line][column].setColour(LIGHTBLUE);
                        delay(500);
                    }

            delay(1000);
            cleardevice();

            setfillstyle(SOLID_FILL, BLUE);
            floodfill(10, 10, 1);
            outtextxy(getmaxx() / 2 - 100, getmaxy() / 2, "The blue player won.");
        }

        // The red player won.
        else if (this->gameBoard.findMove(this->gameBoard.data, 2, 2, positions) == false && player == true)
        {
            for (unsigned short int line = 0; line < 4; line++)
                for (unsigned short int column = 0; column < 4; column++)
                    if (this->gameBoard.data[line][column] == 1)
                    {
                        this->gameBoard.cells[line][column].setColour(LIGHTRED);
                        delay(500);
                    }

            delay(1000);
            cleardevice();

            setfillstyle(SOLID_FILL, RED);
            floodfill(10, 10, 1);
            outtextxy(getmaxx() / 2 - 100, getmaxy() / 2, "The red player won.");
        }
    }
}
