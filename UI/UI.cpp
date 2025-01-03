#include "UI.h"

#include <BearLibTerminal.h>
#include <vector>
#include <string>
#include <iostream>

#include "Colors.h"

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
    clear(title_section);
    print(1, 1, message);
    terminal_refresh();
}

void UI::display_board(Board* board)
{
    clear(board_section);

    const auto board_template =
        "---------------------------------\n"
        "|   |   |   |   |   |   |   |   |\n"
        "----+---+---+---+---+---+---+----\n"
        "|   |   |   |   |   |   |   |   |\n"
        "----+---+---+---+---+---+---+----\n"
        "|   |   |   |   |   |   |   |   |\n"
        "----+---+---+---+---+---+---+----\n"
        "|   |   |   |   |   |   |   |   |\n"
        "----+---+---+---+---+---+---+----\n"
        "|   |   |   |   |   |   |   |   |\n"
        "----+---+---+---+---+---+---+----\n"
        "|   |   |   |   |   |   |   |   |\n"
        "----+---+---+---+---+---+---+----\n"
        "|   |   |   |   |   |   |   |   |\n"
        "----+---+---+---+---+---+---+----\n"
        "|   |   |   |   |   |   |   |   |\n"
        "---------------------------------\n";
    
    print(board_section.x, board_section.y, board_template);

    // Iterate over the board and draw each piece
    for (int y = 0; y < static_cast<int>(board->height()); ++y)
    for (int x = 0; x < static_cast<int>(board->width()); ++x)
    {
        // Print each piece at the corresponding position
        auto [x_pos, y_pos] = coordinate_to_position(x, y);
        
        print(x_pos, y_pos, board->get_graphic(x, y));
    }

    // Refresh the screen to show the board
    terminal_refresh();
}

void UI::display_shop(Shop& shop)
{
    // Clear the inside of the board
    clear(shop_section);

    // TODO: draw the shop

    terminal_refresh();
}

int UI::get_input()
{
    return terminal_read();
}

std::tuple<int, int> UI::get_selected_coordinate()
{
    const int mouse_x = terminal_state(TK_MOUSE_X);
    const int mouse_y = terminal_state(TK_MOUSE_Y);

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

void UI::clear(const TerminalSection& section)
{
    terminal_clear_area(section.x, section.y, section.width, section.height);
}

std::tuple<int, int> UI::coordinate_to_position(const int x, const int y) const
{
    return {board_section.x + 2 + x * 4, board_section.y + 1 + y * 2};
}

std::tuple<int, int> UI::position_to_coordinate(const int x, const int y) const
{
    return {(x - (1 + board_section.x)) / 4, (y - (1 + board_section.y)) / 2};
}

void UI::print(int x, int y, const std::string& message, const color_t color)
{
    terminal_color(colors::celestial_blue);
    terminal_printf(x, y, message.c_str());
}

void UI::print(int x, int y, const char message, color_t color)
{
    terminal_color(color);
    terminal_put(x, y, message);
}

void UI::print(int x, int y, TerminalGraphic graphic)
{
    terminal_color(graphic.color);
    terminal_printf(x, y, graphic.message.c_str());
}

void UI::display_inventory(Inventory& inventory)
{
    int x = inventory_section.x;
    int y = inventory_section.y;
    
    for (auto it = inventory.begin(PieceType::king); it != inventory.end(PieceType::king); ++it)
    {
        print(x, y, it->get_graphic());
        if (x < terminal_width)
        {
            x += 4;
        }
        else
        {
            y += 2;
            x = inventory_section.x;
        }
    }
    for (auto it = inventory.begin(PieceType::queen); it != inventory.end(PieceType::queen); ++it)
    {
        print(x, y, it->get_graphic());
        if (x < terminal_width)
        {
            x += 4;
        }
        else
        {
            y += 2;
            x = inventory_section.x;
        }
    }
    for (auto it = inventory.begin(PieceType::rook); it != inventory.end(PieceType::rook); ++it)
    {
        print(x, y, it->get_graphic());
        if (x < terminal_width)
        {
            x += 4;
        }
        else
        {
            y += 2;
            x = inventory_section.x;
        }
    }
    for (auto it = inventory.begin(PieceType::bishop); it != inventory.end(PieceType::bishop); ++it)
    {
        print(x, y, it->get_graphic());
        if (x < terminal_width)
        {
            x += 4;
        }
        else
        {
            y += 2;
            x = inventory_section.x;
        }
    }
    for (auto it = inventory.begin(PieceType::knight); it != inventory.end(PieceType::knight); ++it)
    {
        print(x, y, it->get_graphic());
        if (x < terminal_width)
        {
            x += 4;
        }
        else
        {
            y += 2;
            x = inventory_section.x;
        }
    }
    for (auto it = inventory.begin(PieceType::pawn); it != inventory.end(PieceType::pawn); ++it)
    {
        print(x, y, it->get_graphic());
        if (x < terminal_width)
        {
            x += 4;
        }
        else
        {
            y += 2;
            x = inventory_section.x;
        }
    }
}

void UI::display_info(const std::string& info)
{
    print(info_section.x, info_section.y, info);
}
