/**
    This is the implementation for the Coin module from the Domain layer.
    The module is responsible with everything related to a coin.
**/

#include "Domain_Coin.h"



void Coin::drawCoin (int xCoord, int yCoord)            /// We have to change this function to be more flexible-----> pls ask me wtf i meant by that
{                                                       /// WTF DID YOU MEAN???????
                                                        /// xDDD  I changed it so the coin will spawn at some coordonates saved in each cell object. Waiting for your answer!!!
                                                        /// ...
                                                        /// PUTIN E DE VIN... HEI, AUU, STATI  SFFG DATI-MI DRUMUL... SDFSD... FS.FSA.DFG DFG.....A SF......... .... ..SD GFDG...
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;
    circle(xCoord, yCoord, getCoinSize());
    setfillstyle(SOLID_FILL, YELLOW);

    // Colour the cell.
    floodfill(xCoord, yCoord, WHITE);
}



int Coin::getCoinSize ()
{
    return coinSize;        /// DOES THIS EVEN WORK ??   ->   this.coinSize
}
