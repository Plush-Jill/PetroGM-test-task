#include <iostream>
#include "chess-board.hpp"
#include "piece.hpp"
#include "pieces/king.hpp"

int main() {
    Piece* king = new King(Position(4, 4));

    std::unique_ptr<Piece> king2 = PieceFactory::instance().create("king", Position(4, 4));
    return 0;
}
