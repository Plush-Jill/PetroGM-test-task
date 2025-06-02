//
// Created by plush-jill on 6/1/25.
//

#include "../include/board-view.hpp"

#include <iostream>
#include <sstream>

BoardView::BoardView(const std::weak_ptr<ChessBoard>& board) : m_board_(board) {
    m_attack_relations_ = std::vector<AttackRelation>();
}

void BoardView::render() {
    const auto board = m_board_.lock();
    if (!board) {
        throw std::runtime_error("Board pointer expired");
    }

    std::ostringstream output;
    const int size = board->getSize();

    output << "  ";
    for (int x = 0; x < size; ++x) {
        output << x << ' ';
    }
    output << '\n';

    for (int y {size - 1}; y >= 0; --y) {
        output << y << ' ';
        for (int x {}; x < size; ++x) {
            if (Position position(x, y); board->hasPieceAt(position)) {
                const auto& piece = board->getPieceAt(position);
                output << piece.getSymbol() << ' ';
            } else {
                output << s_empty_cell_ << ' ';
            }
        }
        output << y << '\n';
    }

    output << "  ";
    for (int x = 0; x < size; ++x) {
        output << x << ' ';
    }
    output << '\n';
    m_newest_render_ = output.str();

    m_attack_relations_ = board->getAttackRelations();
}

void BoardView::showField() const {
    std::cout << m_newest_render_;
}

void BoardView::showAttackRelations() const {
    for (const auto& relation : m_attack_relations_) {
        std::cout << std::format("{} at ({},{}) can attack {} at ({},{})\n",
                                 relation.getAttackerName(),
                                 relation.getAttackerPosition().getX(),
                                 relation.getAttackerPosition().getY(),
                                 relation.getTargetName(),
                                 relation.getTargetPosition().getX(),
                                 relation.getTargetPosition().getY());
    }
}

