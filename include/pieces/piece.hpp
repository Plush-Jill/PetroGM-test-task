//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_HPP
#define PIECE_HPP
#include <memory>
#include <utility>

#include "../position.hpp"
#include "../attack-direction/attack-direction.hpp"

class ChessBoard;
class AttackDirection;

class Piece {
protected:
    Position m_position_;
    char m_symbol_;
    std::vector<std::unique_ptr<AttackDirection>> m_attack_directions_;
public:
    virtual ~Piece() = default;
    // virtual void move(const Position& position) = 0;
    [[nodiscard]] virtual constexpr char getSymbol() const = 0;
    explicit Piece(Position position, char symbol);

    bool canAttack(const Position &target_position, const ChessBoard &board) const;

    [[nodiscard]] virtual bool canBeAttacked() const;
    [[nodiscard]] Position getPosition() const { return m_position_; }
};



#endif //PIECE_HPP


