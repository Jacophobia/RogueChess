#pragma once

#include <memory>

#include "../Piece/Color.h"
#include "../Piece/Piece.h"

class PieceFactory
{
public:
    std::shared_ptr<Piece> build_pawn(Color color);
    
    
};
