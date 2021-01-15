/**
    This is the implementation for the Application Manager module.
    The module is responsible with launching the application.
**/

#include "Test.h"
#include "User_Interface.h"


int main ()
{
    Test test;
    UserInterface userInterface;

    // Test the application.
    test.runAll();
    // Start the application.
    userInterface.startGUI();

    return 0;
}
