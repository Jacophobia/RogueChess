#pragma once

#include <memory>

#include "../Piece/Piece.h"
#include "../Piece/PieceType.h"

class Inventory {
public:
    // Define the custom iterator class
    class Iterator {
    public:
        Iterator(std::vector<std::shared_ptr<Piece>>::iterator it, std::vector<std::shared_ptr<Piece>>::iterator end, const PieceType type)
            : current(std::move(it)), end(std::move(end)), piece_type(type) {}

        std::shared_ptr<Piece> operator->() const
        {
            return *current;
        }
        
        std::shared_ptr<Piece> operator*() const
        {
            return *current;
        }

        Iterator& operator++() {
            do {
                ++current;
            } while (current != end && (*current)->get_type() != piece_type);
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

    private:
        std::vector<std::shared_ptr<Piece>>::iterator current;
        std::vector<std::shared_ptr<Piece>>::iterator end;
        PieceType piece_type;
    };

    // Methods to get iterators for specific piece types
    Iterator begin(const PieceType type) {
        auto it = pieces.begin();
        while (it != pieces.end() && (*it)->get_type() != type) {
            ++it;
        }
        return {it, pieces.end(), type};
    }

    Iterator end(PieceType type) {
        return {pieces.end(), pieces.end(), type}; // Just needs to match type
    }

    // Sample getter methods that return iterators
    Iterator get_pawns() { return begin(PieceType::pawn); }
    Iterator get_knights() { return begin(PieceType::knight); }
    Iterator get_bishops() { return begin(PieceType::bishop); }
    Iterator get_rooks() { return begin(PieceType::rook); }
    Iterator get_kings() { return begin(PieceType::king); }
    Iterator get_queens() { return begin(PieceType::queen); }
    Iterator get_wilds() { return begin(PieceType::wild); }

private:
    std::vector<std::shared_ptr<Piece>> pieces;
};

