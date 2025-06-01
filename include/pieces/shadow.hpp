//
// Created by plush-jill on 6/1/25.
//

#ifndef SHADOW_HPP
#define SHADOW_HPP
#include <memory>

#include "piece.hpp"
#include "attack-direction/linear-direction.hpp"


class Shadow : public Piece {
public:
    explicit Shadow(const Position& position);
};



#endif //SHADOW_HPP
