#include <iostream>

#include "board-view.hpp"
#include "chess-board.hpp"
#include "piece-parser.hpp"
#include "../include/pieces/abstract-piece.hpp"
#include "pieces/king.hpp"

int main(const int argc, char** argv) {
    if (argc != 2) {
        std::cout << std::format("Usage: {} <path_to_pieces_file>\n", argv[0]);
        std::cout << std::format("Example: {} ./inputs/pieces.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    std::vector<std::unique_ptr<AbstractPiece>> pieces;

    try {
        pieces = PieceParser::parseFile(argv[1]);
    } catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        return EXIT_FAILURE;
    }

    for (const auto& piece : pieces) {
        std::cout << std::format("{} at ({},{})",
            piece->getName(),
            piece->getPosition().getX(),
            piece->getPosition().getY())
        << std::endl;
    }
    std::cout << "\n";



    auto board = std::make_shared<ChessBoard>();
    const auto view = std::make_shared<BoardView>(board);

    board->addPieces(std::move(pieces));
    view->render();
    view->show();
    std::cout << "\n";

    std::vector<AttackRelation> attack_relations = board->getAttackRelations();
    for (const AttackRelation& relation : attack_relations) {
        std::cout << relation.toString() << "\n";
    }
    std::cout << "\n";

    board->nextTurn();
    view->render();
    view->show();
    std::cout << "\n";

    attack_relations = board->getAttackRelations();
    for (const AttackRelation& relation : attack_relations) {
        std::cout << relation.toString() << "\n";
    }
    return 0;
}
