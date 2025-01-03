#include "Square.h"

#include <iostream>

#include "../Piece/Piece.h"
#include "../Move/PotentialMove.h"
#include "../UI/Colors.h"

std::tuple<bool, std::shared_ptr<Piece>> Square::try_get_piece()
{
    bool is_piece_there = piece != nullptr;

    return std::make_tuple(is_piece_there, piece);
}

void Square::increment_turn()
{
    piece->increment_turn(was_piece_placed_here);

    was_piece_placed_here = false;
}

std::shared_ptr<Piece> Square::place_piece(std::shared_ptr<Piece> piece)
{
    if (piece == nullptr)
    {
        std::cout << "Attempted to place nullptr into square" << "\n";
        throw std::exception("error: Attempted to place nullptr into square");
    }

    was_piece_placed_here = true;

    const auto old_piece = this->piece;
    this->piece = piece;
    return old_piece;
}

bool Square::contains_piece() const
{
    return piece != nullptr;
}

TerminalGraphic Square::get_graphic() const
{
    TerminalGraphic graphic;

    const TerminalGraphic empty_square_graphic = { .message = " ", .color = colors::white };
    
    if (!overriding_color.empty())
    {
        graphic.color = overriding_color.c_str();
    }
    else if (piece != nullptr)
    {
        graphic.color = piece->get_graphic().color;
    }
    else
    {
        graphic.color = empty_square_graphic.color;
    }

    if (!overriding_symbol.empty())
    {
        graphic.message = overriding_symbol;
    }
    else if (piece != nullptr)
    {
        graphic.message = piece->get_graphic().message;
    }
    else
    {
        graphic.message = empty_square_graphic.message;
    }

    return graphic;
}

void Square::override_color(const char* color)
{
    overriding_color = color;
}

void Square::override_symbol(const std::string& symbol)
{
    overriding_symbol = symbol;
}

void Square::clear_graphical_overrides()
{
    overriding_symbol = "";
    overriding_color = "";
}
