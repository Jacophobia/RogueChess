#pragma once

#include <tuple>
#include <vector>

#include "../Piece/Piece.h"
#include "../UI/UI.h"

class Square;

class Board
{
public:
    ~Board() = default;
    Board(Board&) = delete;
    Board();
    
    std::tuple<bool, std::shared_ptr<Piece>> try_get_piece(int x, int y);
    bool is_within_board_boundaries(int x, int y) const;
    void increment_turn(Color current_turn_color);
    bool show_valid_moves(int x, int y);
    void clear_graphical_overrides();

    void set_up(std::vector<std::tuple<std::shared_ptr<Piece>, int, int>>& pieces_and_locations);
    [[nodiscard]] size_t width() const;
    [[nodiscard]] size_t height() const;

    TerminalGraphic get_graphic(int x, int y) const;
private:
    std::vector<std::vector<Square>> squares;

    std::vector<std::shared_ptr<Piece>> place_pieces(std::vector<std::tuple<std::shared_ptr<Piece>, int, int>> pieces_and_locations);
};
