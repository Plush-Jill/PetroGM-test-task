//
// Created by plush-jill on 6/1/25.
//

#ifndef ROOK_HPP
#define ROOK_HPP
#include <memory>

#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"

// Ладья
class Rook : public Piece {
public:
    explicit Rook(const Position& position) : Piece(position, 'R') {
        m_attack_directions_.push_back(std::make_unique<LinearDirection>(1, 0));
        m_attack_directions_.push_back(std::make_unique<LinearDirection>(-1, 0));
        m_attack_directions_.push_back(std::make_unique<LinearDirection>(0, 1));
        m_attack_directions_.push_back(std::make_unique<LinearDirection>(0, -1));
    }
};


#endif //ROOK_HPP
