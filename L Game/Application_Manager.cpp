/**
    The Application Manager layer is responsible with launching the application.
**/

#include "Test.h"
#include "User_Interface.h"
#include "Controller.h"



int main ()
{
    // Test all the functionalities of the application.
    runTests();

    // Start the application.
    runGUI();

    // Temporary
    // runApplication();

    return 0;
}
