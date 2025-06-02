//
// Created by plush-jill on 6/1/25.
//

#ifndef ATTACK_DIRECTION_HPP
#define ATTACK_DIRECTION_HPP

#include <vector>

#include "position.hpp"
class ChessBoard;

/**
 * @brief Абстрактный класс для направления атаки.
 * Определяет интерфейс для проверки возможности атаки и получения возможных позиций для атаки.
 */
class AbstractAttackDirection {
public:
    virtual                                         ~AbstractAttackDirection    ()                                                              = default;

    /**
     *
     * @param position Позиция, с которой предполагается атака
     * @param target_position Позиция, на которую предполагается атака
     * @param chess_board Доска, на которой будет проверяться возможность атаки
     * @return true, если атака возможна, иначе false
     */
    [[nodiscard]] bool                              canAttack                   (Position position, Position target_position, const ChessBoard & chess_board) const;

    /**
     * @brief Проверка возможности атаки с заданной позиции на указанную позицию. Атака это не обязательно уничтожение другой фигуры, но и просто движение.
     * @param from_position Позиция, с которой будет проверяться возможность атаки
     * @param board Доска, на которой будет проверка
     * @return Вектор возможных позиций для атаки
     */
    [[nodiscard]] virtual std::vector<Position>     getPossibleTargets          (const Position& from_position, const ChessBoard& board) const  = 0;

    /**
     *
     * @param from_position Позиция, с которой будет проверка возможности атаки
     * @param target_position Позиция, на которую предполагается атака
     * @param board Доска, на которой это происходит
     * @return True, если атака возможна по этому направлению, иначе false
     */
    [[nodiscard]] bool                              matchesTarget               (const Position& from_position,
                                                                                 const Position& target_position,
                                                                                 const ChessBoard& board) const;
};

#endif //ATTACK_DIRECTION_HPP
