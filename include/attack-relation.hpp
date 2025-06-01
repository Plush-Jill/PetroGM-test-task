//
// Created by plush-jill on 6/1/25.
//

#ifndef ATTACK_RELATION_HPP
#define ATTACK_RELATION_HPP


#include <format>
#include "pieces/piece.hpp"
#include <string>

class AttackRelation {
private:
    const std::string m_attacker_name_;
    const Position m_attacker_position_;
    const std::string m_target_name_;
    const Position m_target_position_;

public:
    AttackRelation(
        std::string attacker_name, Position attacker_position,
        std::string target_name, Position target_position);

    [[nodiscard]] std::string getAttackerName() const;
    [[nodiscard]] Position getAttackerPosition() const;
    [[nodiscard]] std::string getTargetName() const;
    [[nodiscard]] Position getTargetPosition() const;

    [[nodiscard]] std::string toString() const;
};



#endif //ATTACK_RELATION_HPP
