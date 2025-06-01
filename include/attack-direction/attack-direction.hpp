//
// Created by plush-jill on 6/1/25.
//

#ifndef ATTACK_DIRECTION_HPP
#define ATTACK_DIRECTION_HPP
#include <vector>
#include "position.hpp"
#include "pieces/piece.hpp"
class ChessBoard;
class AttackDirection {
public:
    [[nodiscard]] virtual std::vector<Position> getPossibleTargets(const Position& from_position, const ChessBoard& board) const = 0;
    virtual ~AttackDirection() = default;
    bool canAttack(Position position, Position get_position, const ChessBoard & chess_board) const;
};


#endif //ATTACK_DIRECTION_HPP
