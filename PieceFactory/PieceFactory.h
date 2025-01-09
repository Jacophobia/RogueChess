#pragma once

#include <memory>

#include "../Piece/Color.h"
#include "../Piece/Piece.h"

class PieceFactory
{
public:
    static std::shared_ptr<Piece> build_pawn(Color color);
    static std::shared_ptr<Piece> build_queen(Color color);
private:
    static int determine_direction_piece_faces(Color color);
};
