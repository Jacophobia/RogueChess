#include <BearLibTerminal.h>
#include <vector>

#include "UI/UI.h"

int main() {
    std::vector<std::vector<char>> board
    {
        { 'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R' },
    };

    UI ui;
    ui.display_message("Welcome to RogueChess!");

    while (true) {
        ui.display_board(board);
        
        // Wait for an event
        const auto key = ui.get_input();

        if (key == TK_CLOSE || key == TK_Q || key == TK_ESCAPE) {
            // Exit the loop on window close or 'q' key
            ui.quit();
            return 0;
        }
    }
}


/**
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

        UI ui;

        std::vector<std::vector<char>> board = {
            {'#', '#', '#', '#', '#'},
            {'#', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#'}
        };
        
        ui.display_board(board);

        // Game game;
        //
        // game.start();
        //
        // while (!game.is_game_over())
        // {
        //     game.next_turn();
        // }
    }
}
*/