/**
    This is the interface for the Controller layer.
    The Controller layer is responsible with coordinating the application.
**/

#pragma once

#include "Player_Versus_Player.h"

#include <vector>

#define USI unsigned short int



void runApplication ();
void readData (USI gameBoard[][4],GameBoard board);
void printBoard (USI gameBoard[][4]);
void getNewCoordinates (std::vector < std::pair <USI, USI> >& coordinates);
bool checkMove (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > coordinates);
std::pair <USI, USI> getOrientation (USI gameBoard[][4], std::vector < std::pair <USI, USI> > coordinates);
bool hasGap (USI gameBoard[][4], std::pair <USI, USI> orientation, USI currentPlayer);
std::pair <USI, USI> getStartEndPositions (USI gameBoard[][4], std::pair <USI, USI> orientation, USI currentPlayer);
bool onValidPosition (USI gameBoard[][4], std::pair <USI, USI> orientation, std::pair <USI, USI> startEndPositions, USI currentPlayer);
void makeMove (USI gameBoard[][4], USI currentPlayer, std::vector < std::pair <USI, USI> > newCoordinates);
