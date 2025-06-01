//
// Created by plush-jill on 6/1/25.
//

#ifndef KING_HPP
#define KING_HPP
#include "piece-registrar.hpp"
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class King final : public Piece {
private:
    static constexpr std::string m_command_name_ {"king"};
    static constexpr char s_symbol_ {'K'};
    static PieceRegistrar s_registrar_;
public:
    explicit King(const Position& position);
    [[nodiscard]] bool canBeAttacked() const override;
    [[nodiscard]] char getSymbol() const override;
    [[nodiscard]] bool canAttack(const Position &target_position, const ChessBoard &board) const override;

};



#endif //KING_HPP
