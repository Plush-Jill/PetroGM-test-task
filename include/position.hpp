//
// Created by plush-jill on 6/1/25.
//

#ifndef POSITION_HPP
#define POSITION_HPP



class Position {
private:
    int m_x_;
    int m_y_;

public:
    explicit Position(int x, int y);;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void setX(int new_x);
    void setY(int new_y);
    bool operator==(const Position& other) const;
};




#endif //POSITION_HPP
