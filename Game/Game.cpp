#include "Game.h"

#include <format>

Game::Game()
{
    srand(54783957);

}

void Game::start()
{
    ui.display_title("Welcome to **the currently unplayable version of** RogueChess!");

    test_setup();
}

void Game::test_setup()
{
    auto white_pawn1 = std::make_tuple(PieceFactory::build_pawn(Color::white), 1, 4);
    auto white_pawn2 = std::make_tuple(PieceFactory::build_pawn(Color::white), 3, 6);
    auto black_pawn1 = std::make_tuple(PieceFactory::build_pawn(Color::black), 0, 1);
    auto black_pawn2 = std::make_tuple(PieceFactory::build_pawn(Color::black), 2, 3);

    auto white_queen = std::make_tuple(PieceFactory::build_queen(Color::white), 5, 6);

    std::vector pieces_and_locations = {white_pawn1, black_pawn1, white_pawn2, black_pawn2, white_queen};
    
    board.set_up(pieces_and_locations);
}

void Game::next_turn()
{
    while (true)
    {
        ui.display_board(&board);

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

            if (board.is_within_board_boundaries(x, y))
            {
                board.clear_graphical_overrides();
                board.show_valid_moves(x, y);
            }
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


