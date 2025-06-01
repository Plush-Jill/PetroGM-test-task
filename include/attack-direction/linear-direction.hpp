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

    [[nodiscard]] std::vector<std::pair<int, int>> getPossibleTargets(const Position& from_position, const ChessBoard& board) const override {
        std::vector<std::pair<int, int>> targets;
        int distance = 1;

        while (m_max_distance_ == -1 || distance <= m_max_distance_) {
            int newX = from_position.first + m_offset_x_ * distance;
            int newY = from_position.second + m_offset_y_ * distance;

            if (!board.isValidPosition({newX, newY})) break;

            targets.emplace_back(newX, newY);

            if (board.hasPieceAt({newX, newY})) break;
            ++distance;
        }
        return targets;
    }
};



#endif //LINEAR_DIRECTION_HPP
