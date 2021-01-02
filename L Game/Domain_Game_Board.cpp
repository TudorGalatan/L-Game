/**
    This is the implementation for the Game Board module from the Domain layer.
    The module is responsible with everything related to the game board.
**/

#include "Domain_Game_Board.h"
#include "Domain_Cell.h"
#include "Domain_Player.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

#define HORIZONTAL 1
#define VERTICAL 2


bool areEqualVectors (std::vector < std::pair <USI, USI> > previousCoordinates, std::vector < std::pair <USI, USI> > currentCoordinates)
{
    int prevDim = previousCoordinates.size();
    int currentDim = currentCoordinates.size();
    int nrOfFounds = 0;
    bool found = false;
    for (int i = 0; i < currentDim; i++)
    {
        for (int j = 0; j < prevDim; j++)
            if (previousCoordinates[i].first == currentCoordinates[j].first &&
                    previousCoordinates[i].second == currentCoordinates[j].second)
                found = true;
        if (found == false)
            return false;
        found = false;
    }
    return true;
}


bool GameBoard::findBestMove (unsigned short int aa[4][4], int color, int player,std::vector<std::pair<USI, USI> > &coordinates)
{
    Player* playerRef;
    if(player==1)
        playerRef = &this->redPlayer;
    else
        playerRef = &this->bluePlayer;

    unsigned short int a[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(aa[i][j]==color)
                a[i][j]=0;
            else
                a[i][j]=aa[i][j];
    ///HUNTS A COUPLE OF SPOTS
    coordinates.clear();
    if(a[0][2]+a[1][2]+a[2][2]+a[2][1]==0)
    {
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(2,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[2][0]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(2);
                obj->setYIndex(0);
                this->data[2][0]=3;
                obj->drawCoin(this->cells[2][0].getPosition("ox"),this->cells[2][0].getPosition("oy"));
            }
            return true;
        }
    }
    coordinates.clear();
    if(a[2][0]+a[1][2]+a[2][2]+a[2][1]==0)
    {
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(2,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[0][2]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(0);
                obj->setYIndex(2);
                this->data[0][2]=3;
                obj->drawCoin(this->cells[0][2].getPosition("ox"),this->cells[0][2].getPosition("oy"));
            }
            return true;
        }
    }
    coordinates.clear();
    if(a[0][1]+a[1][1]+a[2][1]+a[2][2]==0)
    {
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[2][3]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(2);
                obj->setYIndex(3);
                this->data[2][3]=3;
                obj->drawCoin(this->cells[2][3].getPosition("ox"),this->cells[2][3].getPosition("oy"));
            }
            return true;
        }
    }
    coordinates.clear();
    if(a[2][3]+a[1][1]+a[2][1]+a[2][2]==0)
    {
        coordinates.push_back(std::make_pair(2,3));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[1][0]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(0);
                obj->setYIndex(1);
                this->data[0][1]=3;
                obj->drawCoin(this->cells[1][0].getPosition("ox"),this->cells[1][0].getPosition("oy"));
            }
            return true;
        }
    }
    coordinates.clear();
    if(a[3][1]+a[2][1]+a[1][1]+a[1][2]==0)
    {
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[1][3]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(1);
                obj->setYIndex(3);
                this->data[1][3]=3;
                obj->drawCoin(this->cells[1][3].getPosition("ox"),this->cells[1][3].getPosition("oy"));
            }
            return true;
        }
    }
    coordinates.clear();
    if(a[1][3]+a[2][1]+a[1][1]+a[1][2]==0)
    {
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[3][1]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(3);
                obj->setYIndex(1);
                this->data[3][1]=3;
                obj->drawCoin(this->cells[3][1].getPosition("ox"),this->cells[3][1].getPosition("oy"));
            }
            return true;
        }
    }
    coordinates.clear();
    if(a[3][2]+a[2][2]+a[1][2]+a[1][1]==0)
    {
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[1][0]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(1);
                obj->setYIndex(0);
                this->data[1][0]=3;
                obj->drawCoin(this->cells[1][0].getPosition("ox"),this->cells[1][0].getPosition("oy"));
            }
            return true;
        }
    }
    coordinates.clear();
    if(a[1][0]+a[2][2]+a[1][2]+a[1][1]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
        {
            srand(time(NULL));
            int val = rand()%2+1;
            Coin* obj;
            if(val==1)
                obj=&this->firstCoin;
            else
                obj=&this->secondCoin;
            if(this->data[3][2]==0)
            {
                obj->deleteCoin(this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("ox"),this->cells[obj->getXIndex()][obj->getYIndex()].getPosition("oy"));
                this->data[obj->getXIndex()][obj->getYIndex()]=0;
                obj->setXIndex(3);
                obj->setYIndex(2);
                this->data[3][2]=3;
                obj->drawCoin(this->cells[3][2].getPosition("ox"),this->cells[3][2].getPosition("oy"));
            }
            return true;
        }
    }
    ///END OF THE 'HUNTING' - Adi 2020

    coordinates.clear();
    if(a[0][0]+a[1][0]+a[2][0]+a[0][1]==0)
    {
        coordinates.push_back(std::make_pair(0,0));
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(0,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[0][1]+a[1][1]+a[2][1]+a[0][2]==0)
    {
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(0,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[0][2]+a[1][2]+a[2][2]+a[0][3]==0)
    {
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(0,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[0][0]+a[0][1]+a[1][1]+a[2][1]==0)
    {
        coordinates.push_back(std::make_pair(0,0));
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[0][1]+a[0][2]+a[1][2]+a[2][2]==0)
    {
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[0][2]+a[0][3]+a[1][3]+a[2][3]==0)
    {
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(0,3));
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(2,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][0]+a[2][0]+a[3][0]+a[1][1]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(3,0));
        coordinates.push_back(std::make_pair(1,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][1]+a[2][1]+a[3][1]+a[1][2]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(1,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][2]+a[2][2]+a[3][2]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(1,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][0]+a[1][1]+a[2][1]+a[3][1]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(3,1));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][1]+a[1][2]+a[2][2]+a[3][2]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(3,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[3][2]+a[3][3]+a[2][3]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(3,3));
        coordinates.push_back(std::make_pair(2,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][2]+a[1][3]+a[2][3]+a[3][3]==0)
    {
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(2,3));
        coordinates.push_back(std::make_pair(3,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[0][0]+a[0][1]+a[0][2]+a[1][0]==0)
    {
        coordinates.push_back(std::make_pair(0,0));
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(1,0));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][0]+a[1][1]+a[1][2]+a[2][0]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,0));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[2][0]+a[2][1]+a[2][2]+a[3][0]==0)
    {
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(3,0));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][1]+a[0][1]+a[0][2]+a[0][3]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(0,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[2][1]+a[1][1]+a[1][2]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[3][1]+a[2][1]+a[2][2]+a[2][3]==0)
    {
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(2,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][0]+a[1][1]+a[1][2]+a[0][2]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(0,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[2][0]+a[2][1]+a[2][2]+a[1][2]==0)
    {
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(1,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[3][0]+a[3][1]+a[3][2]+a[2][2]==0)
    {
        coordinates.push_back(std::make_pair(3,0));
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(2,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[1][1]+a[1][2]+a[1][3]+a[0][3]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(0,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[2][1]+a[2][2]+a[2][3]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(2,3));
        coordinates.push_back(std::make_pair(1,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[3][1]+a[3][2]+a[3][3]+a[2][3]==0)
    {
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(3,3));
        coordinates.push_back(std::make_pair(2,3));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }
    coordinates.clear();
    if(a[2][0]+a[3][0]+a[3][1]+a[3][2]==0)
    {
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(3,0));
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(3,2));
        if(areEqualVectors(playerRef->getCoordinates(),coordinates)==false)
            return true;
    }

    return false;
}


bool GameBoard::findMove (unsigned short int aa[4][4], int color, int player, std::vector<std::pair<USI, USI> > &coordinates)
{
    Player* obj;

    if (player == 1)
        obj = &this->redPlayer;
    else
        obj = &this->bluePlayer;

    unsigned short int a[4][4];
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
            if (aa[line][column] == color)
                a[line][column] = 0;
            else
                a[line][column] = aa[line][column];

    coordinates.clear();
    if(a[0][0]+a[1][0]+a[2][0]+a[0][1]==0)
    {
        coordinates.push_back(std::make_pair(0,0));
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(0,1));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[0][1]+a[1][1]+a[2][1]+a[0][2]==0)
    {
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(0,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[0][2]+a[1][2]+a[2][2]+a[0][3]==0)
    {
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(0,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[0][0]+a[0][1]+a[1][1]+a[2][1]==0)
    {
        coordinates.push_back(std::make_pair(0,0));
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[0][1]+a[0][2]+a[1][2]+a[2][2]==0)
    {
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[0][2]+a[0][3]+a[1][3]+a[2][3]==0)
    {
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(0,3));
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(2,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][0]+a[2][0]+a[3][0]+a[1][1]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(3,0));
        coordinates.push_back(std::make_pair(1,1));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][1]+a[2][1]+a[3][1]+a[1][2]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(1,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][2]+a[2][2]+a[3][2]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(1,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][0]+a[1][1]+a[2][1]+a[3][1]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(3,1));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][1]+a[1][2]+a[2][2]+a[3][2]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(3,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[3][2]+a[3][3]+a[2][3]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(3,3));
        coordinates.push_back(std::make_pair(2,3));
        coordinates.push_back(std::make_pair(1,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][2]+a[1][3]+a[2][3]+a[3][3]==0)
    {
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(2,3));
        coordinates.push_back(std::make_pair(3,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[0][0]+a[0][1]+a[0][2]+a[1][0]==0)
    {
        coordinates.push_back(std::make_pair(0,0));
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(1,0));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][0]+a[1][1]+a[1][2]+a[2][0]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(2,0));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[2][0]+a[2][1]+a[2][2]+a[3][0]==0)
    {
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(3,0));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][1]+a[0][1]+a[0][2]+a[0][3]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(0,1));
        coordinates.push_back(std::make_pair(0,2));
        coordinates.push_back(std::make_pair(0,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[2][1]+a[1][1]+a[1][2]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[3][1]+a[2][1]+a[2][2]+a[2][3]==0)
    {
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(2,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][0]+a[1][1]+a[1][2]+a[0][2]==0)
    {
        coordinates.push_back(std::make_pair(1,0));
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(0,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[2][0]+a[2][1]+a[2][2]+a[1][2]==0)
    {
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(1,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[3][0]+a[3][1]+a[3][2]+a[2][2]==0)
    {
        coordinates.push_back(std::make_pair(3,0));
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(2,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[1][1]+a[1][2]+a[1][3]+a[0][3]==0)
    {
        coordinates.push_back(std::make_pair(1,1));
        coordinates.push_back(std::make_pair(1,2));
        coordinates.push_back(std::make_pair(1,3));
        coordinates.push_back(std::make_pair(0,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[2][1]+a[2][2]+a[2][3]+a[1][3]==0)
    {
        coordinates.push_back(std::make_pair(2,1));
        coordinates.push_back(std::make_pair(2,2));
        coordinates.push_back(std::make_pair(2,3));
        coordinates.push_back(std::make_pair(1,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[3][1]+a[3][2]+a[3][3]+a[2][3]==0)
    {
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(3,2));
        coordinates.push_back(std::make_pair(3,3));
        coordinates.push_back(std::make_pair(2,3));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    coordinates.clear();
    if(a[2][0]+a[3][0]+a[3][1]+a[3][2]==0)
    {
        coordinates.push_back(std::make_pair(2,0));
        coordinates.push_back(std::make_pair(3,0));
        coordinates.push_back(std::make_pair(3,1));
        coordinates.push_back(std::make_pair(3,2));
        if(areEqualVectors(obj->getCoordinates(),coordinates)==false)
            return true;
    }

    return false;
}


void GameBoard::getInitialConfiguration ()
{
    std::ifstream inputFile("Input.in");

    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
        {
            unsigned short int cells;
            inputFile >> cells;
            this->data[line][column] = cells;
        }

    inputFile.close();
}


void GameBoard::saveCurrentConfiguration ()
{
    std::ofstream saveFile("Playground.txt");

    for (unsigned short int line = 0; line < 4; line++)
    {
        for (unsigned short int column = 0; column < 4; column++)
            saveFile << this->data[line][column] << ' ';
        saveFile << '\n';
    }
}


void GameBoard::drawBoard ()
{
    int xCoord = 0, yCoord = 0;

    // Get the size of the screen
    int width = getmaxx();
    int height = getmaxy();

    int cellSize = (height - 200) / 4;

    this->cells[xCoord][yCoord].setDimension(cellSize);

    // Draw every cells.
    for (int i = width / 2 - 2 * cellSize; i <= width / 2 + cellSize; i += cellSize)
    {
        for (int j = height / 4 - cellSize; j <= height / 4 + 2 * cellSize; j += cellSize)
        {
            this->cells[xCoord][yCoord].drawCell(i, j,i + cellSize, j + cellSize);///draw the cells
            this->cells[xCoord][yCoord].setPosition(i + cellSize / 2, j + cellSize / 2);///coordonates for the floodfill
            this->cells[xCoord][yCoord].setTopLeftMargins(j,i);///saves the left and top in this object
            this->cells[xCoord][yCoord].setColour(BLACK);///set the black color to the cells
            xCoord++;
        }
        xCoord = 0;
        yCoord++;
    }
}



/**
    Loads the game with the values from data.txt
**/
void GameBoard::loadNewGame ()
{
    std::vector < std::pair <USI, USI> > redPlayerCoordinates, bluePlayerCoordinates;
    int start = 0;
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)

            // Colour the red player.
            if (this->data[line][column] == 1)
            {
                this->cells[line][column].setColour(RED);
                redPlayerCoordinates.push_back(std::make_pair(line, column));
                ++start;
            }

            // Colour the blue player.
            else if (this->data[line][column] == 2)
            {
                this->cells[line][column].setColour(BLUE);
                bluePlayerCoordinates.push_back(std::make_pair(line, column));
            }

            // Colour the coins.
            else if (this->data[line][column] == 3)
            {
                this->firstCoin.drawCoin(this->cells[line][column].getPosition("ox"), this->cells[line][column].getPosition("oy"));
                if(this->firstCoin.getXIndex() == -1)
                {
                    this->firstCoin.setXIndex(line);
                    this->firstCoin.setYIndex(column);
                }
                else
                {
                    this->secondCoin.setXIndex(line);
                    this->secondCoin.setYIndex(column);
                }
            }

    this->redPlayer.setCoordinates(redPlayerCoordinates);
    this->bluePlayer.setCoordinates(bluePlayerCoordinates);
}


void GameBoard::drawButton(int color)
{
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    setcolor(color);
    int maxx = getmaxx()/10;
    int maxy = getmaxy()/2;
    outtextxy(maxx, maxy,"SKIP MOVING");
}


void GameBoard::moveCoin ()
{
    int x = this->firstCoin.getXIndex(),y=this->firstCoin.getYIndex();
    unsigned short int line,column;
    Coin* coinRef = NULL;
    while(true)
    {
        HWND hwnd = GetForegroundWindow();
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);

        // Get the mouse position on the window.
        ScreenToClient(hwnd, &cursorPosition);

        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        if(GetAsyncKeyState(VK_LBUTTON) && xCoordinate >= getmaxx()/10 && xCoordinate <= getmaxx()/10 + 300 && yCoordinate>=getmaxy()/2-100 && yCoordinate<=getmaxy()/2+100)
            return;
        if(GetAsyncKeyState(VK_LBUTTON) && coinRef == NULL)
        {

            for (line = 0; line < 4 && coinRef == NULL; line++)
            {
                for (column = 0; column < 4; column++)
                    if (this->cells[line][column].isInside(xCoordinate, yCoordinate) && this->data[line][column] == 3)
                        if(line == x && column == y)
                        {
                            this->data[line][column]=0;
                            coinRef = &this->firstCoin;
                            this->firstCoin.deleteCoin(this->cells[line][column].getPosition("ox"),this->cells[line][column].getPosition("oy"));
                        }
                        else
                        {
                            this->data[line][column]=0;
                            coinRef = &this->secondCoin;
                            this->secondCoin.deleteCoin(this->cells[line][column].getPosition("ox"),this->cells[line][column].getPosition("oy"));
                        }
            }
            delay(100);
        }
        else if(GetAsyncKeyState(VK_LBUTTON) && coinRef != NULL)
        {

            coinRef->setXIndex(line);
            coinRef->setYIndex(column);
            for (unsigned short int line = 0; line < 4; line++)
            {
                for (unsigned short int column = 0; column < 4; column++)
                    if (this->cells[line][column].isInside(xCoordinate, yCoordinate) && this->data[line][column] == 0)
                    {
                        coinRef->drawCoin(this->cells[line][column].getPosition("ox"),this->cells[line][column].getPosition("oy"));
                        this->data[line][column] = 3;
                        return;
                    }
            }
        }
    }

}


void GameBoard::redPlayerMoves ()
{
    drawButton(DARKGRAY);
    unsigned short int numberOfClicks = 0;

    previousCoordinates.push_back(std::make_pair(0, 0));
    previousCoordinates.push_back(std::make_pair(0, 0));
    previousCoordinates.push_back(std::make_pair(0, 0));
    previousCoordinates.push_back(std::make_pair(0, 0));
    while (numberOfClicks < 4)
    {
        // Right click
        if (GetAsyncKeyState(VK_RBUTTON))
        {
            numberOfClicks = 0;
            for (unsigned short int line = 0; line < 4; line++)
            {
                for (unsigned short int column = 0; column < 4; column++)
                    if (this->data[line][column] == 1)
                    {
                        this->data[line][column] = 0;
                        this->cells[line][column].setColour(BLACK);
                    }
                    this->redPlayer.setCoordinatesOfCell(line, 10, 10);
            }
        }

        // Left click
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (numberOfClicks == 0)
            {
                for (unsigned short int line = 0; line < 4; line++)
                {
                    previousCoordinates[line].first = this->redPlayer.getLineCoordinateOfCell(line);
                    previousCoordinates[line].second = this->redPlayer.getColumnCoordinateOfCell(line);

                    for (unsigned short int column = 0; column < 4; column++)
                        if (this->data[line][column] == 1)
                        {
                            this->data[line][column] = 0;
                            this->cells[line][column].setColour(BLACK);
                        }
                    this->redPlayer.setCoordinatesOfCell(line, 10, 10);
                }
            }

            HWND hwnd = GetForegroundWindow();
            POINT cursorPosition;

            // Get the mouse position.
            GetCursorPos(&cursorPosition);

            // Get the mouse position on the window.
            ScreenToClient(hwnd, &cursorPosition);

            double xCoordinate = cursorPosition.x;
            double yCoordinate = cursorPosition.y;

            bool stop = false;

            for (unsigned short int line = 0; line < 4 && numberOfClicks <= 4 && stop == false; line++)
            {
                for (unsigned short int column = 0; column < 4 && stop == false; column++)
                    if (this->cells[line][column].isInside(xCoordinate, yCoordinate) && this->data[line][column] == 0)
                    {
                        this->data[line][column] = 1;
                        this->cells[line][column].setColour(RED);
                        ++numberOfClicks;
                        this->redPlayer.setCoordinatesOfCell(numberOfClicks - 1, line, column);
                        stop = true;
                    }
            }
            if (numberOfClicks == 4)
                if (this->checkMove(this->redPlayer.getCoordinates(), previousCoordinates))
                {
                    drawButton(WHITE);
                    moveCoin();
                }
                else
                    numberOfClicks = 0;
            else if(numberOfClicks > 4)
                numberOfClicks = 0;

            delay(202);
        }
    }
}


void GameBoard::bluePlayerMoves()
{
    drawButton(DARKGRAY);
    unsigned short int numberOfClicks = 0;
    std::vector < std::pair <USI, USI> > previousCoordinates;
    previousCoordinates.push_back(std::make_pair(0, 0));
    previousCoordinates.push_back(std::make_pair(0, 0));
    previousCoordinates.push_back(std::make_pair(0, 0));
    previousCoordinates.push_back(std::make_pair(0, 0));
    while (numberOfClicks < 4)
    {
        // Right click
        if (GetAsyncKeyState(VK_RBUTTON))
        {
            numberOfClicks = 0;
            for (unsigned short int line = 0; line < 4; line++)
            {
                for (unsigned short int column = 0; column < 4; column++)
                    if (this->data[line][column] == 2)
                    {
                        this->data[line][column] = 0;
                        this->cells[line][column].setColour(BLACK);
                    }
                this->bluePlayer.setCoordinatesOfCell(line, 10, 10);
            }
        }

        // Left click
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (numberOfClicks == 0)
            {
                for (unsigned short int line = 0; line < 4; line++)
                {
                    previousCoordinates[line].first = this->bluePlayer.getLineCoordinateOfCell(line);
                    previousCoordinates[line].second = this->bluePlayer.getColumnCoordinateOfCell(line);

                    for (unsigned short int column = 0; column < 4; column++)
                        if (this->data[line][column] == 2)
                        {
                            this->data[line][column] = 0;
                            this->cells[line][column].setColour(BLACK);
                        }
                    this->bluePlayer.setCoordinatesOfCell(line, 10, 10);
                }
            }

            HWND hwnd = GetForegroundWindow();
            POINT cursorPosition;

            // Get the mouse position.
            GetCursorPos(&cursorPosition);

            // Get the mouse position on the window.
            ScreenToClient(hwnd, &cursorPosition);

            double xCoordinate = cursorPosition.x;
            double yCoordinate = cursorPosition.y;

            bool stop = false;

            for (unsigned short int line = 0; line < 4 && numberOfClicks <= 4 && stop == false; line++)
            {
                for (unsigned short int column = 0; column < 4 && stop == false; column++)
                    if (this->cells[line][column].isInside(xCoordinate, yCoordinate) && this->data[line][column] == 0)
                    {
                        this->data[line][column] = 2;
                        this->cells[line][column].setColour(BLUE);
                        ++numberOfClicks;
                        this->bluePlayer.setCoordinatesOfCell(numberOfClicks - 1, line, column);
                        stop = true;
                    }
            }
            if (numberOfClicks == 4)
                if (this->checkMove(this->bluePlayer.getCoordinates(),previousCoordinates))
                {
                    drawButton(WHITE);
                    moveCoin();
                }
                else
                    numberOfClicks = 0;

            delay(202);
        }
    }
}


bool GameBoard::checkMove (std::vector < std::pair <USI, USI> > coordinates, std::vector < std::pair <USI, USI> >previousCoordinates)
{
    // All the cells must be free (black or the current player).
    if (this->goodCells(previousCoordinates) == false)
        return false;

    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

    // If we have neither a horizontal, nor a vertical orientation, then it is not an "L".
    if (orientation.first == 0)
        return false;

    // If there is a gap between the three squares that should form an "L", then it cannot be an "L".
    if (this->hasGap(coordinates))
        return false;

    // Get the start and end coordinates for the body of the "L" form.
    std::pair <USI, USI> startEndPositions = this->getStartEndPositions(coordinates);

    // If the fourth square of the possible "L" is not on a valid position, then it cannot be an "L".
    if (this->onValidPosition(coordinates) == false)
        return false;

    // We have an "L" form with free cells only, so it is a valid move.
    return true;
}


void GameBoard::makeMove (std::vector < std::pair <USI, USI> > newCoordinates)
{
    // Delete the current squares of the current player.
    for (unsigned short int line = 0; line < 4; line++)
        for (unsigned short int column = 0; column < 4; column++)
            if (this->data[line][column] == this->currentPlayer)
                this->data[line][column] = 0;

    // Add the player on the new position.
    for (unsigned short int square = 0; square < 4; square++)
    {
        unsigned short int line = newCoordinates[square].first;
        unsigned short int column = newCoordinates[square].second;
        this->data[line][column] = this->currentPlayer;
    }
}


bool GameBoard::goodCells (std::vector < std::pair <USI, USI> > coordinates)
{
    unsigned short int goodCells = 0;
    unsigned short int sameMoves = 0;
    for (unsigned short int cells = 0; cells < 4; cells++)
    {
        unsigned short int line = coordinates.at(cells).first;
        unsigned short int column = coordinates.at(cells).second;

        if (this->data[line][column] == this->currentPlayer)
        {
            goodCells++;
            sameMoves++;
        }
        else if (this->data[line][column] == 0)
            goodCells++;
    }

    // You cannot make the same move.
    if (sameMoves == 4)
        return false;

    // All cells must be good (black or current player).
    if (goodCells != 4)
        return false;

    return true;
}


std::pair <USI, USI> GameBoard::getOrientation (std::vector < std::pair <USI, USI> > coordinates)
{
    // The frequency of the lines and columns of the coordinates for the possible "L"
    unsigned short int frequencyOfLine[4] = { 0 };
    unsigned short int frequencyOfColumn[4] = { 0 };

    // Calculate how many times a line or a column appears in the coordinates.
    for (unsigned short int square = 0; square < 4; square++)
    {
        frequencyOfLine[coordinates[square].first]++;
        frequencyOfColumn[coordinates[square].second]++;
    }

    unsigned short int line = 4, column = 4;

    std::pair <USI, USI> orientation;

    // Firstly, we assume that we have neither a horizontal, nor a vertical orientation.
    orientation.first = 0;
    orientation.second = 0;

    // Check if there is a horizontal or a vertical orientation.
    for (unsigned short int square = 0; square < 4; square++)
    {
        // We have a horizontal orientation if there are 3 equal line coordinates.
        if (frequencyOfLine[square] == 3)
        {
            orientation.first = 1;
            orientation.second = square;
        }

        // We have a vertical orientation if there are 3 equal column coordinates.
        if (frequencyOfColumn[square] == 3)
        {
            orientation.first = 2;
            orientation.second = square;
        }
    }

    return orientation;
}


bool GameBoard::hasGap (std::vector < std::pair <USI, USI> > coordinates)
{
    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

    // We have a horizontal orientation.
    if (orientation.first == 1)
    {
        bool hasColumnZero = false, hasColumnThree = false;

        for (unsigned short int cells = 0; cells < 4; cells++)
        {
            unsigned short int column = coordinates[cells].second;

            if (column == 0)
                hasColumnZero = true;

            if (column == 3)
                hasColumnThree = true;
        }

        if (hasColumnZero && hasColumnThree)
            return true;
    }

    // We have a vertical orientation.
    bool hasLineZero = false, hasLineThree = false;

    for (unsigned short int cells = 0; cells < 4; cells++)
    {
        unsigned short int line = coordinates[cells].first;

        if (line == 0)
            hasLineZero = true;

        if (line == 3)
            hasLineThree = true;
    }

    if (hasLineZero && hasLineThree)
        return true;

    // We don't have a gap.
    return false;
}


std::pair <USI, USI> GameBoard::getStartEndPositions (std::vector < std::pair <USI, USI> > coordinates)
{
    // We assume the start position is 0.
    unsigned short int startPosition = 0;

    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

    // We have a horizontal orientation.
    if (orientation.first == 1)
    {
        bool startOnPosition_1 = true;

        for (unsigned short int cells = 0; cells < 4; cells++)
        {
            unsigned short int column = coordinates[cells].second;
            if (column == 0)
                startOnPosition_1 = false;
        }

        if (startOnPosition_1)
            startPosition = 1;
    }

    // We have a vertical orientation.
    else
    {
        bool startOnPosition_1 = true;

        for (unsigned short int cells = 0; cells < 4; cells++)
        {
            unsigned short int line = coordinates[cells].first;
            if (line == 0)
                startOnPosition_1 = false;
        }

        if (startOnPosition_1)
            startPosition = 1;
    }

    unsigned short int endPosition = startPosition + 2;

    std::pair <USI, USI> startEndPositions;
    startEndPositions.first = startPosition;
    startEndPositions.second = endPosition;

    return startEndPositions;
}


bool GameBoard::onValidPosition (std::vector < std::pair <USI, USI> > coordinates)
{
    std::pair <USI, USI> startEndPositions = this->getStartEndPositions(coordinates);
    unsigned short int startPosition = startEndPositions.first;
    unsigned short int endPosition = startEndPositions.second;

    std::vector < std::pair <USI, USI> > possibleCoordinates;

    std::pair <USI, USI> orientation = this->getOrientation(coordinates);

    // We have a horizontal orientation.
    if (orientation.first == 1)
    {
        unsigned short int line = orientation.second;
        if (line > 0)
        {
            possibleCoordinates.push_back(std::make_pair(line - 1, startPosition));
            possibleCoordinates.push_back(std::make_pair(line - 1, endPosition));
        }

        if (line < 3)
        {
            possibleCoordinates.push_back(std::make_pair(line + 1, startPosition));
            possibleCoordinates.push_back(std::make_pair(line + 1, endPosition));
        }
    }

    // We have a vertical orientation.
    else
    {
        unsigned short int column = orientation.second;

        if (column > 0)
        {
            possibleCoordinates.push_back(std::make_pair(startPosition, column - 1));
            possibleCoordinates.push_back(std::make_pair(endPosition, column - 1));
        }

        if (column < 3)
        {
            possibleCoordinates.push_back(std::make_pair(startPosition, column + 1));
            possibleCoordinates.push_back(std::make_pair(endPosition, column + 1));
        }
    }

    for (unsigned short int possibleSquare = 0; possibleSquare < possibleCoordinates.size(); possibleSquare++)
    {
        for (unsigned short int square = 0; square < 4; square++)
            if (possibleCoordinates[possibleSquare] == coordinates[square])
                return true;
    }

    // The other square is not on a valid position.
    return false;
}
