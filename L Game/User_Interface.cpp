#include "User_Interface.h"



/**
    Start the graphical user interface.
**/
void runGUI ()
{
    // Exclude the C functions for higher speed.
    std::ios::sync_with_stdio(false);

    // Draw the window.
    initwindow(WINDOW_SIZE, WINDOW_SIZE);

    // Draw the main menu's buttons.
    drawMainMenuButtons();

    // Search for a click and see where the user clicked.
    scanMousePosition();

    // Close the application.
    closeApplication();
}



/**
    Draws a button.
    Input:
        - "left": the left margin of the button
        - "up": the up margin of the button
        - "right": the right margin of the button
        - "down": the down margin of the button
        - "depth": the depth of the button
        - "drawDetails": specifies if it should draw more details
        - "textXCoordinate": the starting X position of the text
        - "textYCoordinate": the starting Y position of the text
        - "text": the text of the button
    Output:
        - draws a button on the screen
**/
void drawButton (USI left, USI up, USI right, USI down, USI depth, bool drawDetails, USI textXCoordinate, USI textYCoordinate, char text[])
{
    // Draw the button.
    bar3d(left, up, right, down, depth, drawDetails);

    // Set font characteristics.
    settextstyle(BOLD_FONT, HORIZ_DIR, FONT_SIZE);

    // Write the text.
    outtextxy(textXCoordinate, textYCoordinate, text);
}



/**
    Draws the buttons of the main menu on the screen.
    Input:
        - none
    Output:
        - draws the buttons of the main menu on the screen
**/
void drawMainMenuButtons ()
{
    // Get the parameters for the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = WINDOW_SIZE / 2 - distanceFromCenter;
    unsigned short int right = WINDOW_SIZE / 2 + distanceFromCenter;
    unsigned short int up = 200;
    unsigned short int down = 300;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = WINDOW_SIZE / 2 - 50;
    unsigned short int textYCoordinate = 250;
    char text[] = "START";

    // Draw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for the "RULES" button.
    up = 400;
    down = 500;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Draw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for the "EXIT" button.
    up = 600;
    down = 700;
    textXCoordinate += 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Draw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Determines where the user clicked on the screen.
    Input:
        - "xCoordinate": the x coordinate for the click
        - "yCoordinate": the y coordinate for the click
    Output:
        - 0: the user clicked outside the buttons
        - 1: the user clicked on "START"
        - 2: the user clicked on "RULES"
        - 3: the user clicked on "EXIT"
*/
unsigned short int checkMouseLocation (double xCoordinate, double yCoordinate)
{
    if (xCoordinate >= 400 && xCoordinate <= 600)

        // The user clicked on the "START" button.
        if(yCoordinate >= 200 && yCoordinate <= 300)
            return 1;

        // The user clicked on the "RULES" button.
        else if (yCoordinate >= 400 && yCoordinate <= 500)
            return 2;

        // The user clicked on the "EXIT" button.
        else if (yCoordinate >= 600 && yCoordinate <= 700)
            return 3;

    // The user clicked outside the buttons.
    return 0;
}



/**
    Redraws the "START" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws all the buttons with the hover effect on them
**/
void hoverStart ()
{
    // Clear the screen.
    cleardevice();

    // Get the new parameters for the "START" button.
    unsigned short int distanceFromCenter = 80;
    unsigned short int left = WINDOW_SIZE / 2 - distanceFromCenter;
    unsigned short int right = WINDOW_SIZE / 2 + distanceFromCenter + 40;
    unsigned short int up = 180;
    unsigned short int down = 280;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = WINDOW_SIZE / 2 - 30;
    unsigned short int textYCoordinate = 230;
    char text[] = "START";

    // Draw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for the "RULES" button.
    distanceFromCenter = 100;
    left = WINDOW_SIZE / 2 - distanceFromCenter;
    right = WINDOW_SIZE / 2 + distanceFromCenter;
    up = 400;
    down = 500;
    depth = 25;
    textXCoordinate = WINDOW_SIZE / 2 - 50;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Draw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for the "EXIT" button.
    up = 600;
    down = 700;
    textXCoordinate += 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Draw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Permanently scans the mouse position.
    Input:
        - none
    Output:
        - none
**/
void scanMousePosition ()
{
    POINT cursorPosition;
    bool buttonPressed = false;
    bool changer = false;

    while (buttonPressed == false)
    {
        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // Check if the click is on a button.
        unsigned short int button = checkMouseLocation(xCoordinate, yCoordinate);

        switch (button)
        {
            // The "START" button
            case 1:
                if (changer == false)
                    hoverStart();
                changer = true;
                break;

            // The "RULES" button
            case 2:
                if (changer == false)
                {
                    // To Add
                    // * hoverRules *
                }
                changer = true;
                break;

            // The "EXIT" button
            case 3:
                if (changer == false)
                {
                    // To Add
                    // * hoverExit *
                }
                changer = true;
                break;

            // The click is outside the buttons.
            default:
                if (changer == true)
                {
                    cleardevice();
                    drawMainMenuButtons();
                }
                changer = false;
        }

        // If you pressed left click
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            // Get the position of the cursor.
            int button = checkMouseLocation(xCoordinate, yCoordinate);

            switch (button)
            {
                // The "START" button
                case 1:
                    system("pause");
                    break;

                // The "RULES" button
                case 2:
                    system("pause");
                    break;

                // The "EXIT" button
                case 3:
                    system("pause");
                    break;
            }
        }

        // Waits 5 milliseconds.
        delay(5);
    }
}



/**
    Closes the application.
    Input:
        - none
    Output:
        - closes the application
**/
void closeApplication ()
{
    getch();
    closegraph();
}
