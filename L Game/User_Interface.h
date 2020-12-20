/**
    This is the interface for the User Interface module.
    The module is responsible with the visual side of the application.
**/

#pragma once

#define USI unsigned short int
#define FONT_SIZE 4



class UserInterface
{
    public:

        /**
            Starts the graphical user interface.
            Input:
                - none
            Output:
                - starts the graphical user interface
        **/
        void startGUI ();

        /**
            Draws the main menu.
            Input:
                - none
            Output:
                - draws the main menu
        **/
        void drawMainMenu ();

        /**
            Draws the "START GAME" menu.
            Input:
                - none
            Output:
                - draws the "START GAME" menu
        **/
        void drawStartGameMenu ();

        /**
            Draws the "RULES" screen.
            Input:
                - none
            Output:
                - draws the "RULES" screen
        **/
        void drawRulesScreen ();

        /**
            Draws the "OPTIONS" menu.
            Input:
                - none
            Output:
                - draws the "OPTIONS" menu
        **/
        void drawOptionsMenu ();

        /**
            Draws a button.
            Input:
                - "left": the left margin of the button
                - "up": the upper margin of the button
                - "right": the right margin of the button
                - "down": the down margin of the button
                - "depth": the depth of the button
                - "drawDetails": specifies if it should draw more details
                - "textXCoordinate": the starting X position of the text
                - "textYCoordinate": the starting Y position of the text
                - "text": the text to be displayed on the button
            Output:
                - draws a button on the screen
        **/
        void drawButton (USI left, USI up, USI right, USI down, USI depth, bool drawDetails, USI textXCoordinate, USI textYCoordinate, char text[]);

        /**
            Redraws the "START" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "START" button with the hover effect on it
        **/
        void hoverStartGame ();

        /**
            Redraws the "RULES" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "RULES" button with the hover effect on it
        **/
        void hoverRules ();

        /**
            Redraws the "EXIT" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "EXIT" button with the hover effect on it
        **/
        void hoverExit ();

        /**
            Redraws the "OPTIONS" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "OPTIONS" button with the hover effect on it
        **/
        void hoverOptions ();

        /**
            Redraws the "BACK" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "BACK" button with the hover effect on it
        **/
        void hoverBack ();

        /**
            Redraws the "PLAYER vs COMPUTER" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "PLAYER vs COMPUTER" button with the hover effect on it
        **/
        void hoverPlayerVsComputer ();

        /**
            Redraws the "PLAYER vs PLAYER" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "PLAYER vs PLAYER" button with the hover effect on it
        **/
        void hoverPlayerVsPlayer ();

        /**
            Redirects to the "START GAME" menu.
            Input:
                - none
            Output:
                - redirects to the "START GAME" menu
        **/
        void clickOnStartGame ();

        /**
            Redirects to the "RULES" screen.
            Input:
                - none
            Output:
                - redirects to the "RULES" screen
        **/
        void clickOnRules ();

        /**
            Redirects to the "OPTIONS" menu.
            Input:
                - none
            Output:
                - redirects to the "OPTIONS" menu
        **/
        void clickOnOptions ();

        /**
            Permanently scans the mouse location on the screen.
            Input:
                - none
            Output:
                - permanently scans the mouse location on the screen
        **/
        void scanMouseLocation ();

        /**
            Determines where the user has clicked on the screen.
            Input:
                - "xCoordinate": the x coordinate for the click
                - "yCoordinate": the y coordinate for the click
            Output:
                - 0: if the user clicked outside the buttons
                - 1: if the user clicked on the "START" button
                - 2: if the user clicked on the "RULES" button
                - 3: if the user clicked on the "EXIT" button
                - 4: if the user clicked on the "OPTIONS" button
        */
        unsigned short int getMouseLocation (double xCoordinate, double yCoordinate);

        /**
            Closes the application.
            Input:
                - none
            Output:
                - closes the application
        **/
        void closeApplication ();
};
