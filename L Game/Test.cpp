/**
    This is the implementation for the Test module.
    The module is responsible with testing the functionalities of the application.
**/

#include "Test.h"



void Test::runAll ()
{
    this->gameBoard.getInitialConfiguration();
    this->checkMove();
    this->goodCells();
}



void Test::checkMove ()
{
    std::vector < std::pair <USI, USI> > coordinates;

    // Test 1
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 0));
    // assert(this->gameBoard.checkMove(coordinates) == true);
}



bool Test::goodCells ()
{
    std::vector < std::pair <USI, USI> > coordinates;

    // Test 1
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 0));
    assert(this->gameBoard.goodCells(coordinates) == false);

    // Test 2
    coordinates[0] = std::make_pair(1, 2);
    coordinates[0] = std::make_pair(1, 3);
    coordinates[0] = std::make_pair(2, 3);
    coordinates[0] = std::make_pair(3, 3);
    assert(this->gameBoard.goodCells(coordinates) == false);

    // Test 3
    coordinates[0] = std::make_pair(2, 0);
    coordinates[0] = std::make_pair(2, 1);
    coordinates[0] = std::make_pair(2, 2);
    coordinates[0] = std::make_pair(3, 0);
    assert(this->gameBoard.goodCells(coordinates) == true);
}
