//
// Created by plush-jill on 6/1/25.
//

#include "pieces/rook.hpp"

Rook::Rook(const Position &position) : AbstractPiece(position, s_symbol_) {
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(1, 0));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(-1, 0));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(0, 1));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(0, -1));
}


PieceRegistrar Rook::s_registrar_ {
    s_piece_name_,
    [](const Position& position) -> std::unique_ptr<AbstractPiece> {
        return std::make_unique<Rook>(position);
    }
};


char Rook::getSymbol() const {
    return s_symbol_;
}

std::string Rook::getName() const { return s_piece_name_; }
