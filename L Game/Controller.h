/**
    This file includes the interface of the Controller layer.
    The Controller layer is responsible with controlling the application.
**/

#pragma once

#include <vector>



void runApplication ();
void readData (unsigned short int gameBoard[][4]);
void printBoard (unsigned short int gameBoard[][4]);
void getNewCoordinates (std::vector < std::pair <unsigned short int, unsigned short int> >& coordinates);
bool checkMove (unsigned short int gameBoard[][4], unsigned short int currentPlayer, std::vector < std::pair <unsigned short int, unsigned short int> > coordinates);
void makeMove (unsigned short int gameBoard[][4], unsigned short int currentPlayer, std::vector < std::pair <unsigned short int, unsigned short int> > newCoordinates);
