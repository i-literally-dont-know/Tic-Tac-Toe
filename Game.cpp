#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <string>

#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"

Game::Game() : round(1), playernum_(1)
{
    grid_ = std::vector<std::vector<std::string>>(3, std::vector<std::string>(3, " "));
}

void Game::printWelcomeMessage()
{

    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << "|  Welcome to a tragic game of TicTacToe!  |" << std::endl;
    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "p.s. this is my desultory attempt at redemption" << std::endl;
    std::cout << std::endl;
}
void Game::printBoard()
{

    std::cout << "+-----------+";
    std::cout << std::endl;

    for (int count = 0; count < 3; count++)
    {

        std::cout << "|";
        for (const auto &i : grid_[count])
        {

            std::cout << i;
            std::cout << "  |";
        }
        std::cout << std::endl;
        std::cout << "+-----------+";
        std::cout << std::endl;
    }
};

void Game::chooseXO(std::vector<std::string> &character)
{

    std::cout
        << "Player 1: choose X or O ";
    std::cin >> player1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (player1 == "X")
    {
        character[0] = "X";
        character[1] = "O";
    }
    else
    {
        character[0] = "O";
        character[1] = "X";
    }
}
std::vector<std::vector<std::string>> Game::playMove(int round, std::vector<std::vector<std::string>> &grid)
{
    int index = -1;
    std::string input;
    int invalid = 1;

    int playernum = p.whichPlayer(round);
    index = playernum - 1;
    std::string symbol = character_[index];

    while (invalid != 0)
    {
        std::cout << "Player " << playernum << ", please choose coordinates (x,y) or type 'quit': ";
        std::getline(std::cin, input);
        std::istringstream iss(input);

        std::vector<std::string> words;
        std::string token;

        while (std::getline(iss, token, ','))
        {
            token.erase(0, token.find_first_not_of(" \t"));
            token.erase(token.find_last_not_of(" \t") + 1);
            words.push_back(token);
        }

        if (words.size() == 1 && words[0] == "quit")
        {
            std::vector<std::vector<std::string>> done = {{"Q"}};
            return done;
        }

        if (words.size() != 2 || !isNumber(words))
        {
            std::cout << "Invalid input (must be two numbers or 'quit')\n";
            continue;
        }

        invalid = validateInput(words, x_coor_, y_coor_);
    }

    grid_[x_coor_][y_coor_] = symbol;
    return grid_;
}

bool Game::isValidPos(int x_coordinate, int y_coordinate)
{
    int row = x_coordinate;
    int col = y_coordinate;

    if (grid_[row][col] == " ")
    {
        return true;
    }
    return false;
}

void Game::setGrid(std::vector<std::vector<std::string>> grid)
{
    grid_ = grid;
}

std::vector<std::vector<std::string>> Game::getGrid()
{

    return grid_;
}

void Game::setCharacter(std::vector<std::string> &character)
{
    character_ = character;
}
std::vector<std::string> Game::getCharacter()
{
    return character_;
}

void Game::setRound(int round_)
{
    round = round_;
}

int Game::getRound()
{
    return round;
}

void Game::setPlayerNum(int round)
{
    if (round % 2)
    {
        playernum_ = 1;
    }
    else
    {
        playernum_ = 2;
    }
}
int Game::getPlayerNum()
{
    return playernum_;
}
int Game::evaluateBoard(std::vector<std::vector<std::string>> grid)
{
    // checking rows first:
    for (int i = 0; i < 3; i++)
    {
        std::string first = grid[i][0];
        if (first != " " && first == grid[i][1] && first == grid[i][2])
        {
            return (first == "X") ? 1 : 2;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++)
    {
        std::string first = grid[0][i];
        if (first != " " && first == grid[1][i] && first == grid[2][i])
        {
            return (first == "X") ? 1 : 2;
        }
    }

    // check diagonals
    std::string topleft = grid[0][0];
    std::string bottomleft = grid[2][0];
    std::string topright = grid[0][2];
    std::string bottomright = grid[2][2];
    std::string middle = grid[1][1];

    if (topleft == middle && topleft == bottomright && topleft != " ")
    {
        return (topleft == "X") ? 1 : 2;
    }
    else if (bottomleft == middle && bottomleft == topright && bottomleft != " ")
    {
        return (bottomleft == "X") ? 1 : 2;
    }
    return -1;
}
int Game::validateInput(std::vector<std::string> words, int &x, int &y)
{
    if (words.size() == 1 && words[0] == "quit")
    {
        return -1;
    }
    else if (words.size() != 2)
    {
        std::cout << "Wrong number of parameters!\n";
        return 1;
    }

    y = std::stoi(words[0]) - 1;
    x = std::stoi(words[1]) - 1;

    if (x < 0 || x >= 3 || y < 0 || y >= 3)
    {
        std::cout << "Out of bounds!\n";
        return 1;
    }

    if (!isValidPos(x, y))
    {
        std::cout << "Invalid position!\n";
        return 1;
    }

    return 0;
}

int Game::getXCoor()
{
    return x_coor_;
}
void Game::setXCoor(int x_coor)
{
    x_coor_ = x_coor;
}
void Game::setYCoor(int y_coor)
{
    y_coor_ = y_coor;
}
int Game::getYCoor()
{
    return y_coor_;
}
bool Game::isNumber(const std::vector<std::string> &words)
{
    for (int i = 0; i < 2; ++i)
    {
        for (char c : words[i])
        {
            if (c < '0' || c > '9')
                return false;
        }
    }
    return true;
}
