//
// Created by plush-jill on 6/1/25.
//

#include "pieces/king.hpp"

King::King(const Position &position) : Piece(position, s_symbol_) {
    for (int dx {-1}; dx <= 1; ++dx) {
        for (int dy {-1}; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
                m_attack_directions_.push_back(std::make_unique<LinearDirection>(dx, dy, 1));
            }
        }
    }
}

bool King::canBeAttacked() const {
    return true;
}

char King::getSymbol() const { return s_symbol_; }

bool King::canAttack(const Position &target_position, const ChessBoard &board) const {
    return true;
}
