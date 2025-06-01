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
