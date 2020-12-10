/**
    The Application Manager layer is responsible with launching the application.
**/

#include "Test.h"
#include "User_Interface.h"
#include "Controller.h"

/**
    This is the implementation for the Application Manager layer.
    The Application Manager layer is responsible with launching the application.
**/

#include "Test.h"
#include "User_Interface.h"
// #include "Controller.h"         // Temporary (Working Area)



int main ()
{
    // Test all the functionalities of the application.
    runTests();

    // Start the application.
    runGUI();

    // Temporary (Working Area)
    // runApplication();

    return 0;
}
