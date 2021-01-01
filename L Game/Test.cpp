/**
    This is the implementation for the Test module.
    The module is responsible with testing the functionalities of the application.
**/

#include "Test.h"



void Test::runAll ()
{
    // Get the initial configuration of the game board.
    this->gameBoard.getInitialConfiguration();

    // Run the tests.
    this->checkMove();
    this->goodCells();
    this->getOrientation();
    this->hasGap();
    this->getStartEndPositions();
    this->onValidPosition();
}



void Test::checkMove ()
{
    /*
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;

    // Test 1 - Bad move
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 0));
    bool result = this->gameBoard.checkMove(coordinates);
    bool correctResult = false;
    assert(result == correctResult);

    // Test 2 - Good move
    coordinates[0] = std::make_pair(2, 0);
    coordinates[1] = std::make_pair(2, 1);
    coordinates[2] = std::make_pair(2, 2);
    coordinates[3] = std::make_pair(3, 2);
    result = this->gameBoard.checkMove(coordinates);
    correctResult = true;
    assert(result == correctResult);
    */
}



bool Test::goodCells ()
{
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;

    // Test 1 - Over a coin
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 0));
    bool result = this->gameBoard.goodCells(coordinates);
    bool correctResult = false;
    assert(result == correctResult);

    // Test 2 - Over a coin and the other player
    coordinates[0] = std::make_pair(1, 2);
    coordinates[1] = std::make_pair(1, 3);
    coordinates[2] = std::make_pair(2, 3);
    coordinates[3] = std::make_pair(3, 3);
    result = this->gameBoard.goodCells(coordinates);
    correctResult = false;
    assert(result == correctResult);

    // Test 3 - Almost the same move
    coordinates[0] = std::make_pair(2, 0);
    coordinates[1] = std::make_pair(2, 1);
    coordinates[2] = std::make_pair(2, 2);
    coordinates[3] = std::make_pair(3, 0);
    result = this->gameBoard.goodCells(coordinates);
    correctResult = true;
    assert(result == correctResult);

    // Test 4 - Same move
    coordinates[0] = std::make_pair(1, 0);
    coordinates[1] = std::make_pair(2, 0);
    coordinates[2] = std::make_pair(2, 1);
    coordinates[3] = std::make_pair(2, 2);
    result = this->gameBoard.goodCells(coordinates);
    correctResult = false;
    assert(result == correctResult);
}



std::pair <unsigned short int, unsigned short int> Test::getOrientation ()
{
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;

    // Test 1 - Horizontal orientation
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 0));
    std::pair <unsigned short int, unsigned short int> result = this->gameBoard.getOrientation(coordinates);
    std::pair <unsigned short int, unsigned short int> correctResult = std::make_pair(1, 0);
    assert(result == correctResult);

    // Test 2 - Vertical orientation
    coordinates[0] = std::make_pair(0, 2);
    coordinates[1] = std::make_pair(1, 2);
    coordinates[2] = std::make_pair(2, 2);
    coordinates[3] = std::make_pair(2, 3);
    result = this->gameBoard.getOrientation(coordinates);
    correctResult = std::make_pair(2, 2);
    assert(result == correctResult);

    // Test 3 - Neither horizontal, nor vertical orientation
    coordinates[0] = std::make_pair(0, 1);
    coordinates[1] = std::make_pair(1, 0);
    coordinates[2] = std::make_pair(1, 1);
    coordinates[3] = std::make_pair(2, 2);
    result = this->gameBoard.getOrientation(coordinates);
    correctResult = std::make_pair(0, 0);
    assert(result == correctResult);
}



bool Test::hasGap ()
{
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;

    // Test 1 - Has a gap (horizontal orientation)
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 3));
    coordinates.push_back(std::make_pair(1, 0));
    bool result = this->gameBoard.hasGap(coordinates);
    bool correctResult = true;
    assert(result == correctResult);

    // Test 2 - Does not have a gap (horizontal orientation)
    coordinates[0] = std::make_pair(0, 0);
    coordinates[1] = std::make_pair(0, 1);
    coordinates[2] = std::make_pair(0, 2);
    coordinates[3] = std::make_pair(1, 0);
    result = this->gameBoard.hasGap(coordinates);
    correctResult = false;
    assert(result == correctResult);

    // Test 3 - Has a gap (vertical orientation)
    coordinates[0] = std::make_pair(0, 1);
    coordinates[1] = std::make_pair(1, 1);
    coordinates[2] = std::make_pair(3, 1);
    coordinates[3] = std::make_pair(3, 2);
    result = this->gameBoard.hasGap(coordinates);
    correctResult = true;
    assert(result == correctResult);

    // Test 4 - Does not have a gap (vertical orientation)
    coordinates[0] = std::make_pair(0, 1);
    coordinates[1] = std::make_pair(1, 1);
    coordinates[2] = std::make_pair(2, 1);
    coordinates[3] = std::make_pair(2, 2);
    result = this->gameBoard.hasGap(coordinates);
    correctResult = false;
    assert(result == correctResult);
}



std::pair <unsigned short int, unsigned short int> Test::getStartEndPositions ()
{
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;

    // Test 1 - Horizontal orientation
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 2));
    std::pair <unsigned short int, unsigned short int> result = this->gameBoard.getStartEndPositions(coordinates);
    std::pair <unsigned short int, unsigned short int> correctResult = std::make_pair(0, 2);
    assert(result == correctResult);

    // Test 2 - Vertical orientation
    coordinates[0] = std::make_pair(1, 3);
    coordinates[1] = std::make_pair(2, 3);
    coordinates[2] = std::make_pair(3, 3);
    coordinates[3] = std::make_pair(3, 2);
    result = this->gameBoard.getStartEndPositions(coordinates);
    correctResult = std::make_pair(1, 3);
    assert(result == correctResult);
}



bool Test::onValidPosition ()
{
    std::vector < std::pair <unsigned short int, unsigned short int> > coordinates;

    // Test 1 - On a valid position
    coordinates.push_back(std::make_pair(0, 0));
    coordinates.push_back(std::make_pair(0, 1));
    coordinates.push_back(std::make_pair(0, 2));
    coordinates.push_back(std::make_pair(1, 2));
    bool result = this->gameBoard.onValidPosition(coordinates);
    bool correctResult = true;
    assert(result == correctResult);

    // Test 2 - Not on a valid position
    coordinates[0] = std::make_pair(0, 0);
    coordinates[1] = std::make_pair(0, 1);
    coordinates[2] = std::make_pair(0, 2);
    coordinates[3] = std::make_pair(1, 1);
    result = this->gameBoard.onValidPosition(coordinates);
    correctResult = false;
    assert(result == correctResult);
}
