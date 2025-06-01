//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_PARSER_HPP
#define PIECE_PARSER_HPP


#include <format>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>

#include "pieces/piece.hpp"
#include "piece-factory.hpp"

class PieceParser {
private:
    PieceFactory& m_factory_;

public:
    PieceParser() : m_factory_(PieceFactory::instance()) {}

    [[nodiscard]] static std::vector<std::unique_ptr<Piece>> parseFile(const std::string& filename) {
        std::vector<std::unique_ptr<Piece>> pieces;
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
};



#endif //PIECE_PARSER_HPP
