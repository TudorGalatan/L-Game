/**
    This is the implementation for the User Interface module.
    The module is responsible with the visual side of the application.
**/

#include "User_Interface.h"
#include "Player_Versus_Environment.h"
#include "Player_Versus_Player.h"

#include <graphics.h>
#include <Windows.h>
#include <cstring>
#include <iostream>
#include <mmsystem.h>

const unsigned short int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
const unsigned short int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);


UserInterface::UserInterface ()
{
    PlayerVersusEnvironment bot;
    this->language = 1;
    this->musicOn = false;
    this->turnMusicOnOff();
}


void UserInterface::startGUI ()
{
    // Exclude the C functions for higher speed.
    std::ios::sync_with_stdio(false);

    // Draw the application window.
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    // Draw the main menu.
    drawMainMenu();

    // Permanently scan the mouse location on the screen.
    scanMouseLocation();

    // Close the application.
    closeApplication();
}


void UserInterface::soundSettings ()
{
    cleardevice();

    bool onMusicScreen = true;

    while (onMusicScreen)
    {
        HWND foregroundWindowHandler = GetForegroundWindow();
        POINT cursorPosition;
        GetCursorPos(&cursorPosition);
        ScreenToClient(foregroundWindowHandler, &cursorPosition);
        double x = cursorPosition.x;
        double y = cursorPosition.y;

        if (GetAsyncKeyState(VK_LBUTTON))
        {
            // The user clicked on the "Turn Music ON/OFF" button.
            if (x >= SCREEN_WIDTH / 2 - 288 && x <= SCREEN_WIDTH / 2 + 288 && y >= SCREEN_HEIGHT / 2 - 500 && y <= SCREEN_HEIGHT / 2 + 300)
                continue;
        }
    }
}


void UserInterface::drawMainMenu ()
{
    this->currentPage = 1;

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
    if(language==1)
        strcpy(text, "RULES");
    else
        strcpy(text, "REGULI");

    // Draw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for drawing the "EXIT" button.
    up = 600;
    down = 700;
    textXCoordinate += 10;
    textYCoordinate = 650;
    if(language == 1)
        strcpy(text, "EXIT");
    else
        strcpy(text, "IESIRE");

    // Draw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for drawing the "OPTIONS" button.
    if(language == 1)
        strcpy(text, "OPTIONS");
    else
        strcpy(text, "OPTIUNI");
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
    char text[30];
    if(language == 1)
        strcpy(text, "PLAYER vs COMPUTER");
    else
        strcpy(text, "JUCATOR vs CALCULATOR");

    // Draw the "PLAYER vs COMPUTER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the values for the "PLAYER vs PLAYER" button.
    up += 300;
    down += 300;
    textXCoordinate += 20;
    textYCoordinate += 300;
    if(language == 1)
        strcpy(text, "PLAYER vs PLAYER");
    else
        strcpy(text, "JUCATOR vs JUCATOR");

    //Draw the "PLAYER vs PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the values for the "BACK" button.
    left += 700;
    right += 500;
    up -= 150;
    down -= 150;
    textXCoordinate += 700;
    textYCoordinate -= 150;
    if(language == 1)
        strcpy(text, "BACK");
    else
        strcpy(text, "INAPOI");

    //Draw the "BACK" button.
    outtextxy(1555, SCREEN_HEIGHT / 2, text);
}


void UserInterface::drawRulesScreen ()
{
    // Clear the screen.
    cleardevice();

    this->currentPage = 0;

    unsigned short horizontalPosition = SCREEN_WIDTH / 2;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100 + SCREEN_HEIGHT - 1080;

    // Write the title.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize);
    if(language == 1)
    {
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
    }
    else
    {
        outtextxy(horizontalPosition - 200, verticalPosition, "!!!REGULILE JOCULUI!!!");

        horizontalPosition -= 50;

        // Write the rules.
        settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
        outtextxy(horizontalPosition - 200, verticalPosition += 150, "Tabla are 2 piese in forma de 'L' si 2 banuti");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "Iti poti muta piesa ta in forma de 'L' si,");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "doar daca vrei, poti muta si unul dintre banuti");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "pe o pozitie libera. Trebuie sa-ti calculezi");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "mutarile astfel incat sa il blochezi pe celalalt.");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "Cel ce ramane fara mutari pierde!!!");
    }
    unsigned short int left = horizontalPosition - 100;
    unsigned short int right = horizontalPosition + 100;
    unsigned short int up = 800 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 900 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 40;
    char text[30];
    unsigned short int textYCoordinate = 850 + SCREEN_HEIGHT - 1080;
    if(language == 1)
        strcpy(text, "BACK");
    else
        strcpy(text, "INAPOI");

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}


