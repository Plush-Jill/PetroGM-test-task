//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/queen.hpp"

Queen::Queen(const Position &position) : Piece(position, 'Q') {
    for (int dx = {-1}; dx <= 1; ++dx) {
        for (int dy {-1}; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
                m_attack_directions_.push_back(std::make_unique<LinearDirection>(dx, dy));
            }
        }
    }
}


PieceRegistrar Queen::s_registrar_ {
    s_piece_name_,
    [](const Position& position) -> std::unique_ptr<Piece> {
        return std::make_unique<Queen>(position);
    }
};

char Queen::getSymbol() const { return s_symbol_; }

std::string Queen::getName() { return s_piece_name_; }

