#include <iostream>
#include "chess-board.hpp"
#include "../include/pieces/piece.hpp"
#include "pieces/king.hpp"

int main() {
    Piece* king = new King(Position(4, 4));

    std::unique_ptr<Piece> king2 = PieceFactory::instance().create("king", Position(4, 4));
    auto pieces = PieceFactory::instance().get_available_pieces();
    for (const auto& piece_name : pieces) {
        std::cout << piece_name << std::endl;
    }
    return 0;
}
