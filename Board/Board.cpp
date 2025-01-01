#include "Board.h"

#include <iostream>

#include "../Square/Square.h"
#include "../Move/PotentialMove.h"
#include "../Piece/PieceType.h"

Board::Board(UI* ui)
{
    this->ui = ui;
    
    ui->display_board(squares);
}

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
    bool x_success = x >= squares.size() || x < 0;
    bool y_success = y >= squares[x].size() || y < 0;

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
    auto [success, Piece] = try_get_piece(x, y);

    if (success)
    {
        ui->
    }
}

void Board::set_up(std::vector<std::tuple<Piece*, int, int>>& pieces_and_locations)
{
    place_pieces(pieces_and_locations);
}

//TODO: Rework this method, it kind of sucks and I don't love the parameter 
std::vector<Piece*> Board::place_pieces(std::vector<std::tuple<Piece*, int, int>> pieces_and_locations)
{
    std::vector<Piece*> removed_pieces;
    
    for (auto & piece_and_location : pieces_and_locations)
    {
        auto [piece, x, y] = piece_and_location;

        Piece* removed_piece = squares[x][y].place_piece(piece);

        if (removed_piece != nullptr)
        {
            removed_pieces.push_back(removed_piece);
        }
    }

    return removed_pieces;
}
