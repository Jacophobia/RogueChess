#pragma once
#include <vector>

#include "Color.h"
#include "../Upgrade/PieceUpgrade.h"

class Board;
struct ValidMove;
struct PotentialMove;

class Piece
{
public:
    std::vector<ValidMove> get_valid_moves(Board& board);
    Color get_color();
private:
    std::vector<PotentialMove> potential_moves;
    std::vector<PieceUpgrade> upgrades;
    Color color;
};
