#include "PieceFactory.h"

#include <iostream>

int PieceFactory::determine_direction_piece_faces(const Color color)
{
    switch (color)
    {
    case Color::black:
        return 1;
        
    case Color::white:
        return -1;

    default:
        std::cout << "color = " << color::to_string(color);
        throw std::exception("error: idk how you got here, but your color was neither black nor white");
    }

}

std::shared_ptr<Piece> PieceFactory::build_pawn(Color color)
{
    PotentialMove forward_one;
    PotentialMove initial_forward_two;
    PotentialMove diagonal_capture_left;
    PotentialMove diagonal_capture_right;

    int y_direction = determine_direction_piece_faces(color);

    forward_one.delta_y = 1 * y_direction;

    initial_forward_two.is_only_valid_on_first_move = true;
    initial_forward_two.delta_y = 2 * y_direction;
    initial_forward_two.can_capture = false;

    diagonal_capture_left.delta_x = -1;
    diagonal_capture_left.delta_y = 1 * y_direction;
    diagonal_capture_left.is_only_valid_on_capture = true;
    
    diagonal_capture_right.delta_x = 1;
    diagonal_capture_right.delta_y = 1 * y_direction;
    diagonal_capture_right.is_only_valid_on_capture = true;

    std::vector potential_moves = {
        forward_one,
        initial_forward_two,
        diagonal_capture_left,
        diagonal_capture_right
    };
    
    return std::make_shared<Piece>(color, potential_moves, 1, "P");
}

std::shared_ptr<Piece> PieceFactory::build_queen(Color color)
{
    const int y_direction = determine_direction_piece_faces(color);
    
    PotentialMove forward;
    forward.delta_y = y_direction;     
    forward.delta_x = 0;
    PotentialMove forward_right;
    forward_right.delta_y = y_direction;     
    forward_right.delta_x = 1;
    PotentialMove right;
    right.delta_y = 0;               
    right.delta_x = 1;
    PotentialMove back_right;
    back_right.delta_y = -y_direction;
    back_right.delta_x = 1;
    PotentialMove back;
    back.delta_y = -y_direction;
    back.delta_x = 0;
    PotentialMove back_left;
    back_left.delta_y = -y_direction;
    back_left.delta_x = -1;
    PotentialMove left;
    left.delta_y = 0;
    left.delta_x = -1;
    PotentialMove forward_left;
    forward_left.delta_y = y_direction;
    forward_left.delta_x = -1;
    
    std::vector potential_moves = {
        forward,
        forward_right,
        right,
        back_right,
        back,
        back_left,
        left,
        forward_left
    };

    for (PotentialMove& potential_move : potential_moves)
    {
        potential_move.repetitions_limit = 0;
    }
    
    return std::make_shared<Piece>(color, potential_moves, 10, "Q");
}