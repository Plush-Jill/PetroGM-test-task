//
// Created by plush-jill on 6/1/25.
//

#include "pieces/rook.hpp"

Rook::Rook(const Position &position) : Piece(position, 'R') {
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(1, 0));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(-1, 0));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(0, 1));
    m_attack_directions_.push_back(std::make_unique<LinearDirection>(0, -1));
}
