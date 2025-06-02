//
// Created by plush-jill on 6/1/25.
//

#include "attack-direction/abstract-attack-direction.hpp"

#include <algorithm>

bool AbstractAttackDirection::canAttack(const Position position, const Position target_position, const ChessBoard& chess_board) const {
    auto possible_targets = getPossibleTargets(position, chess_board);
    return std::ranges::find(possible_targets, target_position) != possible_targets.end();
}

bool AbstractAttackDirection::matchesTarget(const Position &from_position, const Position &target_position,
const ChessBoard &board) const {
    auto targets = getPossibleTargets(from_position, board);
    return std::ranges::find(targets, target_position) != targets.end();
}
