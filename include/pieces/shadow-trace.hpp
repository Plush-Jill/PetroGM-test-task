//
// Created by plush-jill on 6/1/25.
//

#ifndef SHADOW_TRACE_HPP
#define SHADOW_TRACE_HPP

#include "abstract-piece.hpp"
#include "creating/piece-registrar.hpp"

/**
 * @brief Класс, представляющий след тени.
 * След тени - это временная фигура, которая может быть создана тенью.
 * След тени не может быть атакован другими фигурами.
 */
class ShadowTrace final : public AbstractPiece {
private:
    int                             m_lifetime_     {1};
    static constexpr std::string    s_piece_name_   {"shadow_trace"};
    static PieceRegistrar           s_registrar_;
    static constexpr char           s_symbol_       {'T'};

public:
    explicit                    ShadowTrace         (const Position& position);

    [[nodiscard]] static bool   canAttack           (const Position &target_position, const ChessBoard &board);

    [[nodiscard]] bool          canBeAttacked       () const override;

    /**
     * @brief Уменьшает время жизни следа тени на единицу.
     */
    void                        decreaseLifetime    ();

    [[nodiscard]] std::string   getName             () const override;

    [[nodiscard]] char          getSymbol           () const override;

    /**
     *
     * @return true, если след тени истек, иначе false
     */
    [[nodiscard]] bool          isExpired           () const;

};



#endif //SHADOW_TRACE_HPP
