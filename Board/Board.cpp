#include "Board.h"

#include <iostream>

#include "../Square/Square.h"
#include "../Move/PotentialMove.h"
#include "../Piece/PieceType.h"
#include "../UI/Colors.h"

Board::Board() : squares(8, std::vector<Square>(8)) { }

std::tuple<bool, std::shared_ptr<Piece>> Board::try_get_piece(int x, int y)
{
    if (y >= height() || y < 0)
    {
        std::cout << "y index asked was out of bounds of the board" << '\n';
        std::cout << "y = " << y << "\n";
        std::cout << "0 <= y < " << height() << '\n';
        throw std::exception("error: y out of bounds");
    }
    if (x >= width() || x < 0)
    {
        std::cout << "x index asked was out of bounds of the board" << '\n';
        std::cout << "x = " << x << "\n";
        std::cout << "0 <= x < " << width() << '\n';
        throw std::exception("error: x out of bounds");
    }
        
    return squares[y][x].try_get_piece();
}

bool Board::is_within_board_boundaries(int x, int y) const
{
    std::cout << "hey, you made it to is_within_boundaries!" << "\n";
    
    bool x_success = x < width() && x >= 0;
    bool y_success = y < height() && y >= 0;

    return x_success && y_success;
}

//Method is called at the BEGINNING of each player's turn
void Board::increment_turn(Color current_turn_color)
{
    for (auto & square_column : squares)
    for (auto & square : square_column)
    {
        auto [success, piece] = square.try_get_piece();

        if (success && piece->get_color() == current_turn_color)
        {
            square.increment_turn();
        }
    }
}

bool Board::show_valid_moves(int x, int y)
{
    std::cout << "hey, you made it to show_valid_moves!" << "\n";
    
    const char* valid_moves_empty_space_color = colors::green;
    const char* valid_moves_opponent_space_color = colors::red;
    
    auto [contains_piece, piece] = try_get_piece(x, y);

    if (!contains_piece)
    {
        return false;
        //throw std::exception("error: valid moves for a piece were attempted to be shown, but the selected square did not have a piece");
    }

    std::vector<ValidMove> valid_moves = piece->get_valid_moves(this, x, y);

    //above obtains the valid squares to move to, below draws the squares
    for (ValidMove valid_move : valid_moves)
    {
        Square& square = squares[y + valid_move.delta_y][x + valid_move.delta_x];
        
        if (!square.contains_piece())
        {
            square.override_symbol("•");
            square.override_color(valid_moves_empty_space_color);
        }
        else
        {
            square.override_color(valid_moves_opponent_space_color);
        }
    }

    return true;
}

void Board::clear_graphical_overrides()
{
    for (auto& square_row : squares)
    for (auto& square : square_row)
    {
        square.clear_graphical_overrides();
    }
}

void Board::set_up(std::vector<std::tuple<std::shared_ptr<Piece>, int, int>>& pieces_and_locations)
{
    place_pieces(pieces_and_locations);
}

size_t Board::width() const
{
    if (squares.empty())
    {
        return 0;
    }
    
    return squares[0].size();
}

size_t Board::height() const
{
    return squares.size();
}

TerminalGraphic Board::get_graphic(int x, int y) const
{
    return squares[y][x].get_graphic();
}

std::vector<std::shared_ptr<Piece>> Board::place_pieces(std::vector<std::tuple<std::shared_ptr<Piece>, int, int>> pieces_and_locations)
{
    std::vector<std::shared_ptr<Piece>> removed_pieces;
    
    for (auto & piece_and_location : pieces_and_locations)
    {
        auto [piece, x, y] = piece_and_location;

        std::shared_ptr<Piece> removed_piece = squares[y][x].place_piece(piece);

        if (removed_piece != nullptr)
        {
            //Not exactly an error, but a good thing to not want to do accidentally
            throw std::exception("attempted to set up board, but placed a piece over another existing piece");
            removed_pieces.push_back(removed_piece);
        }
    }

    return removed_pieces;
}
