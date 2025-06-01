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
    explicit ShadowTrace(const Position& position) : Piece(position, s_symbol_) {}

    [[nodiscard]] bool canAttack(const Position& target_position, const ChessBoard& board) const override {
        return false;
    }

    [[nodiscard]] bool canBeAttacked() const override {
        return false;
    }

    [[nodiscard]] char getSymbol() const override { return s_symbol_; }
};



#endif //SHADOW_TRACE_HPP
