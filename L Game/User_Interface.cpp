/**
    This is the implementation for the User Interface module.
    The module is responsible with the visual side of the application.
**/

#include "User_Interface.h"
#include "Player_Versus_Environment.h"
#include "Player_Versus_Player.h"

#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <cstring>
#include <iostream>

const unsigned short int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
const unsigned short int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);


void UserInterface::startGUI ()
{
    // Exclude the C functions for higher speed.
    std::ios::sync_with_stdio(false);

    // Draw the application window.
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    this->playMusic();
    this->drawMainMenu();
    this->scanMouseLocationMainMenu();
}


void UserInterface::playMusic ()
{
    // mciSendString("play Kahoot_Soundtrack.mp3 repeat", NULL, 0, NULL);
}


void UserInterface::drawMainMenu ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for drawing the "Play" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 84;
    unsigned short int right = SCREEN_WIDTH / 2 + 84;
    unsigned short int up = 200;
    unsigned short int down = 300;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int horizontalPosition = left + 22;
    unsigned short int verticalPosition = 225;
    char text[30] = "Play";

    // Draw the "Play" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Options" button.
    left = SCREEN_WIDTH / 2 - 130;
    right = SCREEN_WIDTH / 2 + 130;
    up = 400;
    down = 500;
    horizontalPosition = left + 22;
    verticalPosition = 425;
    strcpy(text, "Options");

    // Draw the "Options" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Rules" button.
    left = SCREEN_WIDTH / 2 - 100;
    right = SCREEN_WIDTH / 2 + 100;
    up = 600;
    down = 700;
    horizontalPosition = left + 22;
    verticalPosition = 625;
    strcpy(text, "Rules");

    // Draw the "Rules" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Exit" button.
    left = SCREEN_WIDTH / 2 - 84;
    right = SCREEN_WIDTH / 2 + 84;
    up = 800;
    down = 900;
    horizontalPosition = left + 22;
    verticalPosition = 825;
    strcpy(text, "Exit");

    // Draw the "Exit" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);
}



void UserInterface::drawStartGameMenu ()
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

    // Draw the "PLAYER vs COMPUTER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the values for the "PLAYER vs PLAYER" button.
    up += 300;
    down += 300;
    textXCoordinate += 20;
    textYCoordinate += 300;
    strcpy(text, "PLAYER vs PLAYER");

    //Draw the "PLAYER vs PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the values for the "BACK" button.
    left += 700;
    right += 500;
    up -= 150;
    down -= 150;
    textXCoordinate += 700;
    textYCoordinate -= 150;
    strcpy(text, "BACK");

    //Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void UserInterface::drawRulesScreen ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 170;
    unsigned short int verticalPosition = 100;
    char text[] = "GAME RULES";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for writing the rules.
    fontSize = 4;
    horizontalPosition = SCREEN_WIDTH / 2 - 550;
    verticalPosition = 300;

    // Write the rules.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, "The game board  has  2 'L' shaped objects  and  2 coins.");
    outtextxy(horizontalPosition, verticalPosition += 60, "You can  move  your 'L' object and, if you wish, you can");
    outtextxy(horizontalPosition, verticalPosition += 60, "also  move  one  of  the  coins  on a free position. You");
    outtextxy(horizontalPosition, verticalPosition += 60, "have  to move  your  objects  in  such  a  way  that you");
    outtextxy(horizontalPosition, verticalPosition += 60, "block  the  other player.  When  a player can't move his");
    outtextxy(horizontalPosition, verticalPosition += 60, "or her 'L' object, the other player wins. The red player");
    outtextxy(horizontalPosition, verticalPosition += 60, "is the first one.");

    // Get the necessary parameters for drawing the "Back" button.
    unsigned short int leftMargin = SCREEN_WIDTH / 2 - 100;
    unsigned short int rightMargin = SCREEN_WIDTH / 2 + 100;
    unsigned short int upperMargin = 850;
    unsigned short int downMargin = 950;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    horizontalPosition = leftMargin + 38;
    verticalPosition = 875;
    strcpy(text, "Back");

    // Draw the "Back" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);
}


