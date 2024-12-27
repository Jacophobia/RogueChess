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
    Piece(Piece&) = delete;
    Piece(Color color, std::vector<PotentialMove> potential_moves)
    {
        this->color = color;
        this->potential_moves = potential_moves;
    }
    
    std::vector<ValidMove> get_valid_moves(Board& board);
    Color get_color();
    void increment_turn(bool is_piece_moved = false);
private:
    std::vector<PotentialMove> potential_moves = {};
    std::vector<PieceUpgrade> upgrades = {};
    Color color = Color::white;
    bool has_moved = false;
};
