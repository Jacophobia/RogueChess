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

    void display_message(const std::string& message);

    void display_board(const std::vector<std::vector<Square>>& board);
    void display_board(const std::vector<std::vector<char>>& board);
    // void display_shop(Shop& shop);
    // void display_inventory(Inventory& inventory);
    int get_input();
    void exit();
    void quit();

private:
    const int terminal_width = 80;
    const int terminal_height = 25;
};
