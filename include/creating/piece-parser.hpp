//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_PARSER_HPP
#define PIECE_PARSER_HPP

#include <format>
#include <memory>
#include <string>
#include <vector>

#include "pieces/abstract-piece.hpp"

class PieceParser {
public:
                                                                        PieceParser () = default;
    [[nodiscard]] static std::vector<std::unique_ptr<AbstractPiece>>    parseFile   (const std::string& filename);
};

#endif //PIECE_PARSER_HPP
