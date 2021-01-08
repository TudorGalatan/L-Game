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
            Starts playing the background music.
            Input:
                - none
            Output:
                - the background music is played
        **/
        void playMusic ();

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
            Draws the "Difficulty" screen.
            Input:
                - none
            Output:
                - draws the "Difficulty" screen
        **/
        void drawDifficultyScreen ();

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
        void drawButton (USI leftMargin, USI upperMargin, USI rightMargin, USI downMargin, USI depth, bool drawDetails, USI horizontalPosition, USI verticalPosition, char text[]);

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
        void hoverBackRules ();

        /**
            Redraws the "BACK" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "BACK" button with the hover effect on it
        **/
        void hoverBackPlay ();

        /**
            Redraws the "BACK" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "BACK" button with the hover effect on it
        **/
        void hoverBackOptions ();

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
            Redraws the "Music" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "Music" button with the hover effect on it
        **/
        void hoverMusic ();

        /**
            Redraws the "Language" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "Language" button with the hover effect on it
        **/
        void hoverLangauge ();

        /**
            Redraws the "Difficulty" button with the hover effect on it.
            Input:
                - none
            Output:
                - redraws the "Difficulty" button with the hover effect on it
        **/
        void hoverDifficulty ();

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
        void scanMouseLocationMainMenu ();

        /**
            Determines where the user has clicked on the screen.
            Input:
                - "xCoordinate": the x coordinate for the click
                - "yCoordinate": the y coordinate for the click
            Output:
                - 0: if the user clicked outside the buttons
                - 1: if the user clicked on the "Play" button
                - 2: if the user clicked on the "Options" button
                - 3: if the user clicked on the "Rules" button
                - 4: if the user clicked on the "Exit" button
        */
        unsigned short int getMouseLocationMainMenu (double horizontalCoordinate, double verticalCoordinate);

        /**
            Closes the application.
            Input:
                - none
            Output:
                - closes the application
        **/
        void clickOnExit ();
};
