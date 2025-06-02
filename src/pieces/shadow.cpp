//
// Created by plush-jill on 6/1/25.
//

#include "../../include/pieces/shadow.hpp"

#include <format>

#include "chess-board.hpp"
#include "pieces/shadow-trace.hpp"

Shadow::Shadow(const Position &position) : AbstractPiece(position, s_symbol_) {
    for (int dx {-1}; dx <= 1; ++dx) {
        for (int dy {-1}; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
                m_attack_directions_.push_back(std::make_unique<LinearDirection>(dx, dy));
            }
        }
    }
}

void Shadow::attack(ChessBoard &board, const Position &target_position) {
    const auto direction_it = std::ranges::find_if(m_attack_directions_,
                                             [this, &target_position, &board](const auto& direction) {
                                                 return direction->matchesTarget(m_position_, target_position, board);
                                             });

    if (direction_it != m_attack_directions_.end()) {
        auto path_positions = (*direction_it)->getPossibleTargets(m_position_, board);
        for (const auto& position : path_positions) {
            if (position == target_position) break;
            board.addShadowTrace(position);
        }
        Position old_position = m_position_;

        m_position_ = target_position;
        board.addShadowTrace(old_position);
    } else {
        throw std::runtime_error(std::format("No valid attack direction found from ({},{}) to ({},{})",
            m_position_.getX(), m_position_.getY(),
            target_position.getX(), target_position.getY()));
    }
}

char Shadow::getSymbol() const {
    return s_symbol_;
}

std::string Shadow::getName() const { return s_piece_name_; }


PieceRegistrar Shadow::s_registrar_ {
    s_piece_name_,
    [](const Position& position) -> std::unique_ptr<AbstractPiece> {
        return std::make_unique<Shadow>(position);
    }
};
