//
// Created by plush-jill on 6/1/25.
//

#ifndef SHADOW_TRACE_HPP
#define SHADOW_TRACE_HPP
#include "chess-board.hpp"
#include "piece-registrar.hpp"
#include "abstract-piece.hpp"


class ShadowTrace final : public AbstractPiece {
private:
    static constexpr std::string s_piece_name_ {"shadow_trace"};
    static constexpr char s_symbol_ {'T'};
    static PieceRegistrar s_registrar_;
    int m_lifetime_ {1};

public:
    explicit ShadowTrace(const Position& position);
    [[nodiscard]] static bool canAttack(const Position &target_position, const ChessBoard &board);
    [[nodiscard]] bool canBeAttacked() const override;
    [[nodiscard]] char getSymbol() const override;
    [[nodiscard]] std::string getName() override;
    void decreaseLifetime();
    [[nodiscard]] bool isExpired() const;

};



#endif //SHADOW_TRACE_HPP
