//
// Created by plush-jill on 6/1/25.
//

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <vector>
#include <memory>

class Piece; // Forward declaration
struct ChessBoardParams {
    int size {8};
};


using Position = std::pair<int, int>;
class ChessBoard {
private:
    int m_size_;
    std::vector<std::unique_ptr<Piece>> pieces;

public:
    explicit ChessBoard(const ChessBoardParams& params);
    [[nodiscard]] bool isValidPosition(const Position& position) const {
        return
        (position.first >= 0 && position.first < m_size_) &&
        (position.second >= 0 && position.second < m_size_);
    }
    [[nodiscard]] bool hasPieceAt(const Position& position) const {
        return false;
    };

    // void addPiece(std::unique_ptr<Piece> piece) {
    //     // if ()
    //     pieces.push_back(std::move(piece));
    // }

};



#endif //СHESSBOARD_HPP
