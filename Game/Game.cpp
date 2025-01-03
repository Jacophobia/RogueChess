#include "Game.h"

#include <format>

Game::Game()
{
    srand(54783957);

}

void Game::start()
{
    ui.display_title("Welcome to **the currently unplayable version of** RogueChess!");

    //test code below
    
    auto white_pawn = std::make_tuple(PieceFactory::build_pawn(Color::white), 1, 4);
    auto black_pawn = std::make_tuple(PieceFactory::build_pawn(Color::black), 4, 2);

    std::vector<std::tuple<std::shared_ptr<Piece>, int, int>> pieces_and_locations = {white_pawn, black_pawn};
    
    board.set_up(pieces_and_locations);
}

void Game::next_turn()
{
    while (true)
    {
        const auto key = ui.get_input();
        ui.display_board(&board);
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
            could_the_game_be_possibly_over = true;
            return;
        }
    }
}

bool Game::is_game_over()
{
    return could_the_game_be_possibly_over;
}

void Game::close()
{
    ui.quit();
}

void Game::select_piece(int x, int y)
{
    board.show_valid_moves(x, y);
}

