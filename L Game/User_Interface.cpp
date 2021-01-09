/**
    This is the implementation for the User Interface module.
    The module is responsible with the visual side of the application.
**/

#pragma comment(lib, "winmm.lib")

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
    this->drawMainScreen();
    this->onMainScreen();
}


void UserInterface::playMusic ()
{
    mciSendString("play Kahoot_Soundtrack.mp3 repeat", NULL, 0, NULL);
}


void UserInterface::drawMainScreen ()
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


void UserInterface::drawPlayScreen ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 65;
    unsigned short int verticalPosition = 100;
    char text[20] = "PLAY";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Player vs Computer" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 300;
    unsigned short int right = SCREEN_WIDTH / 2 + 300;
    unsigned short int up = 350;
    unsigned short int down = 450;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = left + 21;
    unsigned short int textYCoordinate = 375;
    strcpy(text, "Player vs Computer");

    // Draw the "Player vs Computer" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Player vs Player" button.
    left = SCREEN_WIDTH / 2 - 268;
    right = SCREEN_WIDTH / 2 + 268;
    up = 550;
    down = 650;
    textXCoordinate = left + 21;
    textYCoordinate = 575;
    strcpy(text, "Player vs Player");

    //Draw the "Player vs Player" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Back" button.
    left = SCREEN_WIDTH / 2 - 83;
    right = SCREEN_WIDTH / 2 + 83;
    up = 750;
    down = 850;
    textXCoordinate = left + 21;
    textYCoordinate = 775;
    strcpy(text, "Back");

    //Draw the "Back" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}


void UserInterface::drawOptionsScreen ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 125;
    unsigned short int verticalPosition = 100;
    char text[20] = "OPTIONS";

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

    // Get the necessary parameters for drawing the "Difficulty" button.
    leftMargin = SCREEN_WIDTH / 2 - 175;
    rightMargin = SCREEN_WIDTH / 2 + 175;
    upperMargin = 650;
    downMargin = 750;
    horizontalPosition = leftMargin + 20;
    verticalPosition = 675;
    strcpy(text, "Difficulty");

    // Draw the "Difficulty" button.
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
    char text[20] = "GAME RULES";

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


void UserInterface::drawDifficultyScreen ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 125;
    unsigned short int verticalPosition = 100;
    char text[20] = "DIFFICULTY";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Easy" button.
    unsigned short int leftMargin = SCREEN_WIDTH / 2 - 100;
    unsigned short int rightMargin = SCREEN_WIDTH / 2 + 100;
    unsigned short int upperMargin = 250;
    unsigned short int downMargin = 350;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    horizontalPosition = leftMargin + 25;
    verticalPosition = 275;
    strcpy(text, "Easy");

    // Draw the "Easy" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Hard" button.
    leftMargin = SCREEN_WIDTH / 2 - 145;
    rightMargin = SCREEN_WIDTH / 2 + 145;
    upperMargin = 450;
    downMargin = 550;
    horizontalPosition = leftMargin + 21;
    verticalPosition = 475;
    strcpy(text, "Hard");

    // Draw the "Hard" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Legendary" button.
    leftMargin = SCREEN_WIDTH / 2 - 175;
    rightMargin = SCREEN_WIDTH / 2 + 175;
    upperMargin = 650;
    downMargin = 750;
    horizontalPosition = leftMargin + 20;
    verticalPosition = 675;
    strcpy(text, "Legendary");

    // Draw the "Legendary" button.
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


void UserInterface::hoverPlay ()
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


void UserInterface::hoverPlayerVsComputer ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 65;
    unsigned short int verticalPosition = 100;
    char text[20] = "PLAY";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Player vs Computer" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 280;
    unsigned short int right = SCREEN_WIDTH / 2 + 320;
    unsigned short int up = 330;
    unsigned short int down = 430;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = left + 21;
    unsigned short int textYCoordinate = 355;
    strcpy(text, "Player vs Computer");

    // Draw the "Player vs Computer" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Player vs Player" button.
    left = SCREEN_WIDTH / 2 - 268;
    right = SCREEN_WIDTH / 2 + 268;
    up = 550;
    down = 650;
    depth = 25;
    textXCoordinate = left + 21;
    textYCoordinate = 575;
    strcpy(text, "Player vs Player");

    //Draw the "Player vs Player" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Back" button.
    left = SCREEN_WIDTH / 2 - 83;
    right = SCREEN_WIDTH / 2 + 83;
    up = 750;
    down = 850;
    textXCoordinate = left + 21;
    textYCoordinate = 775;
    strcpy(text, "Back");

    //Draw the "Back" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}


