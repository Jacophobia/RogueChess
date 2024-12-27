#pragma once
#include <tuple>

class Piece;

class Square
{
public:
    std::tuple<bool, Piece*> try_get_piece();

private:
    Piece* piece;
    
};
