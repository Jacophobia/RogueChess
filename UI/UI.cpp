#include "UI.h"

#include <BearLibTerminal.h>
#include <vector>
#include <string>
#include <iostream>

UI::UI()
{
    char terminal_params[128];
    const int result_size = snprintf(
        terminal_params,
        sizeof(terminal_params),
        "window: title='Mouse Position Example', size=%dx%d;"
        "input.filter={keyboard, mouse};", // Enable mouse input
        terminal_width,
        terminal_height
    );

    if (result_size < 0)
    {
        std::cout << "An encoding error has occurred" << "\n";
        throw std::runtime_error("An encoding error has occurred");
    }
    if (static_cast<size_t>(result_size) >= sizeof(terminal_params))
    {
        std::cout << "Terminal input exceeded the size of the buffer" << "\n";
        throw std::runtime_error("Terminal input exceeded the size of the buffer");
    }
    
    // Initialize the terminal
    terminal_open();

    terminal_set(
        terminal_params
    );
}

UI::~UI()
{
    terminal_close(); // Close the terminal
}

void UI::display_message(const std::string& message)
{
    terminal_clear_area(1, 1, terminal_width, 1);
    terminal_printf(1, 1, message.c_str());
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
    constexpr auto x_tab_size = 5;
    constexpr auto y_tab_size = 2;
    
    terminal_clear_area(5, 2, 33, 8); // Clear the screen

    auto board_template =
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n";
    
    terminal_printf(x_tab_size, y_tab_size, board_template);

    // Iterate over the board and draw each piece
    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].size(); ++x)
        {
            // Print each piece at the corresponding position
            terminal_put(x_tab_size + 2 + x * 4, y_tab_size + 1 + y * 2, board[y][x]);
        }
    }

    // Refresh the screen to show the board
    terminal_refresh();
}

int UI::get_input()
{
    return terminal_read();
}

void UI::exit()
{
    terminal_close();
}

void UI::quit()
{
    exit();
}
