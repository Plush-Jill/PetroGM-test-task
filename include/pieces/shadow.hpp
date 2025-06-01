//
// Created by plush-jill on 6/1/25.
//

#ifndef SHADOW_HPP
#define SHADOW_HPP
#include <memory>

#include "piece-registrar.hpp"
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Shadow final : public Piece {
private:
    static constexpr std::string s_piece_name_ {"shadow"};
    static constexpr char s_symbol_ {'S'};
    static PieceRegistrar s_registrar_;

public:
    explicit Shadow(const Position& position);
    [[nodiscard]] char getSymbol() const override;
    [[nodiscard]] std::string getName() override;
};



#endif //SHADOW_HPP
