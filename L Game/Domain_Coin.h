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

        // the size of the coin     ??? The radius?
        int coinSize = 100;

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
        int getCoinSize ();
};
