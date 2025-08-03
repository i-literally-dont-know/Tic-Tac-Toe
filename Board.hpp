#include <iostream>
#include <vector>

#ifndef BOARD_H
#define BOARD_H

class Board
{

private:
    std::vector<std::vector<std::string>> grid_;

public:
    Board();
    std::vector<std::string> row1;
    std::vector<std::string> row2;
    std::vector<std::string> row3;
};

#endif