void UserInterface::drawOptionsMenu ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 125;
    unsigned short int verticalPosition = 100;
    char text[] = "OPTIONS";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Music" button.
    unsigned short int leftMargin = SCREEN_WIDTH / 2 - 100;
    unsigned short int rightMargin = SCREEN_WIDTH / 2 + 100;
    unsigned short int upperMargin = 250;
    unsigned short int downMargin = 350;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    horizontalPosition = leftMargin + 25;
    verticalPosition = 275;
    strcpy(text, "Music");

    // Draw the "Music" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Language" button.
    leftMargin = SCREEN_WIDTH / 2 - 145;
    rightMargin = SCREEN_WIDTH / 2 + 145;
    upperMargin = 450;
    downMargin = 550;
    horizontalPosition = leftMargin + 21;
    verticalPosition = 475;
    strcpy(text, "Language");

    // Draw the "Language" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Resolution" button.
    leftMargin = SCREEN_WIDTH / 2 - 175;
    rightMargin = SCREEN_WIDTH / 2 + 175;
    upperMargin = 650;
    downMargin = 750;
    horizontalPosition = leftMargin + 20;
    verticalPosition = 675;
    strcpy(text, "Resolution");

    // Draw the "Resolution" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Back" button.
    leftMargin = SCREEN_WIDTH / 2 - 83;
    rightMargin = SCREEN_WIDTH / 2 + 83;
    upperMargin = 850;
    downMargin = 950;
    horizontalPosition = leftMargin + 22;
    verticalPosition = 875;
    strcpy(text, "Back");

    // Draw the "Back" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);
}


void UserInterface::drawButton (USI leftMargin, USI upperMargin, USI rightMargin, USI downMargin, USI depth, bool drawDetails, USI horizontalPosition, USI verticalPosition, char text[])
{
    // Set the style of the button.
    unsigned short int pattern = SOLID_FILL;
    unsigned short int colour = RED;
    setfillstyle(pattern, colour);

    // Draw the button.
    bar3d(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails);

    // Set the style of the text for the button.
    unsigned short int fontStyle = BOLD_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 6;
    settextstyle(fontStyle, fontDirection, fontSize);
    setcolor(LIGHTBLUE);

    // Write the text of the button.
    outtextxy(horizontalPosition, verticalPosition, text);

    // Come back to the default colour.
    setcolor(WHITE);
}



void UserInterface::hoverStartGame ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for drawing the "Play" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 64;
    unsigned short int right = SCREEN_WIDTH / 2 + 104;
    unsigned short int up = 180;
    unsigned short int down = 280;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int horizontalPosition = left + 22;
    unsigned short int verticalPosition = 205;
    char text[30] = "Play";

    // Draw the "Play" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Options" button.
    depth = 25;
    left = SCREEN_WIDTH / 2 - 130;
    right = SCREEN_WIDTH / 2 + 130;
    up = 400;
    down = 500;
    horizontalPosition = left + 22;
    verticalPosition = 425;
    strcpy(text, "Options");

    // Draw the "Options" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Rules" button.
    left = SCREEN_WIDTH / 2 - 100;
    right = SCREEN_WIDTH / 2 + 100;
    up = 600;
    down = 700;
    horizontalPosition = left + 22;
    verticalPosition = 625;
    strcpy(text, "Rules");

    // Draw the "Rules" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Exit" button.
    left = SCREEN_WIDTH / 2 - 84;
    right = SCREEN_WIDTH / 2 + 84;
    up = 800;
    down = 900;
    horizontalPosition = left + 22;
    verticalPosition = 825;
    strcpy(text, "Exit");

    // Draw the "Exit" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);
}


void UserInterface::hoverOptions ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for drawing the "Play" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 84;
    unsigned short int right = SCREEN_WIDTH / 2 + 84;
    unsigned short int up = 200;
    unsigned short int down = 300;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int horizontalPosition = left + 22;
    unsigned short int verticalPosition = 225;
    char text[30] = "Play";

    // Draw the "Play" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Options" button.
    left = SCREEN_WIDTH / 2 - 110;
    right = SCREEN_WIDTH / 2 + 150;
    up = 380;
    down = 480;
    depth = 10;
    horizontalPosition = left + 22;
    verticalPosition = 405;
    strcpy(text, "Options");

    // Draw the "Options" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Rules" button.
    left = SCREEN_WIDTH / 2 - 100;
    right = SCREEN_WIDTH / 2 + 100;
    up = 600;
    down = 700;
    depth = 25;
    horizontalPosition = left + 22;
    verticalPosition = 625;
    strcpy(text, "Rules");

    // Draw the "Rules" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Exit" button.
    left = SCREEN_WIDTH / 2 - 84;
    right = SCREEN_WIDTH / 2 + 84;
    up = 800;
    down = 900;
    horizontalPosition = left + 22;
    verticalPosition = 825;
    strcpy(text, "Exit");

    // Draw the "Exit" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);
}


