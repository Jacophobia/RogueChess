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
    void increment_turn();
private:
    std::vector<std::vector<Square>> squares;
};
