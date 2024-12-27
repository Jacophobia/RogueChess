#include "Piece.h"

#include "../Move/PotentialMove.h"

std::vector<ValidMove> Piece::get_valid_moves(Board& board)
{
    for (PotentialMove potential_move : potential_moves)
    {
        if (potential_move.is_only_valid_on_first_move && has_moved)
        {
            continue;
        }
        
        for (int i = 1; i <= potential_move.repetitions_limit || potential_move.repetitions_limit == 0; i++)
        {
            
        }
    }
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
