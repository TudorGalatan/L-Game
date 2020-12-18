/**
    This is the implementation for the Player module from the Domain layer.
    The module is responsible with everything related to a player.
**/

#include "Domain_Player.h"



int Player::clickPosition ()
{
    int x, y;
    getmouseclick(VK_LBUTTON, x, y);
    // To do: check the clicked position and return the number of the cell the user clicked.
}
