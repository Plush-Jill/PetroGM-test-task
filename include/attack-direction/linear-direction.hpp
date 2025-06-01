//
// Created by plush-jill on 6/1/25.
//

#ifndef LINEAR_DIRECTION_HPP
#define LINEAR_DIRECTION_HPP
#include <utility>
#include <vector>

#include "attack-direction.hpp"
class ChessBoard;

class LinearDirection final : public AttackDirection {
private:
    int m_offset_x_;
    int m_offset_y_;
    int m_max_distance_; // -1 для неограниченного
public:
    LinearDirection(const int offset_x, const int offset_y, const int max_distance = -1) :
    m_offset_x_(offset_x), m_offset_y_(offset_y), m_max_distance_(max_distance) {}
    [[nodiscard]] std::vector<Position> getPossibleTargets(const Position& from_position, const ChessBoard& board) const override;
};



#endif //LINEAR_DIRECTION_HPP
