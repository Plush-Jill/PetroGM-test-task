//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_REGISTRAR_HPP
#define PIECE_REGISTRAR_HPP


#include "piece-factory.hpp"
#include <string>

class PieceRegistrar {
public:
    PieceRegistrar(const std::string& name, PieceFactory::Creator creator) {
        PieceFactory::instance().register_piece(name, std::move(creator));
    }
};



#endif //PIECE_REGISTRAR_HPP
