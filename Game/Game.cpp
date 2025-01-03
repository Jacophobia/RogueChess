#include "Game.h"

void Game::start()
{
    // board.set_up();
}

void Game::next_turn()
{
    
}

bool Game::is_game_over()
{
    return true;
}

void Game::select_piece(int x, int y)
{
    board.show_valid_moves(x, y);
}

