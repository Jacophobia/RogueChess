#pragma once
#include <vector>

#include "../Upgrade/PieceUpgrade.h"

class Board;
struct ValidMove;
struct PotentialMove;

class Piece
{
public:
    std::vector<ValidMove> GetValidMoves(Board& board);
private:
    std::vector<PotentialMove> potential_moves;
    std::vector<PieceUpgrade> upgrades;
    
};
