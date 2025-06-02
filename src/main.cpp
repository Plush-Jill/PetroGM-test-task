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

    std::shared_ptr<ChessBoard> board;
    std::shared_ptr<BoardView> view;
    try {
        board = std::make_shared<ChessBoard>();
        view = std::make_shared<BoardView>(board);

        board->addPieces(std::move(pieces));
        view->render();
        view->showField();
        view->showAttackRelations();
        std::cout << "\n";
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        std::cout << "An error occurred during game creating, shutdown.\n";
    }
    const std::vector<std::pair<Position, Position>> turns {{{5, 3}, {5, 1}},
                                                        {{3, 5}, {7, 1}},
                                                        {{5, 1}, {5, 5}}};
    for (const auto&[from, to] :turns) {
        try {
            board->makeTurn(from, to);
            view->render();
            view->showField();
            view->showAttackRelations();
            std::cout << "\n";
        } catch (std::exception& exception) {
            std::cout << exception.what() << std::endl;
            std::cout << "Wrong attack, shutdown.\n";
            return EXIT_FAILURE;
        }
    }
    return 0;
}
