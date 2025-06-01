//
// Created by plush-jill on 6/1/25.
//

#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include <memory>

#include "piece.hpp"
#include "attack-direction/jump-direction.hpp"


class Knight : public Piece {
public:
    explicit Knight(const Position& position);
};



#endif //KNIGHT_HPP
