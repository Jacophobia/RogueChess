#include "Piece.h"

#include "../Board/Board.h"
#include "../Move/PotentialMove.h"
#include "../Move/ValidMove.h"
#include "../UI/Colors.h"

class Square;

std::vector<ValidMove> Piece::get_valid_moves(Board* board, int x, int y) const
{
    std::vector<ValidMove> valid_moves;

    //each potential move
    for (const PotentialMove base_potential_move : potential_moves)
    {
        const PotentialMove potential_move = upgrade_potential_move(base_potential_move);
        
        //removes first-move moves if move is not first-move
        if (potential_move.is_only_valid_on_first_move && has_moved)
        {
            continue;
        }

        //every repeated move
        const int limit = potential_move.repetitions_limit;
        for (int i = 1; i <= limit || limit == 0; i++)
        {
            const int checked_delta_x = potential_move.delta_x * i;
            const int checked_delta_y = potential_move.delta_y * i;

            const int checked_x = checked_delta_x + x;
            const int checked_y = checked_delta_y + y;
            
            if (!board->is_within_board_boundaries(checked_x, checked_y))
            {
                break;
            }
            
            auto [is_there_a_piece_in_the_checked_square, checked_piece] = board->try_get_piece(checked_x, checked_y);

            //condition: there is not a piece in the square, and the move does not require a capture to perform
            if (!is_there_a_piece_in_the_checked_square)
            {
                if (!potential_move.is_only_valid_on_capture)
                {
                    //move is valid, now describing post conditions for move
                    ValidMove valid_move;
                    
                    if (!potential_move.is_only_chainable_on_capture)
                    {
                        valid_move.chains_remaining = potential_move.chains_added;
                    }

                    valid_move.x = checked_delta_x + x;
                    valid_move.y = checked_delta_y + y;

                    valid_move.initial_x = x;
                    valid_move.initial_y = y;

                    valid_moves.push_back(valid_move);
                }
            }
            else if (potential_move.can_capture)
            {
                if (checked_piece->get_color() == color && potential_move.can_pass_through_pieces == true)
                {
                    continue;
                }

                if (checked_piece->get_color() != color)
                {
                    //move is valid, now describing post conditions for move
                    ValidMove valid_move;

                    valid_move.chains_remaining = potential_move.chains_added;

                    valid_move.x = checked_delta_x + x;
                    valid_move.y = checked_delta_y + y;

                    valid_move.initial_x = x;
                    valid_move.initial_y = y;

                    valid_moves.push_back(valid_move);
                    
                    if (potential_move.can_pass_through_pieces == true)
                    {
                        continue;
                    }

                }

                break;
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
    // TODO: NOT IMPLEMENTED
    return potential_move;
}

TerminalGraphic Piece::get_graphic() const
{
    const char* graphic_symbol = symbol.c_str();
    const char* graphic_color;

    switch (color)
    {
    case Color::white:
        graphic_color = colors::tea_green;
        break;
    case Color::black:
        graphic_color = colors::dark_orange;
        break;
    default:
        graphic_color = colors::red;
        break;
    }

    return { .message= graphic_symbol, .color= graphic_color };
}

PieceType Piece::get_type()
{
    // TODO: do this
    return PieceType::bishop;
}
