#include "Square.h"
#include "../Piece/Piece.h"

std::tuple<bool, Piece*> Square::try_get_piece()
{
    bool is_piece_there = piece != nullptr;

    return std::make_tuple(is_piece_there, piece);
}
