//
// Created by plush-jill on 6/1/25.
//

#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Queen : public Piece {
public:
    explicit Queen(const Position& position) : Piece(position, 'Q') {
        for (int dx = {-1}; dx <= 1; ++dx) {
            for (int dy {-1}; dy <= 1; ++dy) {
                if (dx != 0 || dy != 0) {
                    m_attack_directions_.push_back(std::make_unique<LinearDirection>(dx, dy));
                }
            }
        }
    }
};



#endif //QUEEN_HPP
