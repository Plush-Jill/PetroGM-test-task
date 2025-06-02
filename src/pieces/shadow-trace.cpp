//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/shadow-trace.hpp"

ShadowTrace::ShadowTrace(const Position &position) : AbstractPiece(position, s_symbol_) {}

bool ShadowTrace::canAttack([[maybe_unused]] const Position &target_position, [[maybe_unused]] const ChessBoard &board) {
    return false;
}

bool ShadowTrace::canBeAttacked() const {
    return false;
}

char ShadowTrace::getSymbol() const { return s_symbol_; }

std::string ShadowTrace::getName() const { return s_piece_name_; }

void ShadowTrace::decreaseLifetime() { --m_lifetime_; }

bool ShadowTrace::isExpired() const { return m_lifetime_ <= 0; }


PieceRegistrar ShadowTrace::s_registrar_ {
    s_piece_name_,
    [](const Position& position) -> std::unique_ptr<AbstractPiece> {
        return std::make_unique<ShadowTrace>(position);
    }
};

