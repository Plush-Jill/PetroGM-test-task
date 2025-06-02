//
// Created by plush-jill on 6/1/25.
//

#ifndef PIECE_HPP
#define PIECE_HPP

#include <memory>

#include "../position.hpp"
#include "../attack-direction/abstract-attack-direction.hpp"
class ChessBoard;
class AbstractAttackDirection;

class AbstractPiece {
protected:
    static constexpr std::string    s_piece_name_ {"abstract-piece"};
    Position                        m_position_;
    char                            m_symbol_;
    std::vector<std::unique_ptr<AbstractAttackDirection>>   m_attack_directions_;
public:
    explicit                                AbstractPiece   (Position position, char symbol);

    virtual                                 ~AbstractPiece  ()          = default;

    /**
     *
     * @param board Доска, на которой будет проводиться атака
     * @param target_position Позиция на доске, на которую предполагается атака
     * @throws std::runtime_error Если атака невозможна
     */
    virtual void                            attack          (ChessBoard &board, const Position &target_position);

    /**
     *
     * @param target_position Позиция, на которую предполагается атака
     * @param board Доска, на которой будет проверяться возможность атаки
     * @return true, если атака возможна, иначе false
     */
    [[nodiscard]] bool                      canAttack       (const Position &target_position, const ChessBoard &board) const;

    /**
     *
     * @return true, если фигура может быть атакована, иначе false
     */
    [[nodiscard]] virtual bool              canBeAttacked   () const;

    /**
     *
     * @return Имя вида фигуры
     */
    [[nodiscard]] virtual std::string       getName         () const = 0;

    /**
     *
     * @return Текущая позиция фигуры на доске
     */
    [[nodiscard]] Position                  getPosition     () const;

    /**
     *
     * @return Символ для отрисовки, соответствующий данной фигуре
     */
    [[nodiscard]] virtual constexpr char    getSymbol       () const    = 0;

    /**
     *
     * @return Список направлений атаки данной фигуры
     */
    [[nodiscard]] const std::vector<std::unique_ptr<AbstractAttackDirection>>& getAttackDirections() const;
};

#endif //PIECE_HPP


