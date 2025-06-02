//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_REGISTRAR_HPP
#define PIECE_REGISTRAR_HPP

#include <string>

#include "piece-factory.hpp"

class PieceRegistrar {
public:
    PieceRegistrar(const std::string& name, PieceFactory::Creator creator);
};

#endif //PIECE_REGISTRAR_HPP
