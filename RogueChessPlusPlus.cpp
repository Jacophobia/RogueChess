#include <BearLibTerminal.h>
#include <vector>
#include <format>

#include "Game/Game.h"
#include "UI/UI.h"

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

// int main() {
//     
//     const std::vector<std::vector<char>> board
//     {
//         { 'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R' },
//         { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
//         { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
//         { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
//         { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
//         { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
//         { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
//         { 'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R' },
//     };
//
//     UI ui;
//
//     ui.display_title("Welcome to **the currently sample version and unplayable version of** RogueChess!");
//
//     while (true) {
//         // Wait for an event
//         const auto key = ui.get_input();
//         
//         if (key == TK_S)
//         {
//             // Display the shop
//             Shop shop;
//             ui.display_shop(shop);
//         }
//         else
//         {
//             ui.display_board(board);
//         }
//
//         if (key == TK_MOUSE_LEFT)
//         {
//             auto [x, y] = ui.get_selected_coordinate();
//             ui.display_title(std::format("Selected ({}, {})", x, y));
//         }
//
//         if (key == TK_CLOSE || key == TK_Q || key == TK_ESCAPE)
//         {
//             // Exit the loop on window close or 'q' key
//             ui.quit();
//             return 0;
//         }
//     }
// }
