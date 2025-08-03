#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int playernum;
    std::string playersymbol;
    int score;
    int x_coordinate;
    int y_coordinate;
    std::string name;

public:
    int caluclateScore();
    int whichPlayer(int round);
};

#endif