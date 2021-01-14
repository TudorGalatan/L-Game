/**
    This is the interface for the Coin module from the Domain layer.
    The module is responsible with everything related to a coin.
**/

#pragma once

#include <graphics.h>
#include <windows.h>


class Coin
{
    private:

        // The radius of the coin
        int coinSize = 100;
        int xIndex = -1,yIndex;

    public:

        /**
            Draws the coin.
            Input:
                - "xCoord": ???
                - "yCoord": ???
            Output:
                - draws the coin
        **/
        void drawCoin (int xCoord, int yCoord);

        /**
            Gets the size of the coin.
            Input:
                - none
            Output:
                - the size of the coin
        **/
        void deleteCoin(int xCoord,int yCoord);

        int getCoinSize ();

        void onClickAction();

        int getXIndex();

        int getYIndex();

        void setXIndex(int value);

        void setYIndex(int value);
};
