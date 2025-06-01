//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_HPP
#define PIECE_HPP
#include <memory>
#include "attack-direction/attack-direction.hpp"
#include "chess-board.hpp"

class ChessBoard;
class AttackDirection;

class Piece {
protected:
    Position m_position_;
    char m_symbol_;
    std::vector<std::unique_ptr<AttackDirection>> m_attack_directions_;
public:
    virtual ~Piece() = default;

    virtual void move(const Position& position) {

    };

    [[nodiscard]] virtual constexpr char getSymbol() const = 0;

    Piece(const Position& position, const char symbol) : m_position_(position), m_symbol_(symbol) {}

    [[nodiscard]] virtual bool canAttack(const Position& target_position, const ChessBoard& board) const {
        for (const auto& direction : m_attack_directions_) {
            for (auto targets = direction->getPossibleTargets(m_position_, board);
                const auto&[x, y] : targets) {
                if (x == target_position.first && y == target_position.second) {
                    return true;
                }
            }
        }
        return false;
    }

    [[nodiscard]] virtual bool canBeAttacked() const = 0;
};



#endif //PIECE_HPP


