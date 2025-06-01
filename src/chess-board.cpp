//
// Created by plush-jill on 6/1/25.
//

#include "../include/chess-board.hpp"

#include <algorithm>
#include <format>

#include "../include/pieces/abstract-piece.hpp"
#include "pieces/shadow-trace.hpp"

ChessBoard::ChessBoard(const int size) : m_size_(size) {
    m_pieces_ = std::vector<std::unique_ptr<AbstractPiece>>();
}

bool ChessBoard::isValidPosition(const Position &position) const {
    return
    (position.getX() >= 0 && position.getX() < m_size_) &&
    (position.getY() >= 0 && position.getY() < m_size_);
}

bool ChessBoard::hasPieceAt(const Position& position) const {
    return std::ranges::any_of(m_pieces_,
                               [&position](const auto& piece) {
                                   return piece->getPosition() == position;
                               });
}

void ChessBoard::addPieces(std::vector<std::unique_ptr<AbstractPiece>>&& new_pieces) {
    for (auto& piece : new_pieces) {
        if (isValidPosition(piece->getPosition()) && !hasPieceAt(piece->getPosition())) {
            m_pieces_.push_back(std::move(piece));
        } else {
            throw std::out_of_range(std::format(
                "Invalid position for piece: {} ({},{})",
                piece->getName(),
                piece->getPosition().getX(),
                piece->getPosition().getY()));
        }
    }
}

std::vector<AttackRelation> ChessBoard::getAttackRelations() const {
    std::vector<AttackRelation> relations;

    for (const auto& attacker : m_pieces_) {
        for (const auto& target : m_pieces_) {
            if (attacker != target) {
                bool canAttack = false;

                for (const auto& direction : attacker->getAttackDirections()) {
                    if (direction->canAttack(attacker->getPosition(), target->getPosition(), *this)
                        && target->canBeAttacked()) {
                        canAttack = true;
                        break;
                    }
                }

                if (canAttack) {
                    relations.emplace_back(
                    attacker->getName(), attacker->getPosition(),
                    target->getName(), target->getPosition());
                }
            }
        }
    }

    return relations;
}

void ChessBoard::addShadowTrace(const Position &position) {
    if (isValidPosition(position) && !hasPieceAt(position)) {
        m_pieces_.push_back(std::make_unique<ShadowTrace>(position));
    }
}

void ChessBoard::cleanupTraces() {
    const auto it = std::ranges::remove_if(m_pieces_,
                                     [](const auto& piece) {
                                         if (const auto trace = dynamic_cast<ShadowTrace*>(piece.get())) {
                                             return trace->isExpired();
                                         }
                                         return false;
                                     }).begin();
    m_pieces_.erase(it, m_pieces_.end());
}

void ChessBoard::nextTurn() {
    for (auto& piece : m_pieces_) {
        if (const auto trace = dynamic_cast<ShadowTrace*>(piece.get())) {
            trace->decreaseLifetime();
        }
    }
    cleanupTraces();
}

const AbstractPiece& ChessBoard::getPieceAt(const Position position) const {
    for (const auto& piece : m_pieces_) {
        if (piece->getPosition() == position) {
            return *piece;
        }
    }
    throw std::out_of_range(std::format(
        "No piece found at position ({},{})",
        position.getX(),
        position.getY()));
}

int ChessBoard::getSize() const { return m_size_; }
