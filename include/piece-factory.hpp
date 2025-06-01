//
// Created by plush-jill on 4/24/25.
//

#ifndef PIECE_FACTORY_HPP
#define PIECE_FACTORY_HPP
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "pieces/abstract-piece.hpp"


class PieceFactory {
public:
    using Creator = std::function<std::unique_ptr<AbstractPiece>(const Position&)>;

private:
    std::map<std::string, Creator> m_creators;
    std::vector<std::string> m_piece_names;

public:
    PieceFactory() = default;

    /**
     * @brief Создание фигуры по имени.
     * @param name Имя фигуры.
     * @param position Позиция фигуры
     * @return Указатель на созданную фигуру или nullptr, если фигура не найдена.
     */
    [[nodiscard]] std::unique_ptr<AbstractPiece> create(const std::string &name, const Position &position) const;

    /**
     *
     * @return Инстанс синглтона.
     */
    static PieceFactory& instance();

    /**
     * @brief Регистрация фигуры в фабрике.
     * @param name Имя фигуры.
     * @param creator Функция создания фигуры.
     */
    void register_piece(const std::string& name, Creator creator);

    /**
     * @brief Получение списка доступных фигур.
     * @return std::vector<std::string> со всеми доступными фигурами.
     */
    [[nodiscard]] std::vector<std::string> get_available_pieces() const;
};

#endif //PIECE_FACTORY_HPP