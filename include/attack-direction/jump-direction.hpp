//
// Created by plush-jill on 6/1/25.
//

#ifndef JUMP_DIRECTION_HPP
#define JUMP_DIRECTION_HPP

#include <vector>
#include <utility>

#include "abstract-attack-direction.hpp"

class JumpDirection final : public AbstractAttackDirection {
private:
    std::vector<std::pair<int, int>>        m_offsets_;
public:
    explicit                                JumpDirection           (std::vector<std::pair<int, int>> jump_offsets);
    [[nodiscard]] std::vector<Position>     getPossibleTargets      (const Position& from_position, const ChessBoard& board) const override;
};

#endif //JUMP_DIRECTION_HPP
