#include <iostream>
#include "chess-board.hpp"
#include "piece-parser.hpp"
#include "../include/pieces/piece.hpp"
#include "pieces/king.hpp"

int main() {
    auto pieces2 = PieceParser::parseFile("/home/plush-jill/All_Random/git/PetroGM-test-task/inputs/pieces.txt");
    for (const auto& piece : pieces2) {
        std::cout << std::format("{} at ({},{})",
            piece->getName(),
            piece->getPosition().getX(),
            piece->getPosition().getY())
        << std::endl;
    }
    ChessBoard board;
    board.addPieces(std::move(pieces2));
    std::vector<AttackRelation> attack_relations = board.getAttackRelations();
    for (const auto& relation : attack_relations) {
        std::cout << relation.toString() << std::endl;
    }

    return 0;
}
