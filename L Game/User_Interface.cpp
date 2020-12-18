/**
    This is the implementation for the User Interface module.
    The module is responsible with the visual side of the application.
**/

#include "User_Interface.h"
#include "Player_Versus_Environment.h"
#include "Player_Versus_Player.h"

#include <graphics.h> // for graphics
#include <Windows.h> // for the mouse cursor position inside the window
#include <cstring> // for the "strcpy" function

const unsigned short int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
const unsigned short int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);



void runGUI ()
{
    // Exclude the C functions for higher speed.
    std::ios::sync_with_stdio(false);

    // Draw the application window.
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    // Draw the main menu's buttons.
    drawMainMenuButtons();

    // Search for a click and see where the user clicked.
    scanMousePosition();

    // Close the application.
    closeApplication();
}



void drawButton (USI left, USI up, USI right, USI down, USI depth, bool drawDetails, USI textXCoordinate, USI textYCoordinate, char text[])
{
    // Draw the button.
    bar3d(left, up, right, down, depth, drawDetails);

    // Set the font characteristics.
    settextstyle(BOLD_FONT, HORIZ_DIR, FONT_SIZE);

    // Write the text.
    outtextxy(textXCoordinate, textYCoordinate, text);
}



void drawMainMenuButtons ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for drawing the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = SCREEN_WIDTH / 2 - distanceFromCenter;
    unsigned short int right = SCREEN_WIDTH / 2 + distanceFromCenter;
    unsigned short int up = 200 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 300 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = SCREEN_WIDTH / 2 - 50;
    unsigned short int textYCoordinate = 250 + SCREEN_HEIGHT - 1080;
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

    // Update the parameters for drawing the "OPTIONS" button.
    up = 800;
    down = 900;
    textYCoordinate += 200;     // ??? Doesn't work.
    strcpy(text, "OPTIONS");

    // Draw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



