#include <fstream>
#include <iostream>
#include <vector>



void runApplication ();
void readData (unsigned short int board[][4]);
void printBoard (unsigned short int board[][4]);
void getNewCoordinates (std::vector < std::pair <unsigned short int, unsigned short int> >& coordinates);
bool checkMove (unsigned short int board[][4], unsigned short int currentPlayer, std::vector < std::pair <unsigned short int, unsigned short int> > coordinates);
