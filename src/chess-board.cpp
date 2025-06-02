//
// Created by plush-jill on 6/1/25.
//

#include "../include/chess-board.hpp"

#include <algorithm>
#include <format>
#include <iostream>

#include "../include/pieces/abstract-piece.hpp"
#include "pieces/shadow-trace.hpp"

ChessBoard::ChessBoard(const int size) : m_size_(size) {
    m_pieces_ = std::vector<std::unique_ptr<AbstractPiece>>();
}

void ChessBoard::addPiece(std::unique_ptr<AbstractPiece> new_piece) {
    if (!new_piece) {
        throw std::invalid_argument("Cannot add a null piece.");
    }
    if (!isValidPosition(new_piece->getPosition())) {
        throw std::out_of_range(std::format(
            "Invalid position for piece: {} ({},{})",
            new_piece->getName(),
            new_piece->getPosition().getX(),
            new_piece->getPosition().getY()));
    }
    if (hasPieceAt(new_piece->getPosition())) {
        throw std::out_of_range(std::format(
            "Position already occupied for piece: {} ({},{})",
            new_piece->getName(),
            new_piece->getPosition().getX(),
            new_piece->getPosition().getY()));
    }
    m_pieces_.push_back(std::move(new_piece));

}

void ChessBoard::clear() {
    m_pieces_.clear();
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
        addPiece(std::move(piece));
    }
}

void ChessBoard::deletePieceAtIfExist(const Position position) {
    if (hasPieceAt(position)) {
        deletePieceAt(position);
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

const AbstractPiece& ChessBoard::getPieceAt(const Position& position) const {
    for (const auto& piece : m_pieces_) {
        if (piece->getPosition() == position) {
            return *piece;
        }
    }
    throw std::runtime_error(std::format(
        "No piece found at position ({},{})",
        position.getX(),
        position.getY()));
}

void ChessBoard::addShadowTrace(const Position &position) {
    if (isValidPosition(position) && !hasPieceAt(position)) {
        m_pieces_.push_back(std::make_unique<ShadowTrace>(position));
    } else {
        throw std::runtime_error(std::format(
            "Invalid position for shadow trace: ({},{})",
            position.getX(),
            position.getY()));
    }
}

void ChessBoard::attack(const Position &from, const Position &to) {
    if (hasPieceAt(from)) {
        try {
            getPieceAtP(from)->attack(*this, to);
        } catch (const std::runtime_error& error) {
            throw std::runtime_error(std::format(
                "Attack failed from ({},{}) to ({},{}): {}",
                from.getX(), from.getY(),
                to.getX(), to.getY(),
                error.what()));
        }
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
    cleanupTraces();
    decreaseShadowTraces();
}

void ChessBoard::makeTurn(const Position& from, const Position& to) {
    nextTurn();
    attack(from, to);
}

void ChessBoard::deletePieceAt(const Position& position) {
    if (!isValidPosition(position)) {
        throw std::out_of_range(std::format(
            "Invalid position for deletion: ({},{})",
            position.getX(),
            position.getY()));
    }
    for (auto it = m_pieces_.begin(); it != m_pieces_.end(); ++it) {
        if ((*it)->getPosition() == position) {
            m_pieces_.erase(it);
            return;
        }
    }
}

const std::unique_ptr<AbstractPiece>& ChessBoard::getPieceAtP(const Position &position) {
    for (const auto& piece : m_pieces_) {
        if (piece->getPosition() == position) {
            return piece;
        }
    }
    throw std::runtime_error(std::format(
        "No piece found at position ({},{})",
        position.getX(),
        position.getY()));
}

int ChessBoard::getSize() const { return m_size_; }

void ChessBoard::decreaseShadowTraces() {
    for (auto& piece : m_pieces_) {
        if (const auto trace = dynamic_cast<ShadowTrace*>(piece.get())) {
            trace->decreaseLifetime();
        }
    }
}
