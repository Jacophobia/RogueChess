#pragma once

enum class PieceType
{
    pawn = 0b000001,
    knight = 0b000010,
    bishop = 0b000100,
    rook = 0b001000,
    queen = 0b010000,
    king = 0b100000,
    wild = 0b111111,
};

namespace piece
{
    inline const char* to_string(PieceType e)
    {
        switch (e)
        {
        case PieceType::pawn: return "pawn";
        case PieceType::knight: return "knight";
        case PieceType::bishop: return "bishop";
        case PieceType::rook: return "rook";
        case PieceType::queen: return "queen";
        case PieceType::king: return "king";
        case PieceType::wild: return "wild";
        default: return "unknown";
        }
    }
}