unsigned short int checkMouseLocation (double xCoordinate, double yCoordinate)
{
    if (xCoordinate >= SCREEN_WIDTH / 2 - 100 && xCoordinate <= SCREEN_WIDTH / 2 + 100)

        // The user clicked on the "START" button.
        if(yCoordinate >= 200 + SCREEN_HEIGHT - 1080 && yCoordinate <= 300 + SCREEN_HEIGHT - 1080)
            return 1;

        // The user clicked on the "RULES" button.
        else if (yCoordinate >= 400 + SCREEN_HEIGHT - 1080 && yCoordinate <= 500 + SCREEN_HEIGHT - 1080)
            return 2;

        // The user clicked on the "EXIT" button.
        else if (yCoordinate >= 600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
            return 3;

        // The user clicked on the "OPTIONS" button.
        else if (yCoordinate >= 800 + SCREEN_HEIGHT - 1080 && yCoordinate <= 900 + SCREEN_HEIGHT - 1080)
            return 4;

    // The user clicked outside the buttons.
    return 0;
}



void hoverStart ()
{
    // Clear the window.
    cleardevice();

    // Get the new parameters for redrawing the "START" button.
    unsigned short int distanceFromCenter = 80;
    unsigned short int left = SCREEN_WIDTH / 2 - distanceFromCenter;
    unsigned short int right = SCREEN_WIDTH / 2 + distanceFromCenter + 40;
    unsigned short int up = 180 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 280 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = SCREEN_WIDTH / 2 - 30;
    unsigned short int textYCoordinate = 230 + SCREEN_HEIGHT - 1080;
    char text[] = "START";

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    distanceFromCenter = 100;
    left = SCREEN_WIDTH / 2 - distanceFromCenter;
    right = SCREEN_WIDTH / 2 + distanceFromCenter;
    up = 400 + SCREEN_HEIGHT - 1080;
    down = 500 + SCREEN_HEIGHT - 1080;
    depth = 25;
    textXCoordinate = SCREEN_WIDTH / 2 - 50;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    up = 600 + SCREEN_HEIGHT - 1080;
    down = 700 + SCREEN_HEIGHT - 1080;
    textXCoordinate += 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "OPTIONS" button.
    up = 800;
    down = 900;
    textYCoordinate += 200;     // ??? Doesn't work.
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void hoverRules ()
{
    // Clear the window.
    cleardevice();

    // Get the new parameters for redrawing the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = SCREEN_WIDTH / 2 - distanceFromCenter;
    unsigned short int right = SCREEN_WIDTH / 2 + distanceFromCenter;
    unsigned short int up = 200 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 300 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = SCREEN_WIDTH / 2 - 50;
    unsigned short int textYCoordinate = 250 + SCREEN_HEIGHT - 1080;
    char text[] = "START";

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    distanceFromCenter = 80;
    left = SCREEN_WIDTH / 2 - distanceFromCenter;
    right = SCREEN_WIDTH / 2 + distanceFromCenter + 40;
    up = 380 + SCREEN_HEIGHT - 1080;
    down = 480 + SCREEN_HEIGHT - 1080;
    depth = 10;
    textXCoordinate = SCREEN_WIDTH / 2 - 30;
    textYCoordinate = 430 + SCREEN_HEIGHT - 1080;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    distanceFromCenter = 100;
    left = SCREEN_WIDTH / 2 - distanceFromCenter;
    right = SCREEN_WIDTH / 2 + distanceFromCenter;
    up = 600 + SCREEN_HEIGHT - 1080;
    down = 700 + SCREEN_HEIGHT - 1080;
    depth = 25;
    textXCoordinate -= 10;
    textYCoordinate = 650 + SCREEN_HEIGHT - 1080;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "OPTIONS" button.
    up = 800;
    down = 900;
    textYCoordinate += 200;     // ??? Doesn't work.
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void hoverExit ()
{
    // Clear the window.
    cleardevice();

    // Get the new parameters for redrawing the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = SCREEN_WIDTH / 2 - distanceFromCenter;
    unsigned short int right = SCREEN_WIDTH / 2 + distanceFromCenter;
    unsigned short int up = 200 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 300 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = SCREEN_WIDTH / 2 - 50;
    unsigned short int textYCoordinate = 250 + SCREEN_HEIGHT - 1080;
    char text[] = "START";

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    up = 400 + SCREEN_HEIGHT - 1080;
    down = 500 + SCREEN_HEIGHT - 1080;
    textYCoordinate = 450 + SCREEN_HEIGHT - 1080;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    distanceFromCenter = 80;
    left = SCREEN_WIDTH / 2 - distanceFromCenter;
    right = SCREEN_WIDTH / 2 + distanceFromCenter + 40;
    up = 580 + SCREEN_HEIGHT - 1080;
    down = 680 + SCREEN_HEIGHT - 1080;
    depth = 10;
    textXCoordinate = SCREEN_WIDTH / 2 - 20;
    textYCoordinate = 630 + SCREEN_HEIGHT - 1080;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "OPTIONS" button.
    distanceFromCenter = 100;
    left = SCREEN_WIDTH / 2 - distanceFromCenter;
    right = SCREEN_WIDTH / 2 + distanceFromCenter;
    up = 800;
    down = 900;
    depth = 25;
    textXCoordinate = SCREEN_WIDTH / 2 - 40;
    textYCoordinate = 850;
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void hoverOptions ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for redrawing the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = SCREEN_WIDTH / 2 - distanceFromCenter;
    unsigned short int right = SCREEN_WIDTH / 2 + distanceFromCenter;
    unsigned short int up = 200 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 300 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = SCREEN_WIDTH / 2 - 50;
    unsigned short int textYCoordinate = 250 + SCREEN_HEIGHT - 1080;
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
    up = 600;
    down = 700;
    textXCoordinate += 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "OPTIONS" button.
    up = 780;
    down = 880;
    left += 20;
    right += 20;
    depth = 10;
    textYCoordinate += 200;     // ??? Doesn't work.
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void hoverBack ()
{
    // Clears the window.
    cleardevice();

    unsigned short horizontalPosition = SCREEN_WIDTH / 2;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100 + SCREEN_HEIGHT - 1080;

    // Write the title.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize);
    outtextxy(horizontalPosition - 200, verticalPosition, "!!!RULES OF THE GAME!!!");

    horizontalPosition -= 50;

    // Write the rules.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
    outtextxy(horizontalPosition - 200, verticalPosition += 150, "The board has 2 'L' shaped objects and 2 coins");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "You can move your 'L' object and, if you wish,");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "you can move at your choice one of the coins on");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "a free position. You have to move your objects");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "in such a way that you block the other player.");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "The player who runs out of moves loses!!!");

    unsigned short int left = horizontalPosition - 80;
    unsigned short int right = horizontalPosition + 120;
    unsigned short int up = 780 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 880 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 20;
    unsigned short int textYCoordinate = 830 + SCREEN_HEIGHT - 1080;
    char text[] = "BACK";

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void hoverSinglePlayer ()
{
    cleardevice();

    unsigned short int horizontalPosition = SCREEN_WIDTH / 2;
    unsigned short int left = horizontalPosition - 150;
    unsigned short int right = horizontalPosition + 250;
    unsigned short int up = horizontalPosition - 600 + SCREEN_HEIGHT - 1080;
    unsigned short int down = horizontalPosition - 500 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 120;
    unsigned short int textYCoordinate = SCREEN_WIDTH / 2 - 550 + SCREEN_HEIGHT - 1080;
    char text[] = "PLAYER vs COMPUTER";

    // Draw the "PLAYER vs COMPUTER" button.
    drawButton(left + 20, up - 20, right + 20, down - 20, depth - 15, drawDetails, textXCoordinate + 20, textYCoordinate - 20, text);

    //Update the values.
    up += 300;
    down += 300;
    textXCoordinate += 20;
    textYCoordinate += 300;
    strcpy(text, "PLAYER vs PLAYER");

    //Draw the "PLAYER vs PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void hoverMultiPlayer ()
{
    cleardevice();

    unsigned short int horizontalPosition = SCREEN_WIDTH / 2;
    unsigned short int left = horizontalPosition - 150;
    unsigned short int right = horizontalPosition + 250;
    unsigned short int up = horizontalPosition - 600 + SCREEN_HEIGHT - 1080;
    unsigned short int down = horizontalPosition - 500 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 120;
    unsigned short int textYCoordinate = SCREEN_WIDTH / 2 - 550 + SCREEN_HEIGHT - 1080;
    char text[] = "PLAYER vs COMPUTER";

    // Draw the "PLAYER vs COMPUTER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    //Update the values.
    up += 280;
    down += 280;
    left += 20;
    right +=20;
    depth = 10;
    textXCoordinate += 40;
    textYCoordinate += 280;
    strcpy(text,"PLAYER vs PLAYER");

    //Draw the "PLAYER vs PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void drawStartPage ()
{
    // Clear the window.
    cleardevice();

    unsigned short int horizontalPosition = SCREEN_WIDTH / 2;
    unsigned short int left = horizontalPosition - 150;
    unsigned short int right = horizontalPosition + 250;
    unsigned short int up = horizontalPosition - 600;
    unsigned short int down = horizontalPosition - 500;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 120;
    unsigned short int textYCoordinate = SCREEN_WIDTH / 2 - 550;
    char text[] = "PLAYER vs COMPUTER";

    // Draw the "SINGLE PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    //Update the values.
    up += 300;
    down += 300;
    textXCoordinate += 20;
    textYCoordinate += 300;
    strcpy(text,"PLAYER vs PLAYER");

    //Draw the "MULTIPLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void drawRulesPage ()
{
    // Clear the screen.
    cleardevice();

    unsigned short horizontalPosition = SCREEN_WIDTH / 2;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100 + SCREEN_HEIGHT - 1080;

    // Write the title.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize);
    outtextxy(horizontalPosition - 200, verticalPosition, "!!!RULES OF THE GAME!!!");

    horizontalPosition -= 50;

    // Write the rules.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
    outtextxy(horizontalPosition - 200, verticalPosition += 150, "The board has 2 'L' shaped objects and 2 coins");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "You can move your 'L' object and, if you wish,");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "you can move at your choice one of the coins on");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "a free position. You have to move your objects");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "in such a way that you block the other player.");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "The player who runs out of moves loses!!!");

    unsigned short int left = horizontalPosition - 100;
    unsigned short int right = horizontalPosition + 100;
    unsigned short int up = 800 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 900 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 40;
    unsigned short int textYCoordinate = 850 + SCREEN_HEIGHT - 1080;
    char text[] = "BACK";

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void drawOptionsPage ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for drawing the "CHANGE LANGUAGE" button.
    unsigned short int distanceFromCenter = 200;
    unsigned short int left = SCREEN_WIDTH / 2 - distanceFromCenter;
    unsigned short int right = SCREEN_WIDTH / 2 + distanceFromCenter;
    unsigned short int up = 200;
    unsigned short int down = 300;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = left + 20;
    unsigned short int textYCoordinate = up + 50;
    char text[] = "CHANGE LANGUAGE";

    // Draw the "CHANGE LANGUAGE" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for drawing the "TURN MUSIC ON/OFF" button.
    up = 400;
    down = 500;
    textYCoordinate = up + 50;
    strcpy(text, "TURN MUSIC ON/OFF");

    // Draw the "TURN MUSIC ON/OFF" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for drawing the "CHANGE RESOLUTION" button.
    up = 600;
    down = 700;
    textYCoordinate = up + 50;
    strcpy(text, "CHANGE RESOLUTION");

    // Draw the "CHANGE RESOLUTION" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void clickOnStart ()
{
    // Clear the window.
    cleardevice();

    // Draws the "START" page.
    drawStartPage();

    bool onStartPage = true;
    bool changer = false;

    // Horizontal left position for the "RULES" button.
    unsigned short int startPosition = SCREEN_WIDTH / 2;

    while (onStartPage == true)
    {
        HWND hwnd = GetForegroundWindow();  /// ?????
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        // Get the mouse position on the window.
        ScreenToClient(hwnd,&cursorPosition);

        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // First we check if the usScreenToClient(hwnd, &p)er clicked somewhere on the screen, then we check the position.
        // After this, we check if we can apply the hover animation on the button.
        if (GetAsyncKeyState(VK_LBUTTON))

            // Check if the click is inside the "SINGLE PLAYER" button.
            if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
                if (yCoordinate >= 300 + SCREEN_HEIGHT - 1080 && yCoordinate <= 400 + SCREEN_HEIGHT - 1080)
                {
                    ///Action if user clicks on Single player
                    onStartPage = false;
                }
                else if(yCoordinate >=600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
                {
                    ///Action if user clicks on Multiplayer
                    onStartPage = false;
                    startMultiplayerGame();
                }

        if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
            if (yCoordinate >= 300 + SCREEN_HEIGHT - 1080 && yCoordinate <= 400 + SCREEN_HEIGHT - 1080)
            {
                 if (changer == false)
                 {
                    changer = true;
                    cleardevice();
                    hoverSinglePlayer();
                 }
            }
            else if(yCoordinate >= 600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
            {
                if(changer == false)
                {
                    changer = true;
                    cleardevice();
                    hoverMultiPlayer();
                }
            }
            else
            {
                if (changer == true)
                {
                    changer = false;
                    drawStartPage();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawStartPage();
        }
    }

    // Redraw the main window.
    drawMainMenuButtons();

    // Look for the mouse position.
    scanMousePosition();
}



void clickOnRules ()
{
    // Clears the screen.
    cleardevice();

    // Draws the "RULES" page.
    drawRulesPage();

    bool onRulesPage = true;
    bool changer = false;

    // Horizontal left position for the "RULES" button.
    unsigned short int startPosition = SCREEN_WIDTH / 2;

    while (onRulesPage == true)
    {
        HWND hwnd = GetForegroundWindow();
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        // Get the mouse position on the window.
        ScreenToClient(hwnd,&cursorPosition);

        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // First we check if the usScreenToClient(hwnd, &p)er clicked somewhere on the screen, then we check the position.
        // After this, we check if we can apply the hover animation on the button.
        if (GetAsyncKeyState(VK_LBUTTON))

            // Check if the click is inside the "BACK" button.
            if (xCoordinate >= startPosition  - 100 && xCoordinate <= startPosition + 100)
                if (yCoordinate >= 800 + SCREEN_HEIGHT - 1080 && yCoordinate <= 900 + SCREEN_HEIGHT - 1080)
                {
                    xCoordinate = cursorPosition.x;
                    yCoordinate = cursorPosition.y;
                    onRulesPage = false;
                }

        if (xCoordinate >= startPosition - 100 && xCoordinate <= startPosition + 100)
            if (yCoordinate >= 800 + SCREEN_HEIGHT - 1080 && yCoordinate <= 900 + SCREEN_HEIGHT - 1080)
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



void clickOnOptions ()
{
    // Clear the window.
    cleardevice();

    // Draws the "OPTIONS" page.
    drawOptionsPage();

    bool onOptionsPage = true;
    bool changer = false;

    // Horizontal left position for the "OPTIONS" button.
    unsigned short int startPosition = SCREEN_WIDTH / 2;

    while (onOptionsPage == true)
    {
        HWND hwnd = GetForegroundWindow();  /// ?????
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);

        // Get the mouse position on the window.
        ScreenToClient(hwnd, &cursorPosition);

        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // First we check if the usScreenToClient(hwnd, &p)er clicked somewhere on the screen, then we check the position.
        // After this, we check if we can apply the hover animation on the button.
        if (GetAsyncKeyState(VK_LBUTTON))
            if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)

                // Do if the click is inside the "CHANGE LANGUAGE" button.
                if (yCoordinate >= 300 + SCREEN_HEIGHT - 1080 && yCoordinate <= 400 + SCREEN_HEIGHT - 1080)
                    onOptionsPage = false;

                // Do if the click is inside the "TURN MUSIC ON/OFF" button.
                else if(yCoordinate >=600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
                    onOptionsPage = false;

                // Do if the click is inside the "CHANGE RESOLUTION" button.
                else if(yCoordinate >=600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
                    onOptionsPage = false;

        // HOVER
        if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
            if (yCoordinate >= 300 + SCREEN_HEIGHT - 1080 && yCoordinate <= 400 + SCREEN_HEIGHT - 1080)
            {
                 if (changer == false)
                 {
                    changer = true;
                    cleardevice();
                    // hoverSinglePlayer();
                 }
            }
            else if(yCoordinate >= 600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
            {
                if(changer == false)
                {
                    changer = true;
                    cleardevice();
                    // hoverMultiPlayer();
                }
            }
            else
            {
                if (changer == true)
                {
                    changer = false;
                    drawOptionsPage();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawOptionsPage();
        }
    }

    // Redraw the main window.
    drawMainMenuButtons();

    // Look for the mouse position.
    scanMousePosition();
}



void scanMousePosition ()
{
    HWND hwnd = GetForegroundWindow();
    POINT cursorPosition;
    bool buttonPressed = false;
    bool changer = false;

    while (buttonPressed == false)
    {
        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        // Get the mouse position on the screen.
        ScreenToClient(hwnd,&cursorPosition);
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

            // The "OPTIONS" button
            case 4:
                if (changer == false)
                    hoverOptions();
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
                    clickOnStart();
                    break;

                // The "RULES" button
                case 2:
                    buttonPressed = true;
                    clickOnRules();
                    break;

                // The "EXIT" button
                case 3:
                    exit(0);

                // The "OPTIONS" button
                case 4:
                    buttonPressed = true;
                    clickOnOptions();
                    break;
            }
        }

        // Wait 30 milliseconds for performance reasons. (we don t want to scan the mouse position every millisecond)
        delay(30);
    }
}



void closeApplication ()
{
    closegraph();
    getch();
}
