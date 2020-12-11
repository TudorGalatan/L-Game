/**
    This is the implementation for the User Interface layer.
    The User Interface layer is responsible with the visual side of the application.
**/

#include "User_Interface.h"



/**
   Runs the graphical user interface.
    Input:
        - none
    Output:
        - none
**/
void runGUI ()
{
    // Exclude the C functions for higher speed.
    std::ios::sync_with_stdio(false);

    // Draw the application window.
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

    // Set the font characteristics.
    settextstyle(BOLD_FONT, HORIZ_DIR, FONT_SIZE);

    // Write the text.
    outtextxy(textXCoordinate, textYCoordinate, text);
}



/**
    Draws all the buttons of the main menu.
    Input:
        - none
    Output:
        - draws all the buttons of the main menu on the screen
**/
void drawMainMenuButtons ()
{
    cleardevice();

    // Get the parameters for drawing the "START" button.
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

    // Update the parameters for drawing the "RULES" button.
    up = 400;
    down = 500;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Draw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for drawing the "EXIT" button.
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
        - 1: the user clicked on the "START" button
        - 2: the user clicked on the "RULES" button
        - 3: the user clicked on the "EXIT" button
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
        - redraws all the buttons with the hover effect on the "START" button
**/
void hoverStart ()
{
    // Clear the screen.
    cleardevice();

    // Get the new parameters for redrawing the "START" button.
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

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    distanceFromCenter = 100;
    left = WINDOW_SIZE / 2 - distanceFromCenter;
    right = WINDOW_SIZE / 2 + distanceFromCenter;
    up = 400;
    down = 500;
    depth = 25;
    textXCoordinate = WINDOW_SIZE / 2 - 50;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    up = 600;
    down = 700;
    textXCoordinate += 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "RULES" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws all the buttons with the hover effect on the "RULES" button
**/
void hoverRules ()
{
    // Clear the screen.
    cleardevice();

    // Get the new parameters for redrawing the "START" button.
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

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    distanceFromCenter = 80;
    left = WINDOW_SIZE / 2 - distanceFromCenter;
    right = WINDOW_SIZE / 2 + distanceFromCenter + 40;
    up = 380;
    down = 480;
    depth = 10;
    textXCoordinate = WINDOW_SIZE / 2 - 30;
    textYCoordinate = 430;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    distanceFromCenter = 100;
    left = WINDOW_SIZE / 2 - distanceFromCenter;
    right = WINDOW_SIZE / 2 + distanceFromCenter;
    up = 600;
    down = 700;
    depth = 25;
    textXCoordinate -= 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "EXIT" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws all the buttons with the hover effect on the "EXIT" button
**/
void hoverExit ()
{
    // Clear the screen.
    cleardevice();

    // Get the new parameters for redrawing the "START" button.
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

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    up = 400;
    down = 500;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    distanceFromCenter = 80;
    left = WINDOW_SIZE / 2 - distanceFromCenter;
    right = WINDOW_SIZE / 2 + distanceFromCenter + 40;
    up = 580;
    down = 680;
    depth = 10;
    textXCoordinate = WINDOW_SIZE / 2 - 20;
    textYCoordinate = 630;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "BACK" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws the "RULES" page with the hover effect on the "BACK" button
**/
void hoverBack ()
{
    // Clears the screen.
    cleardevice();

    unsigned short horizontalPosition = 200;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100;

    // Write the title.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize);
    outtextxy(horizontalPosition + 50, verticalPosition, "!!!RULES OF THE GAME!!!");

    // Write the rules.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
    outtextxy(horizontalPosition, verticalPosition += 150, "The board has 2 'L' shaped objects and 2 coins");
    outtextxy(horizontalPosition, verticalPosition += 50, "You can move your 'L' object and, if you wish,");
    outtextxy(horizontalPosition, verticalPosition += 50, "you can move at your choice one of the coins on");
    outtextxy(horizontalPosition, verticalPosition += 50, "a free position. You have to move your objects");
    outtextxy(horizontalPosition, verticalPosition += 50, "in such a way that you block the other player.");
    outtextxy(horizontalPosition, verticalPosition += 50, "The player who runs out of moves loses!!!");

    unsigned short int left = horizontalPosition + 220;
    unsigned short int right = horizontalPosition + 370;
    unsigned short int up = 780;
    unsigned short int down = 880;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition + 250;
    unsigned short int textYCoordinate = 830;
    char text[] = "BACK";

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Draws the "RULES" page.
    Input:
        - none
    Output:
        - draws the "RULES" page
**/
void drawRulesPage ()
{
    // Clear the screen.
    cleardevice();

    unsigned short horizontalPosition = 250;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100;

    // Write the title.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize);
    outtextxy(horizontalPosition, verticalPosition, "!!!RULES OF THE GAME!!!");

    horizontalPosition -= 50;

    // Write the rules.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
    outtextxy(horizontalPosition, verticalPosition += 150, "The board has 2 'L' shaped objects and 2 coins");
    outtextxy(horizontalPosition, verticalPosition += 50, "You can move your 'L' object and, if you wish,");
    outtextxy(horizontalPosition, verticalPosition += 50, "you can move at your choice one of the coins on");
    outtextxy(horizontalPosition, verticalPosition += 50, "a free position. You have to move your objects");
    outtextxy(horizontalPosition, verticalPosition += 50, "in such a way that you block the other player.");
    outtextxy(horizontalPosition, verticalPosition += 50, "The player who runs out of moves loses!!!");

    unsigned short int left = horizontalPosition + 200;
    unsigned short int right = horizontalPosition + 350;
    unsigned short int up = 800;
    unsigned short int down = 900;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition + 230;
    unsigned short int textYCoordinate = 850;
    char text[] = "BACK";

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redirects to the "RULES" page.
    Input:
        - none
    Output:
        - redirects to the "RULES" page
**/
void clickOnRules ()
{
    // Clears the screen.
    cleardevice();

    // Draws the "RULES" page.
    drawRulesPage();

    bool onRulesPage = true;
    bool changer = false;

    // Horizontal left position for the "RULES" button.
    unsigned short int startPosition = 400;

    while (onRulesPage == true)
    {
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // First we check if the user clicked somewhere on the screen, then we check the position.
        // After this, we check if we can apply the hover animation on the button.
        if (GetAsyncKeyState(VK_LBUTTON))

            // Check if the click is inside the "BACK" button.
            if (xCoordinate >= startPosition && xCoordinate <= startPosition + 150)
                if (yCoordinate >= 800 && yCoordinate <= 900)
                {
                    xCoordinate = cursorPosition.x;
                    yCoordinate = cursorPosition.y;
                    onRulesPage = false;
                }

        if (xCoordinate >= startPosition && xCoordinate <= startPosition + 150)
            if (yCoordinate >= 800 && yCoordinate <= 900)
            {
                 if (changer == false)
                 {
                    changer = true;
                    cleardevice();
                    hoverBack();
                 }
            }
            else
            {
                if (changer == true)
                {
                    changer = false;
                    drawRulesPage();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawRulesPage();
        }
    }

    // Redraw the main window.
    drawMainMenuButtons();

    // Look for the mouse position.
    scanMousePosition();
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
                    hoverRules();
                changer = true;
                break;

            // The "EXIT" button
            case 3:
                if (changer == false)
                    hoverExit();
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
                    buttonPressed = true;
                    system("pause");
                    break;

                // The "RULES" button
                case 2:
                    buttonPressed = true;
                    clickOnRules();
                    break;

                case 3:
                    buttonPressed = true;
                    closeApplication();
                    system("pause");
                    break;
            }
        }

        // Wait 5 milliseconds for some reason.
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
    closegraph();
    getch();
}