void UserInterface::hoverPlayerVsPlayer ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 65;
    unsigned short int verticalPosition = 100;
    char text[20] = "PLAY";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Player vs Computer" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 300;
    unsigned short int right = SCREEN_WIDTH / 2 + 300;
    unsigned short int up = 350;
    unsigned short int down = 450;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = left + 21;
    unsigned short int textYCoordinate = 375;
    strcpy(text, "Player vs Computer");

    // Draw the "Player vs Computer" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Player vs Player" button.
    left = SCREEN_WIDTH / 2 - 248;
    right = SCREEN_WIDTH / 2 + 288;
    up = 530;
    down = 630;
    depth = 10;
    textXCoordinate = left + 21;
    textYCoordinate = 555;
    strcpy(text, "Player vs Player");

    //Draw the "Player vs Player" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Back" button.
    left = SCREEN_WIDTH / 2 - 83;
    right = SCREEN_WIDTH / 2 + 83;
    up = 750;
    down = 850;
    depth = 25;
    textXCoordinate = left + 21;
    textYCoordinate = 775;
    strcpy(text, "Back");

    //Draw the "Back" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}


void UserInterface::hoverBackPlay ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 65;
    unsigned short int verticalPosition = 100;
    char text[20] = "PLAY";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Player vs Computer" button.
    unsigned short int left = SCREEN_WIDTH / 2 - 300;
    unsigned short int right = SCREEN_WIDTH / 2 + 300;
    unsigned short int up = 350;
    unsigned short int down = 450;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = left + 21;
    unsigned short int textYCoordinate = 375;
    strcpy(text, "Player vs Computer");

    // Draw the "Player vs Computer" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Player vs Player" button.
    left = SCREEN_WIDTH / 2 - 268;
    right = SCREEN_WIDTH / 2 + 268;
    up = 550;
    down = 650;
    textXCoordinate = left + 21;
    textYCoordinate = 575;
    strcpy(text, "Player vs Player");

    //Draw the "Player vs Player" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Get the necessary parameters for drawing the "Back" button.
    left = SCREEN_WIDTH / 2 - 63;
    right = SCREEN_WIDTH / 2 + 103;
    up = 730;
    down = 830;
    depth = 10;
    textXCoordinate = left + 21;
    textYCoordinate = 755;
    strcpy(text, "Back");

    //Draw the "Back" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}


