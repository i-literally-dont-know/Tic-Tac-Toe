//  g++ -std=c++17 -Wall -o a2 main.cpp Board.cpp Game.cpp Player.cpp
// ./a2

#include <iostream>
#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"

int main()
{
    int gameover = -1;
    Game game;
    int round = game.getRound();
    game.printWelcomeMessage();
    game.printBoard();
    std::vector<std::string> character = {"", ""};
    std::vector<std::vector<std::string>> gridmain;
    gridmain = game.getGrid();
    if (round == 1)
    {
        game.chooseXO(character);
        game.setCharacter(character);
        character = game.getCharacter();
    }
    while (gameover != 1)
    {

        int repeatloop = 0;
        int playernumber = -1;
        while (repeatloop != 1)
        {
            game.setPlayerNum(round);
            playernumber = game.getPlayerNum();
            gridmain = game.getGrid();
            std::vector<std::vector<std::string>> done = game.playMove(round, gridmain);

            if (done[0][0] == "Q")
            {
                gameover = 1;
                break;
            }
            game.printBoard();
            if (playernumber == 1)
            {
                playernumber++;
            }
            else
            {
                playernumber--;
            }
            int winning = game.evaluateBoard(game.getGrid());
            // std::cout << winning << std::endl;

            if (winning == 1 || winning == 2)
            {
                std::cout << "Congratulations! Player" << winning << " wins!\n";
                gameover = 1;
                break;
            }
            round++;
        }
    }

    return 0;
}