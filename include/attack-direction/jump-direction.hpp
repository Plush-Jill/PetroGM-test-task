//
// Created by plush-jill on 6/1/25.
//

#ifndef JUMP_DIRECTION_HPP
#define JUMP_DIRECTION_HPP
#include <utility>
#include <vector>

#include "attack-direction.hpp"


class JumpDirection final : public AttackDirection {
private:
    std::vector<std::pair<int, int>> m_offsets_;
public:
    explicit JumpDirection(std::vector<std::pair<int, int>> jump_offsets) : m_offsets_(std::move(jump_offsets)) {}

    [[nodiscard]] std::vector<std::pair<int, int>> getPossibleTargets(const Position& from_position, const ChessBoard& board) const override {
        std::vector<std::pair<int, int>> targets;

        for (const auto&[x, y] : m_offsets_) {
            const Position new_position = {from_position.first + x, from_position.second + y};

            if (board.isValidPosition(new_position)) {
                targets.push_back(new_position);
            }
        }
        return targets;
    }
};



#endif //JUMP_DIRECTION_HPP
