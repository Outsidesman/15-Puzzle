#pragma once
#include <iosfwd>
#include "tile.h"
#include "direction.h"

class Board{
private:
    static constexpr int size{4};
    static constexpr int numRows{size};
    static constexpr int numCols{size};
    Tile m_tiles[numRows][numCols];

public:
    Board();

    void moveTile(const Direction d);
    void scramble();
    bool isSolved() const;

    friend std::ostream& operator<<(std::ostream& out, const Board& c);
};

void boardTask();