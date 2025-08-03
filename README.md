# Tic-Tac-Toe
A really simple tic tac toe game, coded in c++ w a GUI interface 

TW: there are no prompts (yet) so player 1 is js the player who plays first. I also haven't added a "winner's window" yet (or wtv), so the winner of the game is announced in the console instead. 

To compile it: 

g++ -std=c++17 main_gui.cpp Game.cpp Board.cpp Player.cpp -o gui_game \
-I/opt/homebrew/include -L/opt/homebrew/lib \
-lsfml-graphics -lsfml-window -lsfml-system \
-Wl,-rpath,/opt/homebrew/lib

To execute it ig: ./gui_game 







Other than that, I don't really have much else to say lmao 👁️👅👁️
