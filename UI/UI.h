#pragma once

#include <BearLibTerminal.h>
#include <vector>

#include "TerminalSection.h"
#include "../Board/Board.h"
#include "../Inventory/Inventory.h"
#include "../Shop/Shop.h"
#include "../Square/Square.h"

class UI
{
public:
    UI();
    ~UI();
    UI(UI&) = delete;
    UI& operator=(UI&) = delete;

    void display_title(const std::string& message);

    void display_board(Board& board);
    void display_board(const std::vector<std::vector<char>>& board);
    void display_shop(Shop& shop);
    // void display_inventory(Inventory& inventory);
    int get_input();
    std::tuple<int, int> get_selected_coordinate();
    void exit();
    void quit();

private:
    int terminal_width = 80;
    int terminal_height = 25;
    
    TerminalSection board_section =     {.x = 5,  .y = 3,  .width = 33,                  .height = 17};
    TerminalSection shop_section =      {.x = 6,  .y = 4,  .width = 31,                  .height = 15};
    TerminalSection title_section =     {.x = 1,  .y = 1,  .width = terminal_width,      .height = 1};
    TerminalSection inventory_section = {.x = 34, .y = 2,  .width = terminal_width - 33, .height = 17};
    TerminalSection info_section =      {.x = 1,  .y = 18, .width = terminal_width,      .height = terminal_height - 17};

    void clear(const TerminalSection& section);

    [[nodiscard]] std::tuple<int, int> coordinate_to_position(int x, int y) const;
    [[nodiscard]] std::tuple<int, int> position_to_coordinate(int x, int y) const;

    void print(int x, int y, const std::string& message, color_t color = 0xffffff);
    void print(int x, int y, char message, color_t color = 0xffffff);
    void print(int x, int y, TerminalGraphic graphic);
};
