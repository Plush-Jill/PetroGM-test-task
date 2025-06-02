//
// Created by plush-jill on 6/1/25.
//

#ifndef KING_HPP
#define KING_HPP

#include "abstract-piece.hpp"
#include "attack-direction/linear-direction.hpp"
#include "creating/piece-registrar.hpp"

class King final : public AbstractPiece {
private:
    static constexpr std::string    s_piece_name_   {"king"};
    static constexpr char           s_symbol_       {'K'};
    static PieceRegistrar           s_registrar_;
public:
    explicit                    King        (const Position& position);

    [[nodiscard]] char          getSymbol   () const override;

    [[nodiscard]] std::string   getName     () const override;
};

#endif //KING_HPP
