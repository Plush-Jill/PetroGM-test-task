#include <iostream>
#include "chess-board.hpp"
#include "piece.hpp"
#include "pieces/king.hpp"

int main() {
    Piece* king = new King(Position(4, 4));
    return 0;
}
