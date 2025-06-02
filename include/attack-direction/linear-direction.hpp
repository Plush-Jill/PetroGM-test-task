//
// Created by plush-jill on 6/1/25.
//

#ifndef LINEAR_DIRECTION_HPP
#define LINEAR_DIRECTION_HPP

#include <vector>

#include "abstract-attack-direction.hpp"
class ChessBoard;

class LinearDirection final : public AbstractAttackDirection {
private:
    int m_offset_x_;
    int m_offset_y_;
    int m_max_distance_; // -1 для неограниченного
public:
    LinearDirection                                             (int offset_x, int offset_y, int max_distance = -1);
    [[nodiscard]] std::vector<Position> getPossibleTargets      (const Position& from_position, const ChessBoard& board) const override;
};

#endif //LINEAR_DIRECTION_HPP
