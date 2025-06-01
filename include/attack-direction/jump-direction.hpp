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
    explicit JumpDirection(std::vector<std::pair<int, int>> jump_offsets);
    [[nodiscard]] std::vector<Position> getPossibleTargets(const Position& from_position, const ChessBoard& board) const override;
};



#endif //JUMP_DIRECTION_HPP
