//
// Created by plush-jill on 6/1/25.
//

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <vector>
#include <memory>

#include "attack-relation.hpp"
#include "position.hpp"
#include "pieces/piece.hpp"


class ChessBoard {
private:
    int m_size_;
    std::vector<std::unique_ptr<Piece>> m_pieces_;

public:
    explicit ChessBoard(int size = 8);
    [[nodiscard]] bool isValidPosition(const Position& position) const;
    [[nodiscard]] bool hasPieceAt(const Position& position) const;
    void addPieces(std::vector<std::unique_ptr<Piece>>&& new_pieces);
    [[nodiscard]] std::vector<AttackRelation> getAttackRelations() const;

};



#endif //CHESS_BOARD_HPP
