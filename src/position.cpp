//
// Created by plush-jill on 6/1/25.
//

#include "../include/position.hpp"

#include <stdexcept>

Position::Position(const int x, const int y) noexcept : m_x_(x), m_y_(y) {}

Position::Position(const Position &other) noexcept = default;

Position::Position(const std::initializer_list<int> coords) noexcept(false) {
    if (coords.size() != 2) {
        throw std::invalid_argument("Position brace initialization {x,y} requires exactly 2 coordinates");
    }
    m_x_ = *coords.begin();
    m_y_ = *(coords.begin() + 1);
}

int Position::getX() const noexcept { return m_x_; }

int Position::getY() const noexcept { return m_y_; }

void Position::setX(const int new_x) noexcept { m_x_ = new_x; }

void Position::setY(const int new_y) noexcept { m_y_ = new_y; }

Position& Position::operator=(const Position &other) noexcept = default;

bool Position::operator==(const Position &other) const noexcept {
    return m_x_ == other.m_x_ && m_y_ == other.m_y_;
}
