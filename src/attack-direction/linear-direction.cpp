//
// Created by plush-jill on 6/1/25.
//

#include "../../include/attack-direction/linear-direction.hpp"
#include "../../include/chess-board.hpp"

std::vector<Position> LinearDirection::getPossibleTargets(const Position &from_position,
const ChessBoard &board) const  {
    std::vector<Position> targets;
    int distance = 1;

    while (m_max_distance_ == -1 || distance <= m_max_distance_) {
        int newX = from_position.getX() + m_offset_x_ * distance;
        int newY = from_position.getY() + m_offset_y_ * distance;
        Position new_position {newX, newY};
        if (!board.isValidPosition(new_position)) {
            break;
        }

        targets.emplace_back(newX, newY);

        if (board.hasPieceAt(new_position)) break;
        ++distance;
    }
    return targets;
}
