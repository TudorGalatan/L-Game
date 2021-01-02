/**
    This is the interface for the Cell module from the Domain layer.
    The module is responsible with everything related to a cell from the game board.
**/

#pragma once

#define USI unsigned short int


class Cell
{
    private:

        unsigned short int dimension;
        unsigned short int colour;
        unsigned short int topMargin, leftMargin;
        unsigned short int horizontalPosition, verticalPosition;

    public:

        /**
            Creates the default constructor.
            Input:
                - none
            Output:
                - the default constructor is created
        **/
        Cell ();

        /**
            Gets the dimension of the cell.
            Input:
                - none
            Output:
                - the dimension of the cell
        **/
        unsigned short int getDimension ();

        /**
            Sets the new size of the cell.
            Input:
                - "newDimension": the new dimension of the cell
            Output:
                - the cell is updated with its new dimension
        **/
        void setDimension (unsigned short int newDimension);

        /**
            Gets the colour of the cell.
            Input:
                - none
            Output:
                - the colour of the cell
        **/
        unsigned short int getColour ();

        /**
            Sets the colour of the cell.
            Input:
                - "newColour": the new colour of the cell
            Output:
                - the cell is updated with its new colour
        **/
        void setColour (unsigned short int newColour);

        /**
            Gets the top margin of the cell.
            Input:
                - none
            Output:
                - the top margin of the cell
        **/
        unsigned short int getTopMargin ();

        /**
            Gets the left margin of the cell.
            Input:
                - none
            Output:
                - the left margin of the cell
        **/
        unsigned short int getLeftMargin ();

        /**
            Sets the top and left margins of the cell.
            Input:
                - "newTopMargin": the new top margin of the cell
                - "newLeftMargin": the new left margin of the cell
            Output:
                - the cell is updated with its new top and left margins
        **/
        void setTopLeftMargins (unsigned short int newTopMargin, unsigned short int newLeftMargin);

        /**
            Gets the appropriate position based on a given axis.
            Input:
                - "axis": the axis ("ox" or "oy")
            Output:
                - the appropriate position based on the given axis
        **/
        short int getPosition (char* axis);

        /**
            Sets the position of the inside point.
            Input:
                - "newHorizontalPosition": the new horizontal position of the point
                - "newVerticalPosition": the new vertical position of the point
            Output:
                - the cell is updated with its new inside point
        **/
        void setPosition (unsigned short int newHorizontalPosition, unsigned short int newVerticalPosition);

        /**
            Checks whether or not a point is inside the cell.
            Input:
                - "horizontalCoordinate": the horizontal coordinate of the point
                - "verticalCoordinate": the vertical coordinate of the point
            Output:
                - true, if the point is inside the cell
                - false, otherwise
        **/
        bool isInside (double horizontalCoordinate, double verticalCoordinate);

        /**
            Draws a cell.
            Input:
                - "left": the left margin of the cell
                - "up": the upper margin of the cell
                - "right": the right margin of the cell
                - "bottom": the bottom margin of the cell
            Output:
                - the cell is drawn
        **/
        void drawCell (USI left, USI up, USI right, USI bottom);
};
