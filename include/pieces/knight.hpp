//
// Created by plush-jill on 6/1/25.
//

#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include <memory>

#include "piece-registrar.hpp"
#include "piece.hpp"
#include "attack-direction/jump-direction.hpp"


class Knight final : public Piece {
private:
    static constexpr std::string s_piece_name_ {"knight"};
    static constexpr char s_symbol_ {'H'};
    static PieceRegistrar s_registrar_;

public:
    explicit Knight(const Position& position);
    [[nodiscard]] char getSymbol() const override;
};



#endif //KNIGHT_HPP
