//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_HPP
#define PIECE_HPP
#include <memory>
#include "../position.hpp"
#include "../attack-direction/abstract-attack-direction.hpp"

class ChessBoard;
class AbstractAttackDirection;

class AbstractPiece {
protected:
    static constexpr std::string s_piece_name_ {"abstract-piece"};
    Position m_position_;
    char m_symbol_;
    std::vector<std::unique_ptr<AbstractAttackDirection>> m_attack_directions_;
public:
    virtual ~AbstractPiece() = default;
    [[nodiscard]] virtual constexpr char getSymbol() const = 0;
    explicit AbstractPiece(Position position, char symbol);

    [[nodiscard]] bool canAttack(const Position &target_position, const ChessBoard &board) const;
    [[nodiscard]] virtual std::string getName() = 0;
    [[nodiscard]] virtual bool canBeAttacked() const;
    [[nodiscard]] Position getPosition() const;
    [[nodiscard]] const std::vector<std::unique_ptr<AbstractAttackDirection>>& getAttackDirections() const;
};



#endif //PIECE_HPP


