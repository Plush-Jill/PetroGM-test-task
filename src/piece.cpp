//
// Created by plush-jill on 6/1/25.
//
#include "../include/piece.hpp"

Piece::Piece(const Position position, const char symbol) : m_position_(position), m_symbol_(symbol) {}

bool Piece::canAttack(const Position &target_position, const ChessBoard &board) const {
    for (const auto& direction : m_attack_directions_) {
        auto targets = direction->getPossibleTargets(target_position, board);
        for (const auto& target : targets) {
            if (target.getX() == target_position.getX() && target.getY() == target_position.getY()) {
                return true;
            }
        }
    }
    return false;
}
