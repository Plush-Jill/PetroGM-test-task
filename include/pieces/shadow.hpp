//
// Created by plush-jill on 6/1/25.
//

#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "abstract-piece.hpp"
#include "attack-direction/linear-direction.hpp"
#include "creating/piece-registrar.hpp"

class Shadow final : public AbstractPiece {
private:
    static constexpr std::string    s_piece_name_   {"shadow"};
    static constexpr char           s_symbol_       {'S'};
    static PieceRegistrar           s_registrar_;

public:
    explicit                    Shadow      (const Position& position);

    void                        attack      (ChessBoard &board, const Position &target_position) override;

    [[nodiscard]] char          getSymbol   () const override;

    [[nodiscard]] std::string   getName     () const override;
};

#endif //SHADOW_HPP
