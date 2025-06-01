//
// Created by plush-jill on 6/1/25.
//

#ifndef BOARD_VIEW_HPP
#define BOARD_VIEW_HPP

#include "chess-board.hpp"
#include <string>

class BoardView {
public:
    explicit BoardView(const std::weak_ptr<ChessBoard>& board);
    void render();
    void show() const;
private:
    std::weak_ptr<ChessBoard> m_board_;
    static constexpr char s_empty_cell_ = '.';
    std::string m_newest_render_;
};


#endif //BOARD_VIEW_HPP