void UserInterface::hoverRules ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for drawing the "Play" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 84;
    unsigned short int right = SCREEN_WIDTH / 2 + 84;
    unsigned short int up = 200;
    unsigned short int down = 300;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int horizontalPosition = left + 22;
    unsigned short int verticalPosition = 225;
    char text[30] = "Play";

    // Draw the "Play" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Options" button.
    left = SCREEN_WIDTH / 2 - 130;
    right = SCREEN_WIDTH / 2 + 130;
    up = 400;
    down = 500;
    horizontalPosition = left + 22;
    verticalPosition = 425;
    strcpy(text, "Options");

    // Draw the "Options" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Rules" button.
    left = SCREEN_WIDTH / 2 - 80;
    right = SCREEN_WIDTH / 2 + 120;
    up = 580;
    down = 680;
    depth = 10;
    horizontalPosition = left + 22;
    verticalPosition = 605;
    strcpy(text, "Rules");

    // Draw the "Rules" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Exit" button.
    left = SCREEN_WIDTH / 2 - 84;
    right = SCREEN_WIDTH / 2 + 84;
    up = 800;
    down = 900;
    depth = 25;
    horizontalPosition = left + 22;
    verticalPosition = 825;
    strcpy(text, "Exit");

    // Draw the "Exit" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);
}



void UserInterface::hoverExit ()
{
    // Clear the window.
    cleardevice();

    // Get the parameters for drawing the "Play" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 84;
    unsigned short int right = SCREEN_WIDTH / 2 + 84;
    unsigned short int up = 200;
    unsigned short int down = 300;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int horizontalPosition = left + 22;
    unsigned short int verticalPosition = 225;
    char text[30] = "Play";

    // Draw the "Play" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Options" button.
    left = SCREEN_WIDTH / 2 - 130;
    right = SCREEN_WIDTH / 2 + 130;
    up = 400;
    down = 500;
    horizontalPosition = left + 22;
    verticalPosition = 425;
    strcpy(text, "Options");

    // Draw the "Options" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Rules" button.
    left = SCREEN_WIDTH / 2 - 100;
    right = SCREEN_WIDTH / 2 + 100;
    up = 600;
    down = 700;
    horizontalPosition = left + 22;
    verticalPosition = 625;
    strcpy(text, "Rules");

    // Draw the "Rules" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the parameters for drawing the "Exit" button.
    left = SCREEN_WIDTH / 2 - 64;
    right = SCREEN_WIDTH / 2 + 104;
    up = 780;
    down = 880;
    depth = 10;
    horizontalPosition = left + 22;
    verticalPosition = 805;
    strcpy(text, "Exit");

    // Draw the "Exit" button.
    drawButton(left, up, right, down, depth, drawDetails, horizontalPosition, verticalPosition, text);
}


void UserInterface::hoverBackRules ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 170;
    unsigned short int verticalPosition = 100;
    char text[] = "GAME RULES";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for writing the rules.
    fontSize = 4;
    horizontalPosition = SCREEN_WIDTH / 2 - 550;
    verticalPosition = 300;

    // Write the rules.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, "The game board  has  2 'L' shaped objects  and  2 coins.");
    outtextxy(horizontalPosition, verticalPosition += 60, "You can  move  your 'L' object and, if you wish, you can");
    outtextxy(horizontalPosition, verticalPosition += 60, "also  move  one  of  the  coins  on a free position. You");
    outtextxy(horizontalPosition, verticalPosition += 60, "have  to move  your  objects  in  such  a  way  that you");
    outtextxy(horizontalPosition, verticalPosition += 60, "block  the  other player.  When  a player can't move his");
    outtextxy(horizontalPosition, verticalPosition += 60, "or her 'L' object, the other player wins. The red player");
    outtextxy(horizontalPosition, verticalPosition += 60, "is the first one.");

    // Get the necessary parameters for drawing the "Back" button.
    unsigned short int leftMargin = SCREEN_WIDTH / 2 - 80;
    unsigned short int rightMargin = SCREEN_WIDTH / 2 + 120;
    unsigned short int upperMargin = 830;
    unsigned short int downMargin = 930;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    horizontalPosition = leftMargin + 38;
    verticalPosition = 855;
    strcpy(text, "Back");

    // Draw the "Back" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);
}



