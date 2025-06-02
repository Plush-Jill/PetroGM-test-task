#include <iostream>

#include "board-view.hpp"
#include "chess-board.hpp"
#include "creating/piece-parser.hpp"
#include "../include/pieces/abstract-piece.hpp"

int main(const int argc, char** argv) {
    if (argc != 2) {
        std::cout << std::format("Usage: {} <path_to_pieces_file>\n", argv[0]);
        std::cout << std::format("Example: {} ./inputs/pieces.txt\n", argv[0]);
        return EXIT_SUCCESS;
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

    std::vector<AttackRelation> attack_relations;
    std::shared_ptr<ChessBoard> board;
    std::shared_ptr<BoardView> view;
    try {
        board = std::make_shared<ChessBoard>();
        view = std::make_shared<BoardView>(board);

        board->addPieces(std::move(pieces));
        view->render();
        view->show();
        std::cout << "\n";

        attack_relations = board->getAttackRelations();
        for (const auto& relation : attack_relations) {
            std::cout << std::format("{} at ({},{}) can attack {} at ({},{})\n",
                relation.getAttackerName(),
                relation.getAttackerPosition().getX(),
                relation.getAttackerPosition().getY(),
                relation.getTargetName(),
                relation.getTargetPosition().getX(),
                relation.getTargetPosition().getY());
        }
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        std::cout << "An error occurred during game creating, shutdown.\n";
    }
    try {
        board->attack(Position {5, 3} ,Position {5, 1});
        board->nextTurn();
        view->render();
        view->show();

        attack_relations = board->getAttackRelations();
        for (const auto& relation : attack_relations) {
            std::cout << std::format("{} at ({},{}) can attack {} at ({},{})\n",
                relation.getAttackerName(),
                relation.getAttackerPosition().getX(),
                relation.getAttackerPosition().getY(),
                relation.getTargetName(),
                relation.getTargetPosition().getX(),
                relation.getTargetPosition().getY());
        }

        board->attack(Position {3, 5} ,Position {7, 1});
        // board->nextTurn();
        view->render();
        view->show();

        attack_relations = board->getAttackRelations();
        for (const auto& relation : attack_relations) {
            std::cout << std::format("{} at ({},{}) can attack {} at ({},{})\n",
                relation.getAttackerName(),
                relation.getAttackerPosition().getX(),
                relation.getAttackerPosition().getY(),
                relation.getTargetName(),
                relation.getTargetPosition().getX(),
                relation.getTargetPosition().getY());
        }

        board->attack(Position {5, 1} ,Position {5, 5});
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        std::cout << "Wrong attack, shutdown.\n";
    }
    return 0;
}
