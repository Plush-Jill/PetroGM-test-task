//
// Created by plush-jill on 6/1/25.
//

#include "attack-direction/jump-direction.hpp"
#include "chess-board.hpp"
JumpDirection::JumpDirection(std::vector<std::pair<int, int>> jump_offsets) : m_offsets_(std::move(jump_offsets)) {}

std::vector<Position> JumpDirection::getPossibleTargets(const Position &from_position,
                                                                   const ChessBoard &board) const {
    std::vector<Position> targets;

    for (const auto&[x, y] : m_offsets_) {
        const Position new_position {from_position.getX() + x, from_position.getY() + y};

        if (board.isValidPosition(new_position)) {
            targets.push_back(new_position);
        }
    }
    return targets;
}
