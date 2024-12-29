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

void UI::display_title(const std::string& message)
{
    terminal_clear_area(1, 1, terminal_width, 1);
    terminal_printf(1, 1, message.c_str());
    terminal_refresh();
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
    terminal_clear_area(x_tab_size, y_tab_size, 33, 17); // Clear the screen

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
            auto [x_pos, y_pos] = coordinate_to_position(x, y);
            terminal_put(x_pos, y_pos, board[y][x]);
        }
    }

    // Refresh the screen to show the board
    terminal_refresh();
}

void UI::display_shop(Shop& shop)
{
    // Clear the inside of the board
    terminal_clear_area(x_tab_size + 1, y_tab_size + 1, 31, 15);

    // TODO: draw the shop

    terminal_refresh();
}

int UI::get_input()
{
    return terminal_read();
}

std::tuple<int, int> UI::get_selected_coordinate()
{
    int mouse_x = terminal_state(TK_MOUSE_X);
    int mouse_y = terminal_state(TK_MOUSE_Y);

    return position_to_coordinate(mouse_x, mouse_y);
}

void UI::exit()
{
    terminal_close();
}

void UI::quit()
{
    exit();
}

std::tuple<int, int> UI::coordinate_to_position(const int x, const int y) const
{
    return {x_tab_size + 2 + x * 4, y_tab_size + 1 + y * 2};
}

std::tuple<int, int> UI::position_to_coordinate(const int x, const int y) const
{
    return {(x - (1 + x_tab_size)) / 4, (y - (1 + y_tab_size)) / 2};
}
