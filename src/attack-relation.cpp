//
// Created by plush-jill on 6/1/25.
//

#include "../include/attack-relation.hpp"

#include <utility>

AttackRelation::AttackRelation(
    std::string attacker_name,
    const Position attacker_position,
    std::string target_name,
    const Position target_position) :
m_attacker_name_(std::move(attacker_name)), m_attacker_position_(attacker_position),
m_target_name_(std::move(target_name)), m_target_position_(target_position) {

}

std::string AttackRelation::getAttackerName() const { return m_attacker_name_; }

Position AttackRelation::getAttackerPosition() const { return m_attacker_position_; }

std::string AttackRelation::getTargetName() const { return m_target_name_; }

Position AttackRelation::getTargetPosition() const { return m_target_position_; }

std::string AttackRelation::toString() const {
    return std::format("{} at ({},{}) can attack {} at ({},{})",
        m_attacker_name_,
        m_attacker_position_.getX(),
        m_attacker_position_.getY(),
        m_target_name_,
        m_target_position_.getX(),
        m_target_position_.getY());
}
