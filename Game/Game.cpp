#include "Game.h"

#include <format>

Game::Game()
{
    srand(54783957);

}

void Game::start()
{
    ui.display_title("Welcome to **the currently unplayable version of** RogueChess!");
}

void Game::next_turn()
{
    while (true)
    {
        const auto key = ui.get_input();
        
        if (key == TK_S)
        {
            // Display the shop
            Shop shop;
            ui.display_shop(shop);
        }
        else
        {
            ui.display_board(&board);
        }

        if (key == TK_MOUSE_LEFT)
        {
            auto [x, y] = ui.get_selected_coordinate();
            ui.display_title(std::format("Selected ({}, {})", x, y));
        }
        
        if (key == TK_CLOSE || key == TK_Q || key == TK_ESCAPE)
        {
            // Exit the loop on window close or 'q' key
            is_game_over2 = true;
            return;
        }
    }
}

bool Game::is_game_over()
{
    //TODO: make it not always false lol
    return is_game_over2;
}

void Game::close()
{
    ui.quit();
}

void Game::select_piece(int x, int y)
{
    board.show_valid_moves(x, y);
}

