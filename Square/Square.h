#pragma once
#include <memory>
#include <tuple>

#include <string>

#include "../UI/Colors.h"
#include "../UI/TerminalGraphic.h"

class Piece;

class Square
{
public:
    Square() = default;
    ~Square() = default;
    Square(Square&) = default;
    
    std::tuple<bool, std::shared_ptr<Piece>> try_get_piece();
    void increment_turn();
    std::shared_ptr<Piece> place_piece(std::shared_ptr<Piece> piece);
    bool contains_piece() const;

    //graphics
    [[nodiscard]] TerminalGraphic get_graphic() const;
    void override_color(const char* color);
    void override_symbol(const std::string& symbol);
    void clear_graphical_overrides();

private:
    std::shared_ptr<Piece> piece = nullptr;
    bool was_piece_placed_here = false;

    //does not override if strings are empty
    std::string overriding_color = "";
    std::string overriding_symbol = "";
};
