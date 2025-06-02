//
// Created by plush-jill on 6/1/25.
//

#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "abstract-piece.hpp"
#include "attack-direction/linear-direction.hpp"
#include "creating/piece-registrar.hpp"

class Bishop final : public AbstractPiece {
private:
    static constexpr std::string        s_piece_name_   {"bishop"};
    static constexpr char               s_symbol_       {'B'};
    static PieceRegistrar               s_registrar_;
public:
    explicit                    Bishop      (const Position& position);

    [[nodiscard]] char          getSymbol   () const override;

    [[nodiscard]] std::string   getName     () const override;
};

#endif //BISHOP_HPP
