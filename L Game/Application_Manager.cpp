/**
    This is the implementation for the Application Manager module.
    The module is responsible with launching the application.
**/

#include "Test.h"
#include "User_Interface.h"



int main ()
{
    // Test the application.
    runTests();

    // Start the application.
    startGUI();

    return 0;
}
