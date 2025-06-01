//
// Created by plush-jill on 6/1/25.
//

#ifndef ROOK_HPP
#define ROOK_HPP
#include <memory>

#include "piece-registrar.hpp"
#include "abstract-piece.hpp"
#include "attack-direction/linear-direction.hpp"

// Ладья
class Rook final : public AbstractPiece {
private:
    static constexpr std::string s_piece_name_ {"rook"};
    static constexpr char s_symbol_ {'R'};
    static PieceRegistrar s_registrar_;

public:
    explicit Rook(const Position& position);
    [[nodiscard]] char getSymbol() const override;
    [[nodiscard]] std::string getName() override;
};


#endif //ROOK_HPP