void UserInterface::hoverPlayerVsComputer ()
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

    // Update the values for the "BACK" button.
    left += 700;
    right += 500;
    up -= 150;
    down -= 150;
    textXCoordinate += 700;
    textYCoordinate -= 150;
    strcpy(text, "BACK");

    //Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void UserInterface::hoverPlayerVsPlayer ()
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

    // Update the values for the "BACK" button.
    left += 700 - 20;
    right += 500 - 20;
    up -= 150 - 20;
    down -= 150 - 20;
    depth += 15;
    textXCoordinate += 700 - 20;
    textYCoordinate -= 150 - 20;
    strcpy(text, "BACK");

    //Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void UserInterface::clickOnStartGame ()
{
    // Clear the window.
    cleardevice();

    // Draws the "START" page.
    drawStartGameMenu();

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

            if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
            {
                if (yCoordinate >= 300 + SCREEN_HEIGHT - 1080 && yCoordinate <= 400 + SCREEN_HEIGHT - 1080)
                {
                    onStartPage = false;
                    PlayerVersusEnvironment playerVersusEnvironment;
                    playerVersusEnvironment.startGame();
                }
                else if (yCoordinate >=600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
                {
                    onStartPage = false;
                    PlayerVersusPlayer playerVersusPlayer;
                    playerVersusPlayer.startGame();
                }
            }
        if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
            if (yCoordinate >= 300 + SCREEN_HEIGHT - 1080 && yCoordinate <= 400 + SCREEN_HEIGHT - 1080)
            {
                 if (changer == false)
                 {
                    changer = true;
                    cleardevice();
                    hoverPlayerVsComputer();
                 }
            }
            else if(yCoordinate >= 600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
            {
                if(changer == false)
                {
                    changer = true;
                    cleardevice();
                    hoverPlayerVsPlayer();
                }
            }
            else
            {
                if (changer == true)
                {
                    changer = false;
                    drawStartGameMenu();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawStartGameMenu();
        }
    }

    // Redraw the main window.
    drawMainMenu();

    // Look for the mouse position.
    scanMouseLocationMainMenu();
}



void UserInterface::clickOnRules ()
{
    cleardevice();
    this->drawRulesScreen();

    bool onRulesPage = true;
    bool changer = false;

    // The left margin of the "BACK" button.
    unsigned short int leftMargin = SCREEN_WIDTH / 2 - 100;
    unsigned short int rightMargin = SCREEN_WIDTH / 2 + 100;

    while (onRulesPage)
    {
        HWND foregroundWindowHandler = GetForegroundWindow();
        POINT cursorPosition;
        GetCursorPos(&cursorPosition);
        ScreenToClient(foregroundWindowHandler, &cursorPosition);
        double horizontalPosition = cursorPosition.x;
        double verticalPosition = cursorPosition.y;

        // Check if the click is inside the "BACK" button.
        if (GetAsyncKeyState(VK_LBUTTON))
            if (horizontalPosition >= leftMargin && horizontalPosition <= rightMargin)
                if (verticalPosition >= 800 && verticalPosition <= 900)
                    onRulesPage = false;

        if (horizontalPosition >= leftMargin && horizontalPosition <= rightMargin)
            if (verticalPosition >= 800 && verticalPosition <= 900)
            {
                 if (changer == false)
                 {
                    changer = true;
                    cleardevice();
                    hoverBackRules();
                 }
            }
            else
            {
                if (changer == true)
                {
                    changer = false;
                    drawRulesScreen();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawRulesScreen();
        }
    }

    cleardevice();
    this->drawMainMenu();
    this->scanMouseLocationMainMenu();
}



void UserInterface::clickOnOptions ()
{
    // Clear the window.
    cleardevice();

    // Draws the "OPTIONS" page.
    drawOptionsMenu();

    bool onOptionsPage = true;

    // Horizontal left position for the "OPTIONS" button.
    unsigned short int startPosition = SCREEN_WIDTH / 2 - 200;
    unsigned short int endPosition = SCREEN_WIDTH / 2 + 200;

    while (onOptionsPage == true)
    {
        HWND hwnd = GetForegroundWindow();  // a pointer to the open window
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);

        // Get the mouse position on the window.
        ScreenToClient(hwnd, &cursorPosition);

        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        if (GetAsyncKeyState(VK_LBUTTON))
            if (xCoordinate >= startPosition && xCoordinate <= endPosition)
            {
                // Do if the click is inside the "CHANGE LANGUAGE" button.
                if (yCoordinate >= 400 && yCoordinate <= 500)
                    onOptionsPage = false;

                // Do if the click is inside the "TURN MUSIC ON/OFF" button.
                else if (yCoordinate >= 600 && yCoordinate <= 700)
                    onOptionsPage = false;

                // Do if the click is inside the "CHANGE RESOLUTION" button.
                else if (yCoordinate >= 800 && yCoordinate <= 900)
                    onOptionsPage = false;
            }
    }

    cleardevice();
    this->drawMainMenu();
    this->scanMouseLocationMainMenu();
}


void UserInterface::scanMouseLocationMainMenu ()
{
    bool hoveredOverButton = false;
    bool buttonPressed = false;

    while (not buttonPressed)
    {
        HWND foregroundWindowHandler = GetForegroundWindow();
        POINT cursorPosition;
        GetCursorPos(&cursorPosition);
        ScreenToClient(foregroundWindowHandler, &cursorPosition);
        double horizontalPosition = cursorPosition.x;
        double verticalPosition = cursorPosition.y;
        unsigned short int button = getMouseLocationMainMenu(horizontalPosition, verticalPosition);

        switch (button)
        {
            // The user hovered over the "Play" button.
            case 1:
                if (hoveredOverButton == false)
                {
                    this->hoverStartGame();
                    hoveredOverButton = true;
                }
                break;

            // The user hovered over the "Options" button.
            case 2:
                if (hoveredOverButton == false)
                {
                    this->hoverOptions();
                    hoveredOverButton = true;
                }
                break;

            // The user hovered over the "Rules" button.
            case 3:
                if (hoveredOverButton == false)
                {
                    this->hoverRules();
                    hoveredOverButton = true;
                }
                break;

            // The user hovered over the "Exit" button.
            case 4:
                if (hoveredOverButton == false)
                {
                    this->hoverExit();
                    hoveredOverButton = true;
                }
                break;

            // The click is outside the buttons.
            default:
                if (hoveredOverButton == true)
                {
                    cleardevice();
                    this->drawMainMenu();
                }
                hoveredOverButton = false;
        }

        if (GetAsyncKeyState(VK_LBUTTON))
            switch (button)
            {
                // The user clicked on the "Play" button.
                case 1:
                    this->clickOnStartGame();
                    buttonPressed = true;
                    break;

                // The user clicked on the "Options" button.
                case 2:
                    this->clickOnOptions();
                    buttonPressed = true;
                    break;

                // The user clicked on the "Rules" button.
                case 3:
                    this->clickOnRules();
                    buttonPressed = true;
                    break;

                // The user clicked on the "Exit" button.
                case 4:
                    this->clickOnExit();
                    buttonPressed = true;
            }
    }
}


unsigned short int UserInterface::getMouseLocationMainMenu (double horizontalCoordinate, double verticalCoordinate)
{
    // The user clicked on the "Play" button.
    if (horizontalCoordinate >= SCREEN_WIDTH / 2 - 84 && horizontalCoordinate <= SCREEN_WIDTH / 2 + 84 &&
        verticalCoordinate >= 200 && verticalCoordinate <= 300)
        return 1;

    // The user clicked on the "Options" button.
    if (horizontalCoordinate >= SCREEN_WIDTH / 2 - 130 && horizontalCoordinate <= SCREEN_WIDTH / 2 + 130 &&
        verticalCoordinate >= 400 && verticalCoordinate <= 500)
        return 2;

    // The user clicked on the "Rules" button.
    if (horizontalCoordinate >= SCREEN_WIDTH / 2 - 100 && horizontalCoordinate <= SCREEN_WIDTH / 2 + 100 &&
        verticalCoordinate >= 600 && verticalCoordinate <= 700)
        return 3;

    // The user clicked on the "Exit" button.
    if (horizontalCoordinate >= SCREEN_WIDTH / 2 - 84 && horizontalCoordinate <= SCREEN_WIDTH / 2 + 84 &&
        verticalCoordinate >= 800 && verticalCoordinate <= 900)
        return 4;

    // The user clicked outside the buttons.
    return 0;
}


void UserInterface::clickOnExit ()
{
    exit(0);
    closegraph();
    getch();
}
