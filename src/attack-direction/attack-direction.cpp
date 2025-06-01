//
// Created by plush-jill on 6/1/25.
//

#include "attack-direction/attack-direction.hpp"

bool AttackDirection::canAttack(Position position, Position target_position, const ChessBoard& chess_board) const {
    auto possible_targets = getPossibleTargets(position, chess_board);
    return std::ranges::find(possible_targets, target_position) != possible_targets.end();
}
