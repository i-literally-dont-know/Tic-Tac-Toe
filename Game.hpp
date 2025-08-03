#include <iostream>
#include "Board.hpp"
#include "Player.hpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    int round;
    Board row_;
    Player p;
    std::string player1;
    std::string player2; // symbol
    std::vector<std::string> character_;
    int playernum_;
    int x_coor_ = -1;
    int y_coor_ = -1;

    std::vector<std::vector<std::string>> grid_;

public:
    Game();
    void printBoard();
    void printWelcomeMessage();
    void chooseXO(std::vector<std::string> &character);
    std::vector<std::vector<std::string>> playMove(int round, std::vector<std::vector<std::string>> &grid);
    bool isValidPos(int x_coordinate, int y_coordinate);
    void setGrid(std::vector<std::vector<std::string>> grid);
    std::vector<std::vector<std::string>> getGrid();
    void setCharacter(std::vector<std::string> &character);
    std::vector<std::string> getCharacter();
    void setRound(int round_);
    int getRound();
    void changePlayers();
    void setPlayerNum(int round);
    int getPlayerNum();
    int evaluateBoard(std::vector<std::vector<std::string>> grid);
    bool winnerFound();
    int validateInput(std::vector<std::string> words, int &x, int &y);
    int getXCoor();
    void setXCoor(int x_coor);
    void setYCoor(int y_coor);
    int getYCoor();
    bool isNumber(const std::vector<std::string> &words);
};

#endif