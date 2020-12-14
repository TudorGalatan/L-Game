#include "Multiplayer.h"

#include <graphics.h>
#include <windows.h>
#include <iostream>

void startMultiplayerGame()
{
    cleardevice();
    drawBoard();
    while(true)
        continue;
}

void drawBoard()
{
    ///Get the length and the width of the screen.
    int length = GetSystemMetrics(SM_CXSCREEN);
    int width = GetSystemMetrics(SM_CYSCREEN);
    int left = width / 2 - 150,right = width + width / 2 - 150, bottom = width - 100,top = 50;
    int midX = (left + right) / 2;
    int midY = (top + bottom) / 2;

    rectangle(left,top,right,bottom);
    line(midX, top, midX, bottom);
    line(right, midY, left, midY);

    midX = (left + midX) / 2;
    midY = (top + midY) / 2;

    line(midX, top, midX, bottom);
    line(right, midY, left, midY);


    ///TODO: Change values here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    midX = (left + right) / 2 + midX;
    midY = (top + bottom) / 2 + midY;
    line(midX, top, midX, bottom);
    line(right, midY, left, midY);
}
