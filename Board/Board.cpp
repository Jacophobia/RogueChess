#include "Board.h"

#include <iostream>

#include "../Square/Square.h"

std::tuple<bool, Piece*> Board::try_get_piece(int x, int y)
{
    if (x >= squares.size() || x < 0)
    {
        std::cout << "x index asked was out of bounds of the board" << '\n';
        std::cout << "x = " << x << "\n";
        std::cout << "0 <= x < " << squares.size() << '\n';
        throw std::exception("error: x out of bounds");
    }
    if (y >= squares[x].size() || y < 0)
    {
        std::cout << "y index asked was out of bounds of the board" << '\n';
        std::cout << "y = " << y << "\n";
        std::cout << "0 <= y < " << squares[x].size() << '\n';
        throw std::exception("error: y out of bounds");
    }
        
    return squares[x][y].try_get_piece();
}

bool Board::is_within_board_boundaries(int x, int y) const
{
    bool x_success = (x >= squares.size()) || (x < 0);
    bool y_success = (y >= squares[x].size()) || (y < 0);

    return x_success && y_success;
}

void Board::increment_turn()
{
    for (std::vector<Square> square_column : squares)
    for (Square square : square_column)
    {
        square.increment_turn();
    }

}
