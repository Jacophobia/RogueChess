#include "Square.h"

#include "../Piece/Piece.h"

std::string Square::to_string() const
{
    return piece->to_string();
}
