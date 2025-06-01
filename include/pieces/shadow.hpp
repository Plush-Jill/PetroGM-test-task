//
// Created by plush-jill on 6/1/25.
//

#ifndef SHADOW_HPP
#define SHADOW_HPP
#include <memory>

#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Shadow : public Piece {
public:
    explicit Shadow(const Position& position) : Piece(position, 'S') {
        for (int dx {-1}; dx <= 1; ++dx) {
            for (int dy {-1}; dy <= 1; ++dy) {
                if (dx != 0 || dy != 0) {
                    m_attack_directions_.push_back(std::make_unique<LinearDirection>(dx, dy));
                }
            }
        }
    }
};



#endif //SHADOW_HPP