void UserInterface::hoverMusic ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 125;
    unsigned short int verticalPosition = 100;
    char text[20] = "OPTIONS";

    // Write the title.
    settextstyle(fontStyle, fontDirection, fontSize);
    outtextxy(horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Music" button.
    unsigned short int leftMargin = SCREEN_WIDTH / 2 - 80;
    unsigned short int rightMargin = SCREEN_WIDTH / 2 + 120;
    unsigned short int upperMargin = 230;
    unsigned short int downMargin = 330;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    horizontalPosition = leftMargin + 25;
    verticalPosition = 255;
    strcpy(text, "Music");

    // Draw the "Music" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Language" button.
    leftMargin = SCREEN_WIDTH / 2 - 145;
    rightMargin = SCREEN_WIDTH / 2 + 145;
    upperMargin = 450;
    downMargin = 550;
    depth = 25;
    horizontalPosition = leftMargin + 21;
    verticalPosition = 475;
    strcpy(text, "Language");

    // Draw the "Language" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Difficulty" button.
    leftMargin = SCREEN_WIDTH / 2 - 175;
    rightMargin = SCREEN_WIDTH / 2 + 175;
    upperMargin = 650;
    downMargin = 750;
    horizontalPosition = leftMargin + 20;
    verticalPosition = 675;
    strcpy(text, "Difficulty");

    // Draw the "Difficulty" button.
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


void UserInterface::hoverLangauge ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 125;
    unsigned short int verticalPosition = 100;
    char text[20] = "OPTIONS";

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
    leftMargin = SCREEN_WIDTH / 2 - 125;
    rightMargin = SCREEN_WIDTH / 2 + 165;
    upperMargin = 430;
    downMargin = 530;
    depth = 10;
    horizontalPosition = leftMargin + 21;
    verticalPosition = 455;
    strcpy(text, "Language");

    // Draw the "Language" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Difficulty" button.
    leftMargin = SCREEN_WIDTH / 2 - 175;
    rightMargin = SCREEN_WIDTH / 2 + 175;
    upperMargin = 650;
    downMargin = 750;
    depth = 25;
    horizontalPosition = leftMargin + 20;
    verticalPosition = 675;
    strcpy(text, "Difficulty");

    // Draw the "Difficulty" button.
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


void UserInterface::hoverDifficulty ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 125;
    unsigned short int verticalPosition = 100;
    char text[20] = "OPTIONS";

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

    // Get the necessary parameters for drawing the "Difficulty" button.
    leftMargin = SCREEN_WIDTH / 2 - 155;
    rightMargin = SCREEN_WIDTH / 2 + 195;
    upperMargin = 630;
    downMargin = 730;
    depth = 10;
    horizontalPosition = leftMargin + 20;
    verticalPosition = 655;
    strcpy(text, "Difficulty");

    // Draw the "Difficulty" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Back" button.
    leftMargin = SCREEN_WIDTH / 2 - 83;
    rightMargin = SCREEN_WIDTH / 2 + 83;
    upperMargin = 850;
    downMargin = 950;
    depth = 25;
    horizontalPosition = leftMargin + 22;
    verticalPosition = 875;
    strcpy(text, "Back");

    // Draw the "Back" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);
}


void UserInterface::hoverBackOptions ()
{
    // Clear the window.
    cleardevice();

    // Get the necessary parameters for writing the title.
    unsigned short int fontStyle = COMPLEX_FONT;
    unsigned short int fontDirection = HORIZ_DIR;
    unsigned short int fontSize = 7;
    unsigned short int horizontalPosition = SCREEN_WIDTH / 2 - 125;
    unsigned short int verticalPosition = 100;
    char text[20] = "OPTIONS";

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

    // Get the necessary parameters for drawing the "Difficulty" button.
    leftMargin = SCREEN_WIDTH / 2 - 175;
    rightMargin = SCREEN_WIDTH / 2 + 175;
    upperMargin = 650;
    downMargin = 750;
    horizontalPosition = leftMargin + 20;
    verticalPosition = 675;
    strcpy(text, "Difficulty");

    // Draw the "Difficulty" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);

    // Get the necessary parameters for drawing the "Back" button.
    leftMargin = SCREEN_WIDTH / 2 - 63;
    rightMargin = SCREEN_WIDTH / 2 + 103;
    upperMargin = 830;
    downMargin = 930;
    depth = 10;
    horizontalPosition = leftMargin + 22;
    verticalPosition = 855;
    strcpy(text, "Back");

    // Draw the "Back" button.
    this->drawButton(leftMargin, upperMargin, rightMargin, downMargin, depth, drawDetails, horizontalPosition, verticalPosition, text);
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


void UserInterface::onMainScreen ()
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
        unsigned short int button = getMouseLocationOnMainScreen(horizontalPosition, verticalPosition);

        switch (button)
        {
            // The user hovered over the "Play" button.
            case 1:
                if (hoveredOverButton == false)
                {
                    this->hoverPlay();
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
                    this->drawMainScreen();
                    hoveredOverButton = false;
                }
        }

        if (GetAsyncKeyState(VK_LBUTTON))
            switch (button)
            {
                // The user clicked on the "Play" button.
                case 1:
                    this->onPlayScreen();
                    buttonPressed = true;
                    break;

                // The user clicked on the "Options" button.
                case 2:
                    this->onOptionsScreen();
                    buttonPressed = true;
                    break;

                // The user clicked on the "Rules" button.
                case 3:
                    this->onRulesScreen();
                    buttonPressed = true;
                    break;

                // The user clicked on the "Exit" button.
                case 4:
                    this->exitGame();
                    buttonPressed = true;
            }
    }
}


