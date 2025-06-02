//
// Created by plush-jill on 6/1/25.
//

#include "creating/piece-registrar.hpp"

PieceRegistrar::PieceRegistrar(const std::string &name, PieceFactory::Creator creator) {
    PieceFactory::instance().register_piece(name, std::move(creator));
}
