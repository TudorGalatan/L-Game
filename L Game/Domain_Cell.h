/**
    This is the interface for the Cell module from the Domain layer.
    The module is responsible with everything related to a cell from the game board.
**/

#pragma once



class Cell
{
    private:

        // The dimension of the cell (200 px)
        int dim;    // = 200 ???

        // The colour of the cell
        int cellColor;      // we don't need to say cellColor -> this.color

        // The positions used in setPosition(), the 'spawn' position.
        int posX = 666, posY = 666;

    public:

        /**
            Draws a cell.
            Input:
                - "left": the left margin of the cell
                - "up": the upper margin of the cell
                - "right": the right margin of the cell
                - "bottom": the bottom margin of the cell
            Output:
                - draws the cell
        **/
        void drawCell (int left, int up, int right, int bottom);

        /**
            Gets the size of the cell.
            Input:
                - none
            Output:
                - the size of the cell
        **/
        int getCellSize ();

        /**
            Gets the colour of the cell.
            Input:
                - none
            Output:
                - the colour of the cell
        **/
        int getColor ();

        /**
            Sets the colour of the cell.
            Input:
                - "color": the colour of the cell
            Output:
                - sets the colour of the cell to its new, given value
        **/
        void setColor (int color);

        /**
            ???
            Input:
                -
            Output:
                -
        **/
        int getPosition (char* axis);   // the parameter?

        /**
            ???
            Input:
                - "pX": position on ox
                - "pY": position on oy
            Output:
                - changes the private variables posx and posy
        **/
        void setPosition (int pX, int pY); // set the position to help the setColor function fill the right cell

        /**
            Updates the size of the cell.
            Input:
                - "newSize": the new size of the cell
            Output:
                - updates the cell size
        **/
        int changeCellSize (int newSize); // change the size of the cell (not used yet)
};
