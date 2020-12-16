#include "Multiplayer.h"

#include <graphics.h>
#include <iostream>
#include <Windows.h>

void startMultiplayerGame()
{
    Cell cell[4][4];
    bool player = false;///False -> RED PLAYER, True -> BLUE PLAYER
    cleardevice();
    drawBoard(cell);
    delay(1000);///Just for testingm
    while(true)
    {
        switch(player)
        {
            case false:
                ///RED TURN
                redMove(cell);
                player = !player;
                break;
            default:
                ///BLUE TURN
                player = !player;
        }
    }
}
/**
    Cell class functions.
*/
void Cell::setColor(int color)///set the color of the cell
{
    cellColor = color;
    setfillstyle(SOLID_FILL, color);///set the fill style
    floodfill(posX,posY,WHITE);///color the cell
}
void Cell::drawCell(int left,int up,int right,int bottom)
{
    rectangle(left,up,right,bottom);
}

int Cell::changeCellSize(int newSize)
{
    dim = newSize;
    return dim;
}
void Cell::setPosition(int pX,int pY)
{
    posX = pX;
    posY = pY;
}
int Cell::getColor()
{
    return cellColor;
}
///---------------------------------------------------------------
/**
    Coin class functions.
*/
void Coin::drawCoin()///we have to change this function to be more flexible-----> pls ask me wtf i meant by that
{
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;
    int posX = height / 4 + cellSize + cellSize / 2;
    int posY = height / 4 - cellSize + cellSize / 2;
    circle(posX, posY, getCoinSize());
    setfillstyle(SOLID_FILL, YELLOW);///set the fill style
    floodfill(posX,posY,WHITE);///color the cell
}
///---------------------------------------------------------------
void drawBoard(Cell cell[][4])
{
    Coin coin1,coin2;
    int xCoord = 0, yCoord = 0;
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;///calculate the size of a cell
    cellSize = cell[xCoord][yCoord].changeCellSize(cellSize);///change the value in the class
    for(int i = height / 4 + cellSize; i <= height / 4 + 4 * cellSize; i += cellSize)
    {
        for(int j = height / 4 - cellSize; j <= height / 4 + 2 * cellSize; j += cellSize)
        {
            cell[xCoord][yCoord].drawCell(i, j,i + cellSize, j + cellSize);///draw the cell
            cell[xCoord][yCoord].setPosition(i + cellSize / 2, j + cellSize / 2);
            cell[xCoord][yCoord].setColor(BLACK);///set the black color to the cells
            xCoord++;
        }
        xCoord = 0;
        yCoord++;
    }
    ///Draw the coin from the top-left
    coin1.drawCoin();
    ///Draw the red L.
    cell[1][0].setColor(RED);
    for(int i=0;i<3;i++)
        cell[2][i].setColor(RED);
    ///Draw the blue L.
    cell[2][3].setColor(BLUE);
    for(int i=1;i<=3;i++)
        cell[1][i].setColor(BLUE);
}
void redMove(Cell cell[][4])
{
    if(GetAsyncKeyState(VK_LBUTTON))
    {
        int playerColor = RED;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(cell[i][j].getColor() == RED)
                    cell[i][j].setColor(BLACK);
    }
}
