//
// Created by plush-jill on 6/1/25.
//

#include "../include/position.hpp"

Position::Position(const int x, const int y) : m_x_(x), m_y_(y) {}

Position::Position(const Position &other) = default;

int Position::getX() const { return m_x_; }

int Position::getY() const { return m_y_; }

void Position::setX(const int new_x) { m_x_ = new_x; }

void Position::setY(const int new_y) { m_y_ = new_y; }

Position& Position::operator=(const Position &other) = default;

bool Position::operator==(const Position &other) const {
    return m_x_ == other.m_x_ && m_y_ == other.m_y_;
}
