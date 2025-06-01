//
// Created by plush-jill on 6/1/25.
//

#ifndef ATTACK_DIRECTION_HPP
#define ATTACK_DIRECTION_HPP
#include <utility>
#include <vector>
#include "chess-board.hpp"

class ChessBoard;

class AttackDirection {
public:
    [[nodiscard]] virtual std::vector<std::pair<int, int>> getPossibleTargets(const Position& from_position, const ChessBoard& board) const = 0;
    virtual ~AttackDirection() = default;
};


#endif //ATTACK_DIRECTION_HPP
