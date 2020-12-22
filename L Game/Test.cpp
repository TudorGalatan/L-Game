/**
    This is the implementation for the Test module.
    The module is responsible with testing the functionalities of the application.
**/

#include "Test.h"



void Test::runAll ()
{
    this->gameBoard.getInitialConfiguration();

    // Tests
    this->checkMove();
    this->goodCells();
    this->getOrientation();
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

    // Test 1 - Over a coin
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 0));
    bool ourResult = this->gameBoard.goodCells(coordinates);
    bool correctResult = false;
    assert(ourResult == correctResult);

    // Test 2 - Over a coin and the other player
    coordinates[0] = std::make_pair(1, 2);
    coordinates[1] = std::make_pair(1, 3);
    coordinates[2] = std::make_pair(2, 3);
    coordinates[3] = std::make_pair(3, 3);
    ourResult = this->gameBoard.goodCells(coordinates);
    correctResult = false;
    assert(ourResult == correctResult);

    // Test 3 - Almost the same move
    coordinates[0] = std::make_pair(2, 0);
    coordinates[1] = std::make_pair(2, 1);
    coordinates[2] = std::make_pair(2, 2);
    coordinates[3] = std::make_pair(3, 0);
    ourResult = this->gameBoard.goodCells(coordinates);
    correctResult = true;
    assert(ourResult == correctResult);

    // Test 4 - Same move
    coordinates[0] = std::make_pair(1, 0);
    coordinates[1] = std::make_pair(2, 0);
    coordinates[2] = std::make_pair(2, 1);
    coordinates[3] = std::make_pair(2, 2);
    ourResult = this->gameBoard.goodCells(coordinates);
    correctResult = false;
    assert(ourResult == correctResult);
}



std::pair <USI, USI> Test::getOrientation ()
{
    std::vector < std::pair <USI, USI> > coordinates;

    // Test 1 - Horizontal orientation
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 0));
    std::pair <USI, USI> ourResult = this->gameBoard.getOrientation(coordinates);
    std::pair <USI, USI> correctResult = std::make_pair(1, 0);
    assert(ourResult == correctResult);

    // Test 2 - Vertical orientation
    coordinates[0] = std::make_pair(0, 2);
    coordinates[1] = std::make_pair(1, 2);
    coordinates[2] = std::make_pair(2, 2);
    coordinates[3] = std::make_pair(2, 3);
    ourResult = this->gameBoard.getOrientation(coordinates);
    correctResult = std::make_pair(2, 2);
    assert(ourResult == correctResult);

    // Test 3 - Neither horizontal, nor vertical orientation
    coordinates[0] = std::make_pair(0, 1);
    coordinates[1] = std::make_pair(1, 0);
    coordinates[2] = std::make_pair(1, 1);
    coordinates[3] = std::make_pair(2, 2);
    ourResult = this->gameBoard.getOrientation(coordinates);
    correctResult = std::make_pair(0, 0);
    assert(ourResult == correctResult);
}
