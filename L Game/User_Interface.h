/**
    This is the interface for the User Interface layer.
    The User Interface layer is responsible with the visual side of the application.
**/

#pragma once

#define USI unsigned short int
#define WINDOW_SIZE 1920
#define FONT_SIZE 4



void runGUI ();
void drawButton (USI left, USI up, USI right, USI down, USI depth, bool drawDetails, USI textXCoordinate, USI textYCoordinate, char text[]);
void drawMainMenuButtons ();
void scanMousePosition ();
void hoverStart ();
void hoverBack ();
void hoverSinglePlayer();
void hoverMultiPlayer();
void drawStartPage ();
void drawRulesPage ();
void clickOnRules ();
unsigned short int checkMouseLocation (double xCoordinate, double yCoordinate);
void drawMainMenuButtons ();
void closeApplication ();
