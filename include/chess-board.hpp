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
    int                                                 m_size_;
    std::vector<std::unique_ptr<AbstractPiece>>         m_pieces_;
    void                                                cleanupTraces();

    void                                                deletePieceAt       (const Position &position);

    void                                                decreaseShadowTraces();

    [[nodiscard]] const std::unique_ptr<AbstractPiece>& getPieceAtP          (const Position &position);

public:
    explicit                                            ChessBoard          (int size = 8);

    /**
     * @brief Добавляет новые фигуры на доску.
     * @param new_piece Добавляемая фигура
     * @throws std::invalid_argument Если передана пустая фигура (nullptr).
     * @throws std::out_of_range Если фигура пытается занять недопустимую позицию или если на этой позиции уже есть другая фигура.
     */
    void                                                addPiece            (std::unique_ptr<AbstractPiece> new_piece);

    /**
     * @brief Добавляет новые фигуры на доску.
     * @param new_pieces Вектор фигур, которые будут добавлены на доску.
     * @throws std::invalid_argument Если передана пустая фигура (nullptr).
     * @throws std::out_of_range Если фигура пытается занять недопустимую позицию или если на этой позиции уже есть другая фигура.
     */
    void                                                addPieces           (std::vector<std::unique_ptr<AbstractPiece>>&& new_pieces);

    /**
     *
     * @param position Место создания следа тени
     */
    void                                                addShadowTrace      (const Position& position);

    /**
     * @brief Заставляет фигуру атаковать другую фигуру на доске, если это возможно.
     * @param from Место, с которого предполагается атака
     * @param to Место, на которое предполагается атака
     * @throws std::runtime_error Случай, если фигура не может атаковать указанную позицию.
     */
    void                                                attack              (const Position& from, const Position& to);

    void                                                clear               ();

    void                                                deletePieceAtIfExist(Position position);

    /**
     * @brief Возвращает вектор отношений атаки между фигурами на доске.
     * @return Вектор отношений атак.
     */
    [[nodiscard]] std::vector<AttackRelation>           getAttackRelations  () const;

    /**
     * @brief Возвращает фигуру, находящуюся в заданной позиции.
     * @param position Позиция, в которой нужно найти фигуру.
     * @return Ссылка на фигуру в заданной позиции.
     * @throws std::runtime_error Если позиция недействительна или не содержит фигуры.
     */
    [[nodiscard]] const AbstractPiece&                  getPieceAt          (const Position &position) const;

    int                                                 getSize             () const;

    [[nodiscard]] bool                                  hasPieceAt          (const Position& position) const;

    /**
     *
     * @param position Позиция, которую нужно проверить.
     * @return True, если позиция допустима (в пределах доски) и на ней уже не стоит фигура, иначе false.
     */
    [[nodiscard]] bool                                  isValidPosition     (const Position& position) const;

    /**
     * @brief Обновление доски, в частности, уменьшение количества следов тени.
     */
    void                                                nextTurn            ();
};



#endif //CHESS_BOARD_HPP
