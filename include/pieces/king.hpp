//
// Created by plush-jill on 6/1/25.
//

#ifndef KING_HPP
#define KING_HPP
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class King final : public Piece {
private:
    static constexpr char s_symbol_ {'K'};
public:
    explicit King(const Position& position) : Piece(position, s_symbol_) {
        for (int dx {-1}; dx <= 1; ++dx) {
            for (int dy {-1}; dy <= 1; ++dy) {
                if (dx != 0 || dy != 0) {
                    m_attack_directions_.push_back(std::make_unique<LinearDirection>(dx, dy, 1));
                }
            }
        }
    }

    [[nodiscard]] bool canBeAttacked() const override {
        return true;
    }

    [[nodiscard]] char getSymbol() const override { return s_symbol_; }
};



#endif //KING_HPP
