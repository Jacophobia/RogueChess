#pragma once

#include <tuple>
#include <vector>

#include "../Piece/Piece.h"

class Square;

class Board
{
public:
    std::tuple<bool, Piece*> try_get_piece(int x, int y);
    bool is_within_board_boundaries(int x, int y) const;
    void increment_turn(Color current_turn_color);

    void set_up(std::vector<std::tuple<Piece*, int, int>>& pieces_and_locations);
    
private:
    std::vector<std::vector<Square>> squares;

    std::vector<Piece*> place_pieces(std::vector<std::tuple<Piece*, int, int>> pieces_and_locations);
};
