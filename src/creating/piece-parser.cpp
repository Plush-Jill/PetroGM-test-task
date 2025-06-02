//
// Created by plush-jill on 6/1/25.
//

#include <iostream>
#include <fstream>

#include "creating/piece-parser.hpp"
#include "creating/piece-factory.hpp"
#include "pieces/abstract-piece.hpp"

std::vector<std::unique_ptr<AbstractPiece>> PieceParser::parseFile(const std::string &filename) {
    std::vector<std::unique_ptr<AbstractPiece>> pieces;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string piece_type;
    int x, y;

    while (file >> piece_type >> x >> y) {
        try {
            if (auto piece = PieceFactory::instance().create(piece_type, Position(x, y))) {
                pieces.push_back(std::move(piece));
            } else {
                std::cout << std::format("Unknown piece type: {}", piece_type) << std::endl;
            }
        } catch (const std::exception& e) {
        }
    }

    return pieces;
}