void UserInterface::drawOptionsMenu ()
{
    // Clear the window.
    cleardevice();
    // TODO: Add title.
    this->currentPage = 0;
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
    char text[30];
    if(language == 1)
        strcpy(text, "LANGUAGE: ENGLISH");
    else
        strcpy(text, "LIMBA: ROMANA");
    // Draw the "CHANGE LANGUAGE" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate + 50, textYCoordinate, text);

    // Update the parameters for drawing the "TURN MUSIC ON/OFF" button.
    up = 400;
    down = 500;
    textYCoordinate = up + 50;
    if(musicOn == true)
        if(language == 1)
            strcpy(text, "TURN MUSIC OFF");
        else
            strcpy(text, "OPRESTE MUZICA");
    else
        if(language == 1)
            strcpy(text, "TURN MUSIC ON");
        else
            strcpy(text, "PORNESTE MUZICA");

    // Draw the "TURN MUSIC ON/OFF" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate + 50, textYCoordinate, text);

    PlayerVersusEnvironment bot;
    //if(bot.gameMode == 1)
        if(language == 1)
            strcpy(text, "GAMEMODE: EASY");
        else
            strcpy(text, "MOD DE JOC: USOR");
   // else
        if(language == 1)
            strcpy(text, "GAMEMODE: HARD");
        else
            strcpy(text, "MOD DE JOC: GREU");
    up+=200;
    down+=200;
    textYCoordinate+=200;

    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate + 50, textYCoordinate, text);

    right-=100;
    left+=100;
    textXCoordinate += 130;
    textYCoordinate = 850;
    up = 800;
    down = 900;
    if(language == 1)
        strcpy(text,"BACK");
    else
        strcpy(text,"INAPOI");

    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}


