#pragma once
#include <string>
#include <vector>

#include "Color.h"
#include "../Upgrade/PieceUpgrade.h"
#include "../Move/PotentialMove.h"
#include "../Move/ValidMove.h"

class Board;

class Piece
{
public:
    Piece(Piece&) = delete;
    Piece(Color color, std::vector<PotentialMove> potential_moves)
    {
        this->color = color;
        this->potential_moves = potential_moves;
    }
    
    std::vector<ValidMove> get_valid_moves(Board& board) const;
    Color get_color();
    void increment_turn(bool is_piece_moved = false);
    std::string to_string() const;
    
private:
    std::vector<PotentialMove> potential_moves;
    std::vector<PieceUpgrade> upgrades;
    Color color = Color::white;
    bool has_moved = false;

    PotentialMove upgrade_potential_move(PotentialMove potential_move) const;
};
