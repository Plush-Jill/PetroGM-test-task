//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/knight.hpp"

Knight::Knight(const Position &position) : Piece(position, 'N') {
    std::vector<std::pair<int, int>> knight_moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    m_attack_directions_.push_back(std::make_unique<JumpDirection>(knight_moves));
}
