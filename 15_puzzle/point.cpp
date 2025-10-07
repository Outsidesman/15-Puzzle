#include "point.h"
#include "direction.h"

Point::Point(int x, int y) : m_x{x}, m_y{y} {}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}

Point Point::getAdjacentPoint(const Direction& d) {
    if(d == Direction::up)      return { m_x,     m_y - 1 }; 
    if(d == Direction::down)    return { m_x,     m_y + 1 }; 
    if(d == Direction::left)    return { m_x - 1, m_y     }; 
    /* right */                 return { m_x + 1, m_y     }; 
}

bool operator==(const Point& a, const Point& b){
    if(a.m_x == b.m_x && a.m_y == b.m_y){
        return true;
    }
    return false;
}