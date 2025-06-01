//
// Created by plush-jill on 6/1/25.
//

#ifndef ROOK_HPP
#define ROOK_HPP
#include <memory>

#include "piece-registrar.hpp"
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"

// Ладья
class Rook final : public Piece {
private:
    static constexpr std::string s_piece_name_ {"rook"};
    static constexpr char s_symbol_ {'R'};
    static PieceRegistrar s_registrar_;

public:
    explicit Rook(const Position& position);
    [[nodiscard]] char getSymbol() const override;
};


#endif //ROOK_HPP
