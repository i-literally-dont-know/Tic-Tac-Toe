#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>
#include <vector>

// to compile:
// g++ -std=c++17 main_gui.cpp Game.cpp Board.cpp Player.cpp -o gui_game \
-I/opt/homebrew/include -L/opt/homebrew/lib \
-lsfml-graphics -lsfml-window -lsfml-system \
-Wl,-rpath,/opt/homebrew/lib
// to execute:  ./gui_game

int main()
{
    Game game;

    std::vector<std::string> character = {"X", "O"};
    game.setCharacter(character);
    game.setPlayerNum(game.getRound());

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf"))
    {
        std::cerr << "Failed to load font!\n";
        return -1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 800), "Tic Tac Toe!");

    sf::RectangleShape boardBackground(sf::Vector2f(600.f, 600.f));
    boardBackground.setFillColor(sf::Color::White);
    boardBackground.setPosition(100.f, 100.f);

    // Grid lines
    sf::RectangleShape vLine1(sf::Vector2f(5.f, 600.f));
    vLine1.setPosition(300.f, 100.f); // 100 + 200
    vLine1.setFillColor(sf::Color::Black);

    sf::RectangleShape vLine2(sf::Vector2f(5.f, 600.f));
    vLine2.setPosition(500.f, 100.f); // 100 + 400
    vLine2.setFillColor(sf::Color::Black);

    sf::RectangleShape hLine1(sf::Vector2f(600.f, 5.f));
    hLine1.setPosition(100.f, 300.f); // 100 + 200
    hLine1.setFillColor(sf::Color::Black);

    sf::RectangleShape hLine2(sf::Vector2f(600.f, 5.f));
    hLine2.setPosition(100.f, 500.f); // 100 + 400
    hLine2.setFillColor(sf::Color::Black);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                float mouseX = event.mouseButton.x;
                float mouseY = event.mouseButton.y;

                int col = (mouseX - 100) / 200;
                int row = (mouseY - 100) / 200;

                if (row >= 0 && row < 3 && col >= 0 && col < 3 && game.isValidPos(row, col))
                {
                    int player = game.getPlayerNum();
                    std::string symbol = game.getCharacter()[player - 1];

                    auto grid = game.getGrid();
                    grid[row][col] = symbol;
                    game.setGrid(grid);

                    if (game.evaluateBoard(grid) != -1)
                    {
                        std::cout << "Player " << player << " wins!\n";
                        window.close();
                    }

                    game.setRound(game.getRound() + 1);
                    game.setPlayerNum(game.getRound());
                }
            }
        }

        // Render phase
        window.clear();
        window.draw(boardBackground);
        window.draw(vLine1);
        window.draw(vLine2);
        window.draw(hLine1);
        window.draw(hLine2);

        // Draw current board state
        auto grid = game.getGrid();
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (grid[i][j] != " ")
                {
                    sf::Text text;
                    text.setFont(font);
                    text.setString(grid[i][j]);
                    text.setCharacterSize(150);
                    text.setFillColor(sf::Color::Black);
                    text.setPosition(100 + j * 200 + 50, 100 + i * 200 - 10);
                    window.draw(text);
                }
            }
        }

        window.display();
    }

    return 0;
}
