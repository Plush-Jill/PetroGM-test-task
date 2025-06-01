//
// Created by plush-jill on 6/1/25.
//

#include "piece-factory.hpp"

PieceFactory& PieceFactory::instance() {
    static PieceFactory factory;
    return factory;
}

std::unique_ptr<Piece> PieceFactory::create(const std::string& name, const Position& position) const {
    if (const auto it = m_creators.find(name); it != m_creators.end()) {
        return it->second(position);
    }
    return nullptr;
}

void PieceFactory::register_piece(const std::string& name, Creator creator) {
    m_creators[name] = std::move(creator);
    m_piece_names.push_back(name);
}


std::vector<std::string> PieceFactory::get_available_pieces() const {
    return m_piece_names;
}