void UserInterface::drawButton (USI left, USI up, USI right, USI down, USI depth, bool drawDetails, USI textXCoordinate, USI textYCoordinate, char text[])
{
    setfillstyle(SOLID_FILL,YELLOW);
    // Draw the button.
    bar3d(left, up, right, down, depth, drawDetails);
    // Set the font characteristics.
    settextstyle(BOLD_FONT, HORIZ_DIR, FONT_SIZE);

    // Write the text.
    outtextxy(textXCoordinate, textYCoordinate, text);
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
    if(language == 1)
        strcpy(text, "RULES");
    else
        strcpy(text, "REGULI");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    up = 600 + SCREEN_HEIGHT - 1080;
    down = 700 + SCREEN_HEIGHT - 1080;
    textXCoordinate += 10;
    textYCoordinate = 650;
    if(language == 1)
        strcpy(text, "EXIT");
    else
        strcpy(text, "IESIRE");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "OPTIONS" button.
    up = 800;
    down = 900;
    textXCoordinate -= 25;
    textYCoordinate += 200;
    if(language == 1)
        strcpy(text, "OPTIONS");
    else
        strcpy(text, "OPTIUNI");

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
    if(language == 1)
        strcpy(text, "RULES");
    else
        strcpy(text, "REGULI");

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
    if(language == 1)
        strcpy(text, "EXIT");
    else
        strcpy(text, "IESIRE");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "OPTIONS" button.
    up = 800;
    down = 900;
    textXCoordinate -= 25;
    textYCoordinate += 200;
    if(language == 1)
        strcpy(text, "OPTIONS");
    else
        strcpy(text, "OPTIUNI");

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
    if(language == 1)
        strcpy(text, "RULES");
    else
        strcpy(text, "REGULI");

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
    if(language == 1)
        strcpy(text, "EXIT");
    else
        strcpy(text, "IESIRE");

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
    if(language == 1)
        strcpy(text, "OPTIONS");
    else
        strcpy(text, "OPTIUNI");

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
    if(language == 1)
        strcpy(text, "RULES");
    else
        strcpy(text, "REGULI");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    up = 600;
    down = 700;
    textXCoordinate += 10;
    textYCoordinate = 650;
    if(language == 1)
        strcpy(text, "EXIT");
    else
        strcpy(text, "IESIRE");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "OPTIONS" button.
    up = 780;
    down = 880;
    left += 20;
    right += 20;
    depth = 10;
    textYCoordinate += 180;
    if(language == 1)
        strcpy(text, "OPTIONS");
    else
        strcpy(text, "OPTIUNI");

    // Redraw the "OPTIONS" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}


void UserInterface::hoverBack ()
{
    // Clears the window.
    cleardevice();

    unsigned short horizontalPosition = SCREEN_WIDTH / 2;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100 + SCREEN_HEIGHT - 1080;

    if(language == 1)
    {
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
    }
    else
    {
        outtextxy(horizontalPosition - 200, verticalPosition, "!!!REGULILE JOCULUI!!!");

        horizontalPosition -= 50;

        // Write the rules.
        settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
        outtextxy(horizontalPosition - 200, verticalPosition += 150, "Tabla are 2 piese in forma de 'L' si 2 banuti");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "Iti poti muta piesa ta in forma de 'L' si,");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "doar daca vrei, poti muta si unul dintre banuti");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "pe o pozitie libera. Trebuie sa-ti calculezi");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "mutarile astfel incat sa il blochezi pe celalalt.");
        outtextxy(horizontalPosition - 200, verticalPosition += 50, "Cel ce ramane fara mutari pierde!!!");
    }

    unsigned short int left = horizontalPosition - 80;
    unsigned short int right = horizontalPosition + 120;
    unsigned short int up = 780 + SCREEN_HEIGHT - 1080;
    unsigned short int down = 880 + SCREEN_HEIGHT - 1080;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 20;
    unsigned short int textYCoordinate = 830 + SCREEN_HEIGHT - 1080;
    char text[30];
    if(language == 1)
        strcpy(text,"BACK");
    else
        strcpy(text,"INAPOI");

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
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
    char text[30];
    if(language == 1)
        strcpy(text,"PLAYER vs COMPUTER");
    else
        strcpy(text,"JUCATOR vs CALCULATOR");

    // Draw the "PLAYER vs COMPUTER" button.
    drawButton(left + 20, up - 20, right + 20, down - 20, depth - 15, drawDetails, textXCoordinate + 20, textYCoordinate - 20, text);

    //Update the values.
    up += 300;
    down += 300;
    textXCoordinate += 20;
    textYCoordinate += 300;
    if(language == 1)
        strcpy(text, "PLAYER vs PLAYER");
    else
        strcpy(text, "JUCATOR vs JUCATOR");

    //Draw the "PLAYER vs PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the values for the "BACK" button.
    left += 700;
    right += 500;
    up -= 150;
    down -= 150;
    textXCoordinate += 700;
    textYCoordinate -= 150;
    if(language == 1)
        strcpy(text, "BACK");
    else
        strcpy(text, "INAPOI");

    //Draw the "BACK" button.
    outtextxy(1555, SCREEN_HEIGHT / 2, text);
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
    char text[30];
    if(language == 1)
        strcpy(text, "PLAYER vs COMPUTER");
    else
        strcpy(text, "JUCATOR vs CALCULATOR");

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
    if(language == 1)
        strcpy(text, "PLAYER vs PLAYER");
    else
        strcpy(text, "JUCATOR vs JUCATOR");

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
    if(language == 1)
        strcpy(text, "BACK");
    else
        strcpy(text, "INAPOI");

    //Draw the "BACK" button.
    outtextxy(1555, SCREEN_HEIGHT / 2, text);
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
        {
            if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
            {
                if (yCoordinate >= 300 + SCREEN_HEIGHT - 1080 && yCoordinate <= 400 + SCREEN_HEIGHT - 1080)
                {
                    onStartPage = false;
                    PlayerVersusEnvironment playerVersusEnvironment;
                    playerVersusEnvironment.startGame();
                }
                else if (yCoordinate >= 600 + SCREEN_HEIGHT - 1080 && yCoordinate <= 700 + SCREEN_HEIGHT - 1080)
                {
                    onStartPage = false;
                    PlayerVersusPlayer playerVersusPlayer;
                    playerVersusPlayer.startGame();
                }
            }
            if(xCoordinate>=1500 && xCoordinate<=1700 && yCoordinate <= SCREEN_HEIGHT / 2 + 50 && yCoordinate >= SCREEN_HEIGHT / 2 - 50)
            {
                this->drawMainMenu();
                this->scanMouseLocation();
                return;
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
    scanMouseLocation();
}


void UserInterface::clickOnRules ()
{
    // Clears the screen.
    cleardevice();

    // Draws the "RULES" page.
    drawRulesScreen();

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

        // First we check if the user clicked somewhere on the screen, then we check the position.
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
                    drawRulesScreen();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawRulesScreen();
        }
    }
    delay(150);
    // Redraw the main window.
    drawMainMenu();

    // Look for the mouse position.
    scanMouseLocation();
}


