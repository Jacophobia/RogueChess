#pragma once
#include <tuple>

#include <string>

class Piece;

class Square
{
public:
    std::tuple<bool, Piece*> try_get_piece();
    void increment_turn();
    Piece* place_piece(Piece* piece);

    void change_color(/*still needs arguments*/);
    std::string to_string() const;

private:
    Piece* piece = nullptr;
    bool was_piece_placed_here = false;
};
