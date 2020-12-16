/**
    This is the implementation for the Application Manager layer.
    The Application Manager layer is responsible with launching the application.
**/

#include "Test.h"
#include "User_Interface.h"



int main ()
{
    // Test the application.
    runTests();

    // Start the application.
    runGUI();

    return 0;
}
