//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/shadow-trace.hpp"

ShadowTrace::ShadowTrace(const Position &position) : Piece(position, s_symbol_) {}

bool ShadowTrace::canAttack(const Position &target_position, const ChessBoard &board) const {
    return false;
}

bool ShadowTrace::canBeAttacked() const {
    return false;
}

char ShadowTrace::getSymbol() const { return s_symbol_; }
