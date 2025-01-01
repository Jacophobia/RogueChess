#pragma once

#include <tuple>
#include <vector>

#include "../Piece/Piece.h"
#include "../UI/UI.h"

class Square;

class Board
{
public:
    Board(UI* ui);
    ~Board() = default;
    Board(Board&) = delete;
    
    std::tuple<bool, Piece*> try_get_piece(int x, int y);
    bool is_within_board_boundaries(int x, int y) const;
    void increment_turn(Color current_turn_color);
    bool show_valid_moves(int x, int y);

    void set_up(std::vector<std::tuple<Piece*, int, int>>& pieces_and_locations);
    [[nodiscard]] size_t width() const;
    [[nodiscard]] size_t height() const;
private:
    UI* ui;
    
    std::vector<std::vector<Square>> squares;

    std::vector<Piece*> place_pieces(std::vector<std::tuple<Piece*, int, int>> pieces_and_locations);
};
