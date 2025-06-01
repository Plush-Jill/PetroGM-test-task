//
// Created by plush-jill on 6/1/25.
//

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <vector>
#include <memory>

#include "piece.hpp"
#include "position.hpp"
class Piece;

class ChessBoard {
private:
    int m_size_;
    std::vector<std::unique_ptr<Piece>> pieces;

public:
    explicit ChessBoard(const int size = 8) : m_size_(size) {};
    [[nodiscard]] bool isValidPosition(const Position& position) const;
    [[nodiscard]] bool hasPieceAt(const Position& position) const;
    [[nodiscard]] Piece* getPieceAt(const Position& position) const;


};



#endif //CHESS_BOARD_HPP
