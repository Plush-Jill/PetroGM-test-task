//
// Created by plush-jill on 6/1/25.
//

#ifndef POSITION_HPP
#define POSITION_HPP
#include <initializer_list>

class Position {
private:
    int m_x_;
    int m_y_;

public:
    explicit            Position    (int x, int y) noexcept;
                        Position    (const Position& other) noexcept;

    /**
     *
     * @throws std::invalid_argument() Если в списке инициализации не 2 элемента.
     */
                        Position    (std::initializer_list<int> coords) noexcept(false);
    [[nodiscard]] int   getX        () const noexcept;
    [[nodiscard]] int   getY        () const noexcept;
    void                setX        (int new_x) noexcept;
    void                setY        (int new_y) noexcept;
    Position& operator  =           (const Position& other) noexcept;
    bool operator       ==          (const Position& other) const noexcept;
};

#endif //POSITION_HPP
