//
// Created by plush-jill on 6/1/25.
//

#include "../include/board-view.hpp"

#include <iostream>
#include <sstream>

BoardView::BoardView(const std::weak_ptr<ChessBoard>& board) : m_board_(board) {}

void BoardView::render() {
    std::ostringstream output;
    const int size = m_board_.lock()->getSize();

    output << "  ";
    for (int x = 0; x < size; ++x) {
        output << x << ' ';
    }
    output << '\n';

    for (int y = size - 1; y >= 0; --y) {
        output << y << ' ';
        for (int x = 0; x < size; ++x) {
            if (Position position(x, y); m_board_.lock()->hasPieceAt(position)) {
                const auto& piece = m_board_.lock()->getPieceAt(position);
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
}

void BoardView::show() const {
    std::cout << m_newest_render_;
}

