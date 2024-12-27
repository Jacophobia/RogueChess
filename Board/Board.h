#pragma once
#include <tuple>
#include <vector>

#include "../Piece/Piece.h"

class Square;

class Board
{
public:
    std::tuple<bool, Piece*> try_get_piece(int x, int y);
private:
    std::vector<std::vector<Square>> squares;
    
};
