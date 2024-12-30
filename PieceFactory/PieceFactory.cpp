#include "PieceFactory.h"

#include <iostream>

std::shared_ptr<Piece> PieceFactory::build_pawn(Color color)
{
    PotentialMove forward_one;
    PotentialMove initial_forward_two;
    PotentialMove diagonal_capture_left;
    PotentialMove diagonal_capture_right;

    int y_direction;

    switch (color)
    {
    case Color::black:
        y_direction = -1;
        break;
        
    case Color::white:
        y_direction = 1;
        break;

    default:
        std::cout << "color = " << color::to_string(color);
        throw std::exception("error: idk how you got here, but your color was neither black nor white");
    }

    forward_one.delta_y = 1 * y_direction;

    initial_forward_two.is_only_valid_on_first_move = true;
    initial_forward_two.delta_y = 2 * y_direction;

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
    
    return std::make_shared<Piece>(color, potential_moves, 1);
}
