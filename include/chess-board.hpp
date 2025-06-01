//
// Created by plush-jill on 6/1/25.
//

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <vector>
#include <memory>

#include "attack-relation.hpp"
#include "position.hpp"
#include "pieces/abstract-piece.hpp"


class ChessBoard {
private:
    int m_size_;
    std::vector<std::unique_ptr<AbstractPiece>> m_pieces_;
    void cleanupTraces();
public:
    explicit ChessBoard(int size = 8);
    [[nodiscard]] bool isValidPosition(const Position& position) const;
    [[nodiscard]] bool hasPieceAt(const Position& position) const;
    void addPieces(std::vector<std::unique_ptr<AbstractPiece>>&& new_pieces);
    [[nodiscard]] std::vector<AttackRelation> getAttackRelations() const;
    void addShadowTrace(const Position& position);
    [[nodiscard]] const AbstractPiece& getPieceAt(Position position) const;
    void nextTurn();
    [[nodiscard]] int getSize() const;

};



#endif //CHESS_BOARD_HPP
