#include "UI.h"

#include <BearLibTerminal.h>
#include <vector>
#include <string>

UI::UI()
{
    terminal_open(); // Initialize the terminal
    terminal_set("window: size=80x24; font: default");
}

UI::~UI()
{
    terminal_close(); // Close the terminal
}

void UI::display_board(const std::vector<std::vector<Square>>& board)
{
    terminal_clear(); // Clear the screen

    // Iterate over the board and draw each piece
    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            constexpr auto tab_size = 6;
            // Print each piece at the corresponding position
            terminal_printf(tab_size + x * 2, tab_size + y * 2, "%s", board[y][x].to_string().c_str());
        }
    }

    // Refresh the screen to show the board
    terminal_refresh();
}

void UI::display_board(const std::vector<std::vector<char>>& board)
{
    terminal_clear(); // Clear the screen

    // Iterate over the board and draw each piece
    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            constexpr auto tab_size = 6;
            // Print each piece at the corresponding position
            terminal_put(tab_size + x * 2, tab_size + y * 2, board[y][x]);
        }
    }

    // Refresh the screen to show the board
    terminal_refresh();
}
