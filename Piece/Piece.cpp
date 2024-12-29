#include "Piece.h"

#include "../Board/Board.h"
#include "../Move/PotentialMove.h"
#include "../Move/ValidMove.h"
#include "../UI/Colors.h"

class Square;

std::vector<ValidMove> Piece::get_valid_moves(Board& board) const
{
    std::vector<ValidMove> valid_moves;

    //each potential move
    for (PotentialMove base_potential_move : potential_moves)
    {
        PotentialMove potential_move = upgrade_potential_move(base_potential_move);
        
        //removes first-move moves if move is not first-move
        if (potential_move.is_only_valid_on_first_move && has_moved)
        {
            continue;
        }

        //every repeated move
        const int limit = potential_move.repetitions_limit;
        for (int i = 1; i <= limit || limit == 0; i++)
        {
            int checked_delta_x = potential_move.delta_x * i;
            int checked_delta_y = potential_move.delta_y * i;

            if (!board.is_within_board_boundaries(checked_delta_x, checked_delta_y))
            {
                break;
            }
            
            auto [is_piece_in_checked_square, checked_piece] = board.try_get_piece(checked_delta_x, checked_delta_y);

            //condition: there is not a piece in the square, and the move does not require a capture to perform
            if (!is_piece_in_checked_square)
            if (!potential_move.is_only_valid_on_capture)
            {
                //move is valid, now describing post conditions for move
                ValidMove valid_move;
                
                if (!potential_move.is_only_chainable_on_capture)
                {
                    valid_move.chains_remaining = potential_move.chains_added;
                }

                valid_move.delta_x = checked_delta_x;
                valid_move.delta_y = checked_delta_y;

                valid_moves.push_back(valid_move);
                
                continue;
            }
            
            if (checked_piece->get_color() == Color::black)
            {
                //move is valid, now describing post conditions for move
                ValidMove valid_move;

                valid_move.chains_remaining = potential_move.chains_added;

                valid_move.delta_x = checked_delta_x;
                valid_move.delta_y = checked_delta_y;

                valid_moves.push_back(valid_move);
            }
        }
    }

    return valid_moves;
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

PotentialMove Piece::upgrade_potential_move(PotentialMove potential_move) const
{
    //NOT IMPLEMENTED
    return potential_move;
}

TerminalGraphic Piece::get_graphic() const
{
    return { .message= "P", .color= colors::celestial_blue };
}
