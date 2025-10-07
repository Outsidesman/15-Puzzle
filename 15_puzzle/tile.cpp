/*
    Copyright (c) 2025 - Matt C
    All rights reserved.
*/

#include <iostream>
#include "tile.h"

Tile::Tile(int num) : m_tileNum{num} {}

void Tile::setNum(int num) {
    m_tileNum = num;
}

int Tile::getNum() const{
    return m_tileNum;
}

bool Tile::isEmpty() const{
    return (m_tileNum == 0);
}

std::ostream& operator<<(std::ostream& out, const Tile& t){
    if(t.getNum() > 9) {
        out << " " << t.getNum() << " ";
    } else if(t.getNum() > 0) {
        out << "  " << t.getNum() << " ";
    } else {
        out << "    ";
    }
    return out;
}
