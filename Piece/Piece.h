#pragma once

#include <vector>

#include "Color.h"
#include "PieceType.h"
#include "../Upgrade/PieceUpgrade.h"
#include "../Move/PotentialMove.h"
#include "../Move/ValidMove.h"
#include "../UI/TerminalGraphic.h"

class Board;

class Piece
{
public:
    Piece(Piece&) = delete;
    Piece(Color color, const std::vector<PotentialMove>& potential_moves, int rating, const std::string& symbol)
    {
        this->color = color;
        this->potential_moves = potential_moves;
        this->rating = rating;
        this->symbol = symbol;
    }
    Piece() = default;
    
    std::vector<ValidMove> get_valid_moves(Board* board, int x, int y) const;
    Color get_color();
    void increment_turn(bool is_piece_moved = false);
    [[nodiscard]] TerminalGraphic get_graphic() const;
    [[nodiscard]] PieceType get_type();
private:
    std::vector<PotentialMove> potential_moves;
    std::vector<PieceUpgrade> upgrades;
    Color color = Color::white;
    std::string symbol = "P";
    bool has_moved = false;
    int rating = 1;

    [[nodiscard]] PotentialMove upgrade_potential_move(PotentialMove potential_move) const;
};
