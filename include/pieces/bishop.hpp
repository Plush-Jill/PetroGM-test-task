//
// Created by plush-jill on 6/1/25.
//

#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "piece-registrar.hpp"
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Bishop final : public Piece {
private:
    static constexpr std::string s_piece_name_ {"bishop"};
    static constexpr char s_symbol_ {'B'};
    static PieceRegistrar s_registrar_;
public:
    explicit Bishop(const Position& position);
    [[nodiscard]] char getSymbol() const override;
};



#endif //BISHOP_HPP
