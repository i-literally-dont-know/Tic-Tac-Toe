#include <iostream>
#include "Player.hpp"

int Player::whichPlayer(int round)
{
    playernum = (round % 2) ? 1 : 2;

    return playernum;
}