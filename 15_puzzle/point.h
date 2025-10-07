#pragma once
#include "direction.h"

class Point{
private:
    int m_x{};
    int m_y{};

public:
    Point() = default;
    Point(int x, int y);

    int getX() const;
    int getY() const;

    Point getAdjacentPoint(const Direction& d);

    friend bool operator==(const Point& a, const Point& b);
};