//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/knight.hpp"

Knight::Knight(const Position &position) : AbstractPiece(position, s_symbol_) {
    std::vector<std::pair<int, int>> knight_moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    m_attack_directions_.push_back(std::make_unique<JumpDirection>(knight_moves));
}


PieceRegistrar Knight::s_registrar_ {
    s_piece_name_,
    [](const Position& position) -> std::unique_ptr<AbstractPiece> {
        return std::make_unique<Knight>(position);
    }
};

char Knight::getSymbol() const {
    return s_symbol_;
}

std::string Knight::getName() { return s_piece_name_;}
