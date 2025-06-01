//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/shadow-trace.hpp"

ShadowTrace::ShadowTrace(const Position &position) : Piece(position, s_symbol_) {}

bool ShadowTrace::canAttack(const Position &target_position, const ChessBoard &board) {
    return false;
}

bool ShadowTrace::canBeAttacked() const {
    return false;
}

char ShadowTrace::getSymbol() const { return s_symbol_; }


PieceRegistrar ShadowTrace::s_registrar_ {
    s_piece_name_,
    [](const Position& position) -> std::unique_ptr<Piece> {
        return std::make_unique<ShadowTrace>(position);
    }
};

