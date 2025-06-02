//
// Created by plush-jill on 6/1/25.
//
#include "../../include/pieces/abstract-piece.hpp"

#include <iostream>

#include "chess-board.hpp"

AbstractPiece::AbstractPiece(const Position position, const char symbol) : m_position_(position), m_symbol_(symbol) {}

void AbstractPiece::attack(ChessBoard &board, const Position &target_position) {
    if (canAttack(target_position, board)) {
        board.deletePieceAtIfExist(target_position);
        m_position_ = target_position;
    }
    else {
        throw std::runtime_error(std::format(
            "Cannot attack position ({},{}) with piece {} at ({},{}).",
            target_position.getX(),
            target_position.getY(),
            getName(),
            m_position_.getX(),
            m_position_.getY()));
    }
}

bool AbstractPiece::canAttack(const Position &target_position, const ChessBoard &board) const {
    for (const auto& direction : m_attack_directions_) {
        auto targets = direction->getPossibleTargets(m_position_, board);  // Fixed here
        for (const auto& target : targets) {
            if (target == target_position) {
                return board.getPieceAt(target_position).canBeAttacked();
            }
        }
    }
    return false;
}

bool AbstractPiece::canBeAttacked() const {
    return true;
}

Position AbstractPiece::getPosition() const { return m_position_; }

const std::vector<std::unique_ptr<AbstractAttackDirection>>& AbstractPiece::getAttackDirections() const {
    return m_attack_directions_;
}
