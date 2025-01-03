#pragma once
#include <tuple>

#include <string>

#include "../UI/Colors.h"
#include "../UI/TerminalGraphic.h"

class Piece;

class Square
{
public:
    std::tuple<bool, Piece*> try_get_piece();
    void increment_turn();
    Piece* place_piece(Piece* piece);
    bool contains_piece() const;

    //graphics
    [[nodiscard]] TerminalGraphic get_graphic() const;
    void override_color(const char* color);
    void override_symbol(const std::string& symbol);
    void clear_graphical_overrides();

private:
    Piece* piece = nullptr;
    bool was_piece_placed_here = false;

    //does not override if strings are empty
    std::string overriding_color = "";
    std::string overriding_symbol = "";
};
