#pragma once
#include <tuple>

class Piece;

class Square
{
public:
    std::tuple<bool, Piece*> try_get_piece();
    void increment_turn();
    Piece* place_piece(Piece* piece);

private:
    Piece* piece;
    bool was_piece_placed_here = false;
    
};
