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
    this->scanMouseLocation();
    this->closeApplication();
}


void UserInterface::playMusic ()
{
    // mciSendString("play Kahoot_Soundtrack.mp3 repeat", NULL, 0, NULL);
}


void UserInterface::drawMainMenu ()
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
    char text[30] = "START";

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
    strcpy(text, "OPTIONS");
    up = 800;
    down = 900;
    textXCoordinate -= 25;
    textYCoordinate = 850;
    // Draw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
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
    char text[30] = "START";

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
    textXCoordinate -= 25;
    textYCoordinate += 200;     // ??? Doesn't work.
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void UserInterface::hoverRules ()
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
    char text[30] = "START";

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
    textXCoordinate -= 25;
    textYCoordinate += 200;     // ??? Doesn't work.
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void UserInterface::hoverExit ()
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
    char text[30] = "START";

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
    textXCoordinate = SCREEN_WIDTH / 2 - 65;
    textYCoordinate = 850;
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



void UserInterface::hoverOptions ()
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
    char text[30] = "START";

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
    textYCoordinate += 180;
    strcpy(text, "OPTIONS");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
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
                /*
                else if (yCoordinate >=600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
                {
                    onStartPage = false;
                    startPlayerVsPlayerGame();
                }
                */
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
    scanMouseLocation();
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
    this->scanMouseLocation();
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
    this->scanMouseLocation();
}



void UserInterface::scanMouseLocation ()
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
        ScreenToClient(hwnd, &cursorPosition);
        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // Check if the click is on a button.
        unsigned short int button = getMouseLocation(xCoordinate, yCoordinate);

        switch (button)
        {
            // The "START" button
            case 1:
                if (changer == false)
                    hoverStartGame();
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
                    drawMainMenu();
                }
                changer = false;
        }

        // If you pressed left click
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            // Get the position of the cursor.
            int button = getMouseLocation(xCoordinate, yCoordinate);

            switch (button)
            {
                // The "START" button
                case 1:
                    buttonPressed = true;
                    clickOnStartGame();
                    break;

                // The "RULES" button
                case 2:
                    buttonPressed = true;
                    clickOnRules();
                    break;

                // The "EXIT" button
                case 3:
                    buttonPressed = true;
                    exit(0);
                    break;

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



unsigned short int UserInterface::getMouseLocation (double xCoordinate, double yCoordinate)
{
    if (xCoordinate >= SCREEN_WIDTH / 2 - 100 && xCoordinate <= SCREEN_WIDTH / 2 + 100)
    {
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
    }
    // The user clicked outside the buttons.
    return 0;
}



void UserInterface::closeApplication ()
{
    closegraph();
    getch();
}
