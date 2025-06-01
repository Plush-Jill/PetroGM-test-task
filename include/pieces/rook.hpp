//
// Created by plush-jill on 6/1/25.
//

#ifndef ROOK_HPP
#define ROOK_HPP
#include <memory>

#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"

// Ладья
class Rook : public Piece {
public:
    explicit Rook(const Position& position);
};


#endif //ROOK_HPP
