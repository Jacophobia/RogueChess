#include "Game/Game.h"

int main()
{
    Game game;

    game.start();
    
    while (!game.is_game_over())
    {
        game.next_turn();
    }

    game.close();
}