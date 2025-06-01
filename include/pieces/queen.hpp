//
// Created by plush-jill on 6/1/25.
//

#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Queen : public Piece {
public:
    explicit Queen(const Position& position);
};



#endif //QUEEN_HPP
