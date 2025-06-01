//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_HPP
#define PIECE_HPP
#include <memory>
#include "../position.hpp"
#include "../attack-direction/attack-direction.hpp"

class ChessBoard;
class AttackDirection;

class Piece {
protected:
    static constexpr std::string s_piece_name_ {"piece"};
    Position m_position_;
    char m_symbol_;
    std::vector<std::unique_ptr<AttackDirection>> m_attack_directions_;
public:
    virtual ~Piece() = default;
    [[nodiscard]] virtual constexpr char getSymbol() const = 0;
    explicit Piece(Position position, char symbol);

    [[nodiscard]] bool canAttack(const Position &target_position, const ChessBoard &board) const;
    [[nodiscard]] virtual std::string getName() = 0;
    [[nodiscard]] virtual bool canBeAttacked() const;
    [[nodiscard]] Position getPosition() const;
    [[nodiscard]] const std::vector<std::unique_ptr<AttackDirection>>& getAttackDirections() const;
};



#endif //PIECE_HPP


