//
// Created by plush-jill on 6/1/25.
//

#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "abstract-piece.hpp"
#include "attack-direction/linear-direction.hpp"
#include "creating/piece-registrar.hpp"

class Queen final : public AbstractPiece {
private:
    static constexpr std::string    s_piece_name_   {"queen"};
    static constexpr char           s_symbol_       {'Q'};
    static PieceRegistrar           s_registrar_;

public:
    explicit                    Queen       (const Position& position);

    [[nodiscard]] char          getSymbol   () const override;

    [[nodiscard]] std::string   getName     () const override;
};

#endif //QUEEN_HPP
