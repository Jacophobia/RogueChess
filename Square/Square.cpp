#include "Square.h"

#include <iostream>

#include "../Piece/Piece.h"
#include "../Move/PotentialMove.h"

std::tuple<bool, Piece*> Square::try_get_piece()
{
    bool is_piece_there = piece != nullptr;

    return std::make_tuple(is_piece_there, piece);
}

void Square::increment_turn()
{
    piece->increment_turn(was_piece_placed_here);

    was_piece_placed_here = false;
}

Piece* Square::place_piece(Piece* piece)
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

void Square::change_color()
{
}

std::string Square::to_string() const
{
    return piece->to_string();
}
