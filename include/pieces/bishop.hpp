//
// Created by plush-jill on 6/1/25.
//

#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Bishop : public Piece {
public:
    explicit Bishop(const Position& position);
};



#endif //BISHOP_HPP
