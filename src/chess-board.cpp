//
// Created by plush-jill on 6/1/25.
//

#include "../include/chess-board.hpp"
#include "../include/piece.hpp"

bool ChessBoard::isValidPosition(const Position &position) const {
    return
    (position.getX() >= 0 && position.getX() < m_size_) &&
    (position.getY() >= 0 && position.getY() < m_size_);
}

bool ChessBoard::hasPieceAt(const Position &position) const {
    return getPieceAt(position) != nullptr;
}

Piece* ChessBoard::getPieceAt(const Position &position) const {

    return nullptr;
}
