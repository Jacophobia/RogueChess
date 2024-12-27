
#include <iostream>

#include "Game/Game.h"

int main(int argc, char* argv[])
{
    std::cout << "Welcome to RogueChess!" << '\n';
    while (true)
    {
        std::cout << "Start a new game?" << ' ';
        std::string input;
        std::cin >> input;

        if (!input.empty() && input[0] != 'y')
        {
            return 0;
        }

        Game game;

        game.start();

        while (!game.is_game_over())
        {
            game.next_turn();
        }
    }
}
