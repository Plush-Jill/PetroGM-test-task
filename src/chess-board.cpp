//
// Created by plush-jill on 6/1/25.
//

#include "../include/chess-board.hpp"

#include <algorithm>
#include <format>
#include <iostream>

#include "../include/pieces/piece.hpp"

ChessBoard::ChessBoard(const int size) : m_size_(size) {
    m_pieces_ = std::vector<std::unique_ptr<Piece>>();
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

void ChessBoard::addPieces(std::vector<std::unique_ptr<Piece>>&& new_pieces) {
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

// std::vector<AttackRelation> ChessBoard::getAttackRelations() const {
//     std::vector<AttackRelation> relations;
//
//     for (const auto& attacker : m_pieces_) {
//         for (const auto& target : m_pieces_) {
//             if (attacker != target && target->canBeAttacked()) {
//                 if (attacker->canAttack(target->getPosition(), *this)) {
//                     relations.emplace_back(
//                         attacker->getName(), attacker->getPosition(),
//                         target->getName(), target->getPosition());
//                 }
//             }
//         }
//     }
//
//     return relations;
// }


std::vector<AttackRelation> ChessBoard::getAttackRelations() const {
    std::vector<AttackRelation> relations;

    for (const auto& attacker : m_pieces_) {
        for (const auto& target : m_pieces_) {
            if (attacker != target) {
                bool canAttack = false;

                for (const auto& direction : attacker->getAttackDirections()) {
                    if (direction->canAttack(attacker->getPosition(), target->getPosition(), *this)) {
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