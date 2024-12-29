#pragma once

#include <vector>

#include "../Inventory/Inventory.h"
#include "../Shop/Shop.h"
#include "../Square/Square.h"

class UI
{
public:
    UI();
    ~UI();
    UI(UI*) = delete;
    UI& operator=(UI&) = delete;

    void display_title(const std::string& message);

    void display_board(const std::vector<std::vector<Square>>& board);
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
    int x_tab_size = 5;
    int y_tab_size = 3;

    std::tuple<int, int> coordinate_to_position(int x, int y) const;
    std::tuple<int, int> position_to_coordinate(int x, int y) const;
};
