//
// Created by plush-jill on 6/1/25.
//

#ifndef KING_HPP
#define KING_HPP
#include "piece-registrar.hpp"
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class King final : public Piece {
private:
    static constexpr std::string s_piece_name_ {"king"};
    static constexpr char s_symbol_ {'K'};
    static PieceRegistrar s_registrar_;
public:
    explicit King(const Position& position);
    [[nodiscard]] char getSymbol() const override;

};



#endif //KING_HPP