void UserInterface::onPlayScreen ()
{
    cleardevice();
    this->drawPlayScreen();

    bool onPlayScreen = true;
    bool hoveredOverButton = false;

    while (onPlayScreen)
    {
        HWND foregroundWindowHandler = GetForegroundWindow();
        POINT cursorPosition;
        GetCursorPos(&cursorPosition);
        ScreenToClient(foregroundWindowHandler, &cursorPosition);
        double horizontalPosition = cursorPosition.x;
        double verticalPosition = cursorPosition.y;

        if (GetAsyncKeyState(VK_LBUTTON))

            // The user clicked on the "Player vs Computer" button.
            if (horizontalPosition >= SCREEN_WIDTH / 2 - 300 && horizontalPosition <= SCREEN_WIDTH / 2 + 300 &&
                verticalPosition >= 350 && verticalPosition <= 450)
            {
                PlayerVersusEnvironment playerVersusEnvironment;
                playerVersusEnvironment.startGame();
                onPlayScreen = false;
            }

            // The user clicked on the "Player vs Player" button.
            else if (horizontalPosition >= SCREEN_WIDTH / 2 - 268 && horizontalPosition <= SCREEN_WIDTH / 2 + 268 &&
                verticalPosition >= 550 && verticalPosition <= 650)
            {
                PlayerVersusPlayer playerVersusPlayer;
                playerVersusPlayer.startGame();
                onPlayScreen = false;
            }

            // The user clicked on the "Back" button.
            else if (horizontalPosition >= SCREEN_WIDTH / 2 - 83 && horizontalPosition <= SCREEN_WIDTH / 2 + 83 &&
                verticalPosition >= 750 && verticalPosition <= 850)
            {
                cleardevice();
                this->drawMainScreen();
                this->onMainScreen();
                onPlayScreen = false;
            }

        // The user hovered over the "Player vs Computer" button.
        if (horizontalPosition >= SCREEN_WIDTH / 2 - 300 && horizontalPosition <= SCREEN_WIDTH / 2 + 300 &&
            verticalPosition >= 350 && verticalPosition <= 450)
        {
             if (hoveredOverButton == false)
             {
                hoveredOverButton = true;
                cleardevice();
                this->hoverPlayerVsComputer();
             }
        }

        // The user hovered over the "Player vs Player" button.
        else if (horizontalPosition >= SCREEN_WIDTH / 2 - 268 && horizontalPosition <= SCREEN_WIDTH / 2 + 268 &&
            verticalPosition >= 550 && verticalPosition <= 650)
        {
            if (hoveredOverButton == false)
            {
                hoveredOverButton = true;
                cleardevice();
                this->hoverPlayerVsPlayer();
            }
        }

        // The user hovered over the "Back" button.
        else if (horizontalPosition >= SCREEN_WIDTH / 2 - 83 && horizontalPosition <= SCREEN_WIDTH / 2 + 83 &&
                verticalPosition >= 750 && verticalPosition <= 850)
        {
            if (hoveredOverButton == false)
            {
                hoveredOverButton = true;
                cleardevice();
                this->hoverBackPlay();
            }
        }

        // The user does not hover over any button anymore.
        else if (hoveredOverButton == true)
        {
            hoveredOverButton = false;
            this->drawPlayScreen();
        }
    }
}


