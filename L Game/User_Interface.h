/**
    This is the interface for the User Interface module.
    The module is responsible with the visual side of the application.
**/

#pragma once

#define USI unsigned short int


class UserInterface
{
    private:

        bool musicIsOn;

    public:

        /**
            This is the default constructor.
        **/
        UserInterface ();

        /**
            Starts the graphical user interface.
            Input:
                - none
            Output:
                - the graphical user interface is being started
        **/
        void startGUI ();

        /**
            Draws the Main screen.
            Input:
                - none
            Output:
                - the Main screen is drawn
        **/
        void drawMainScreen ();

        /**
            Draws the Play screen.
            Input:
                - none
            Output:
                - the Play screen is drawn
        **/
        void drawPlayScreen ();

        /**
            Draws the Options screen.
            Input:
                - none
            Output:
                - the Options screen is drawn
        **/
        void drawOptionsScreen ();

        /**
            Draws the Rules screen.
            Input:
                - none
            Output:
                - the Rules screen is drawn
        **/
        void drawRulesScreen ();

        /**
            Draws the Music screen.
            Input:
                - none
            Output:
                - the Music screen is drawn
        **/
        void drawMusicScreen ();

        /**
            Draws the Language screen.
            Input:
                - none
            Output:
                - the Language screen is drawn
        **/
        void drawLanguageScreen ();

        /**
            Draws the Difficulty screen.
            Input:
                - none
            Output:
                - the Difficulty screen is drawn
        **/
        void drawDifficultyScreen ();

        /**
            Draws a button.
            Input:
                - "leftMargin": the left margin of the button
                - "upperMargin": the upper margin of the button
                - "rightMargin": the right margin of the button
                - "downMargin": the down margin of the button
                - "depth": the depth of the button
                - "drawDetails": specifies whether or not to draw more details
                - "horizontalPosition": the horizontal position of the text
                - "verticalPosition": the vertical position of the text
                - "text": the text to be displayed on the button
            Output:
                - the button is drawn
        **/
        void drawButton (USI leftMargin, USI upperMargin, USI rightMargin, USI downMargin, USI depth, bool drawDetails, USI horizontalPosition, USI verticalPosition, char text[]);

        /**
            Draws the Main screen with a hover effect on the Play button.
            Input:
                - none
            Output:
                - the Main screen with a hover effect on the Play button is drawn
        **/
        void hoverPlay ();

        /**
            Draws the Main screen with a hover effect on the Options button.
            Input:
                - none
            Output:
                - the Main screen with a hover effect on the Options button is drawn
        **/
        void hoverOptions ();

        /**
            Draws the Main screen with a hover effect on the Rules button.
            Input:
                - none
            Output:
                - the Main screen with a hover effect on the Rules button is drawn
        **/
        void hoverRules ();

        /**
            Draws the Main screen with a hover effect on the Exit button.
            Input:
                - none
            Output:
                - the Main screen with a hover effect on the Exit button is drawn
        **/
        void hoverExit ();

        /**
            Draws the Play screen with a hover effect on the Player vs Computer button.
            Input:
                - none
            Output:
                - the Play screen with a hover effect on the Player vs Computer button is drawn
        **/
        void hoverPlayerVsComputer ();

        /**
            Draws the Play screen with a hover effect on the Player vs Player button.
            Input:
                - none
            Output:
                - the Play screen with a hover effect on the Player vs Player button is drawn
        **/
        void hoverPlayerVsPlayer ();

        /**
            Draws the Play screen with a hover effect on the Back button.
            Input:
                - none
            Output:
                - the Play screen with a hover effect on the Back button is drawn
        **/
        void hoverBackPlay ();

        /**
            Draws the Options screen with a hover effect on the Music button.
            Input:
                - none
            Output:
                - the Options screen with a hover effect on the Music button is drawn
        **/
        void hoverMusic ();

        /**
            Draws the Options screen with a hover effect on the Language button.
            Input:
                - none
            Output:
                - the Options screen with a hover effect on the Language button is drawn
        **/
        void hoverLangauge ();

        /**
            Draws the Options screen with a hover effect on the Difficulty button.
            Input:
                - none
            Output:
                - the Options screen with a hover effect on the Difficulty button is drawn
        **/
        void hoverDifficulty ();

        /**
            Draws the Options screen with a hover effect on the Back button.
            Input:
                - none
            Output:
                - the Options screen with a hover effect on the Back button is drawn
        **/
        void hoverBackOptions ();

        /**
            Draws the Rules screen with a hover effect on the Back button.
            Input:
                - none
            Output:
                - the Rules screen with a hover effect on the Back button is drawn
        **/
        void hoverBackRules ();

        /**
            Handles user's actions on the Main screen.
            Input:
                - none
            Output:
                - user's actions on the Main screen are being handled
        **/
        void onMainScreen ();

        /**
            Handles user's actions on the Play screen.
            Input:
                - none
            Output:
                - user's actions on the Play screen are being handled
        **/
        void onPlayScreen ();

        /**
            Handles user's actions on the Options screen.
            Input:
                - none
            Output:
                - user's actions on the Options screen are being handled
        **/
        void onOptionsScreen ();

        /**
            Handles user's actions on the Rules screen.
            Input:
                - none
            Output:
                - user's actions on the Rules screen are being handled
        **/
        void onRulesScreen ();

        /**
            Handles user's actions on the Music screen.
            Input:
                - none
            Output:
                - user's actions on the Music screen are being handled
        **/
        void onMusicScreen ();

        /**
            Handles user's actions on the Language screen.
            Input:
                - none
            Output:
                - user's actions on the Language screen are being handled
        **/
        void onLanguageScreen ();

        /**
            Handles user's actions on the Difficulty screen.
            Input:
                - none
            Output:
                - user's actions on the Difficulty screen are being handled
        **/
        void onDifficultyScreen ();

        /**
            Gets the mouse location on the Main screen.
            Input:
                - "horizontalPosition": the horizontal position of the mouse
                - "verticalPosition": the vertical position of the mouse
            Output:
                - 0: if the mouse is outside the buttons
                - 1: if the mouse is on the Play button
                - 2: if the mouse is on the Options button
                - 3: if the mouse is on the Rules button
                - 4: if the mouse is on the Exit button
        */
        unsigned short int getMouseLocationOnMainScreen (double horizontalPosition, double verticalPosition);

        /**
            Turns the music on or off.
            Input:
                - none
            Output:
                - the music is turned on if it was off
                - the music is turned off if it was on
        **/
        void turnMusicOnOff ();

        /**
            Exits the game.
            Input:
                - none
            Output:
                - the game is exited
        **/
        void exitGame ();
};
