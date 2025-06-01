//
// Created by plush-jill on 6/1/25.
//

#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "piece-registrar.hpp"
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Queen final : public Piece {
private:
    static constexpr std::string s_piece_name_ {"queen"};
    static constexpr char s_symbol_ {'Q'};
    static PieceRegistrar s_registrar_;

public:
    explicit Queen(const Position& position);
    [[nodiscard]] char getSymbol() const override;
};



#endif //QUEEN_HPP