void UserInterface::onOptionsScreen ()
{
    cleardevice();
    this->drawOptionsScreen();

    bool onOptionsScreen = true;
    bool hoveredOverButton = false;

    while (onOptionsScreen)
    {
        HWND foregroundWindowHandler = GetForegroundWindow();
        POINT cursorPosition;
        GetCursorPos(&cursorPosition);
        ScreenToClient(foregroundWindowHandler, &cursorPosition);
        double horizontalPosition = cursorPosition.x;
        double verticalPosition = cursorPosition.y;

        if (GetAsyncKeyState(VK_LBUTTON))

            // The user clicked on the "Music" button.
            if (horizontalPosition >= SCREEN_WIDTH / 2 - 100 && horizontalPosition <= SCREEN_WIDTH / 2 + 100 &&
                verticalPosition >= 250 && verticalPosition <= 350)
                onOptionsScreen = false;

            // The user clicked on the "Language" button.
            else if (horizontalPosition >= SCREEN_WIDTH / 2 - 145 && horizontalPosition <= SCREEN_WIDTH / 2 + 145 &&
                verticalPosition >= 450 && verticalPosition <= 550)
                onOptionsScreen = false;

            // The user clicked on the "Difficulty" button.
            else if (horizontalPosition >= SCREEN_WIDTH / 2 - 175 && horizontalPosition <= SCREEN_WIDTH / 2 + 175 &&
                verticalPosition >= 650 && verticalPosition <= 750)
                {
                    cleardevice();
                    this->drawDifficultyScreen();
                    onOptionsScreen = false;
                }

            // The user clicked on the "Back" button.
            else if (horizontalPosition >= SCREEN_WIDTH / 2 - 83 && horizontalPosition <= SCREEN_WIDTH / 2 + 83 &&
                verticalPosition >= 850 && verticalPosition <= 950)
                {
                    cleardevice();
                    this->drawMainScreen();
                    this->onMainScreen();
                    onOptionsScreen = false;
                }

        // The user hovered over the "Music" button.
        if (horizontalPosition >= SCREEN_WIDTH / 2 - 100 && horizontalPosition <= SCREEN_WIDTH / 2 + 100 &&
            verticalPosition >= 250 && verticalPosition <= 350)
        {
            if (hoveredOverButton == false)
            {
                hoveredOverButton = true;
                cleardevice();
                this->hoverMusic();
            }
        }

        // The user hovered over the "Langauge" button.
        else if (horizontalPosition >= SCREEN_WIDTH / 2 - 145 && horizontalPosition <= SCREEN_WIDTH / 2 + 145 &&
            verticalPosition >= 450 && verticalPosition <= 550)
        {
            if (hoveredOverButton == false)
            {
                hoveredOverButton = true;
                cleardevice();
                this->hoverLangauge();
            }
        }

        // The user hovered over the "Difficulty" button.
        else if (horizontalPosition >= SCREEN_WIDTH / 2 - 175 && horizontalPosition <= SCREEN_WIDTH / 2 + 175 &&
            verticalPosition >= 650 && verticalPosition <= 750)
        {
            if (hoveredOverButton == false)
            {
                hoveredOverButton = true;
                cleardevice();
                this->hoverDifficulty();
            }
        }

        // The user hovered over the "Back" button.
        else if (horizontalPosition >= SCREEN_WIDTH / 2 - 83 && horizontalPosition <= SCREEN_WIDTH / 2 + 83 &&
            verticalPosition >= 850 && verticalPosition <= 950)
        {
            if (hoveredOverButton == false)
            {
                hoveredOverButton = true;
                cleardevice();
                this->hoverBackOptions();
            }
        }

        // The user does not hover over any button anymore.
        else if (hoveredOverButton == true)
        {
            hoveredOverButton = false;
            this->drawOptionsScreen();
        }
    }
}


void UserInterface::onRulesScreen ()
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
    this->drawMainScreen();
    this->onMainScreen();
}


unsigned short int UserInterface::getMouseLocationOnMainScreen (double horizontalPosition, double verticalPosition)
{
    // The user clicked on the "Play" button.
    if (horizontalPosition >= SCREEN_WIDTH / 2 - 84 && horizontalPosition <= SCREEN_WIDTH / 2 + 84 &&
        verticalPosition >= 200 && verticalPosition <= 300)
        return 1;

    // The user clicked on the "Options" button.
    if (horizontalPosition >= SCREEN_WIDTH / 2 - 130 && horizontalPosition <= SCREEN_WIDTH / 2 + 130 &&
        verticalPosition >= 400 && verticalPosition <= 500)
        return 2;

    // The user clicked on the "Rules" button.
    if (horizontalPosition >= SCREEN_WIDTH / 2 - 100 && horizontalPosition <= SCREEN_WIDTH / 2 + 100 &&
        verticalPosition >= 600 && verticalPosition <= 700)
        return 3;

    // The user clicked on the "Exit" button.
    if (horizontalPosition >= SCREEN_WIDTH / 2 - 84 && horizontalPosition <= SCREEN_WIDTH / 2 + 84 &&
        verticalPosition >= 800 && verticalPosition <= 900)
        return 4;

    // The user clicked outside the buttons.
    return 0;
}


void UserInterface::exitGame ()
{
    exit(0);
    closegraph();
    getch();
}