void UserInterface::changeDifficulty()
{
   /** PlayerVersusEnvironment bot;
    if(bot.gameMode == 1)
        bot.gameMode = 2;
    else
        bot.gameMode = 1;*/
}


void UserInterface::clickOnOptions ()
{
    // Clear the window.
    cleardevice();
    // Draws the "OPTIONS" page.
    drawOptionsMenu();

    bool onOptionsPage = true;

    // Horizontal left position for the "OPTIONS" button.
    unsigned short int startPosition = SCREEN_WIDTH / 2;

    while (onOptionsPage == true)
    {
        delay(200);
        HWND hwnd = GetForegroundWindow();  // a pointer to the open window
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
            {
                // Do if the click is inside the "CHANGE LANGUAGE" button.
                if (yCoordinate >= 300 + SCREEN_HEIGHT - 1180 && yCoordinate <= 400 + SCREEN_HEIGHT - 1180)
                {
                    if(language == 1)
                        language = 2;
                    else
                        language = 1;
                    cleardevice();
                    delay(100);
                    drawOptionsMenu();
                }

                // Do if the click is inside the "TURN MUSIC ON/OFF" button.
                else if(yCoordinate >= SCREEN_HEIGHT / 2 - 200 && yCoordinate <= SCREEN_HEIGHT / 2)
                {
                    turnMusicOnOff();
                    cleardevice();
                    drawOptionsMenu();
                    delay(100);
                }
                else if(yCoordinate >= SCREEN_HEIGHT / 2 + 50 && yCoordinate <= SCREEN_HEIGHT / 2 + 150)
                {
                    changeDifficulty();
                    cleardevice();
                    delay(500);
                    drawOptionsMenu();
                    delay(100);
                }
                else if(yCoordinate >= SCREEN_HEIGHT - 300 && yCoordinate <= SCREEN_HEIGHT - 100)
                {
                    onOptionsPage = false;
                    drawMainMenu();
                    scanMouseLocation();
                    delay(100);
                }
            }
    }
}


void UserInterface::turnMusicOnOff()
{
    if (this->musicOn)
    {
        mciSendString("close Kahoot_Soundtrack.mp3", NULL, 0, NULL);
        this->musicOn = false;
    }
    else
    {
        mciSendString("play Kahoot_Soundtrack.mp3 repeat", NULL, 0, NULL);
        this->musicOn = true;
    }
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
        ScreenToClient(hwnd,&cursorPosition);
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
                    this->currentPage = 0;
                    clickOnStartGame();
                    break;

                // The "RULES" button
                case 2:
                    buttonPressed = true;
                    this->currentPage = 0;
                    clickOnRules();
                    break;

                // The "EXIT" button
                case 3:
                    if(this->currentPage == MAIN_PAGE)
                        exit(0);

                // The "OPTIONS" button
                case 4:
                    if(currentPage == MAIN_PAGE)
                    {
                        this->currentPage = 0;
                        buttonPressed = true;
                        cleardevice();
                        clickOnOptions();
                        break;
                    }

            }
        }

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
