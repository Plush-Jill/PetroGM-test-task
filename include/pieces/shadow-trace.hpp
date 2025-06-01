//
// Created by plush-jill on 6/1/25.
//

#ifndef SHADOW_TRACE_HPP
#define SHADOW_TRACE_HPP
#include "chess-board.hpp"
#include "piece.hpp"


class ShadowTrace final : public Piece {
private:
    static constexpr char s_symbol_ {'T'};
public:
    explicit ShadowTrace(const Position& position);
    [[nodiscard]] bool canAttack(const Position& target_position, const ChessBoard& board) const override;
    [[nodiscard]] bool canBeAttacked() const override;
    [[nodiscard]] char getSymbol() const override;
};



#endif //SHADOW_TRACE_HPP
