//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/bishop.hpp"

Bishop::Bishop(const Position &position) : Piece(position, 'B') {
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(1, 1));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(-1, 1));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(1, -1));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(-1, -1));
}


PieceRegistrar Bishop::s_registrar_ {
    s_piece_name_,
    [](const Position& position) -> std::unique_ptr<Piece> {
        return std::make_unique<Bishop>(position);
    }
};

char Bishop::getSymbol() const {
    return s_symbol_;
}