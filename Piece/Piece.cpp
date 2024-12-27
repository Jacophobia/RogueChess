#include "Piece.h"

std::vector<ValidMove> Piece::get_valid_moves(Board& board)
{
    
}

Color Piece::get_color()
{
    return color;
}

void Piece::increment_turn(const bool is_piece_moved)
{
    if (is_piece_moved)
    {
        has_moved = true;
    }

    
}
