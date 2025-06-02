//
// Created by plush-jill on 6/1/25.
//

#ifndef BOARD_VIEW_HPP
#define BOARD_VIEW_HPP

#include <string>

#include "chess-board.hpp"

class BoardView {
private:
    std::weak_ptr<ChessBoard>   m_board_;
    std::string                 m_newest_render_;
    static constexpr char       s_empty_cell_       {'.'};

public:
    explicit    BoardView   (const std::weak_ptr<ChessBoard>& board);

    /**
     * @brief Смотрит на доску и формирует строку для отображения.
     */
    void        render      ();

    /**
     * @brief Отображает текущую строку на консоль.
     * Должен быть вызван после вызова BoardView::render().
     */
    void        show        () const;
};

#endif //BOARD_VIEW_HPP
