/*
    Copyright (c) 2025 - Matt C
    All rights reserved.
*/

#include <iostream>
#include <chrono>
#include <thread>
#include "board.h"
#include "utils.h"
#include "point.h"
#include "direction.h"

Board::Board() {
    constexpr int N{ size * size };
    int tile{ 1 };
    for (int row{0}; row < numRows; ++row) {
        for (int col{0}; col < numCols; ++col, ++tile) {
            m_tiles[row][col] = tile % N;
        }
    }
}

void Board::moveTile(const Direction d){
    Point emptyPoint{};
    Point adjacentPoint{};

    // Locate the empty tile
    for (int row{0}; row < numRows; ++row) {
        for (int col{0}; col < numCols; ++col) {
            if (m_tiles[row][col].isEmpty()){
                emptyPoint = Point{ col, row };
                break;
            }
        }
    }

    // From the empty tile, find the adjacent tile that is in the
    // direction opposite of the direction the user entered
    adjacentPoint = emptyPoint.getAdjacentPoint(-d);

    // If the adjacent tile is valid (it's not off the grid), swap the
    // empty tile and the adjacent tile and redraw the board.
    int x = adjacentPoint.getX();
    int y = adjacentPoint.getY();

    if (0 <= x && x < numCols && 0 <= y && y < numRows) {
        m_tiles[emptyPoint.getY()][emptyPoint.getX()].setNum(m_tiles[y][x].getNum());
        m_tiles[y][x].setNum(0);
    }

    // (If the adjacent tile is not valid, do nothing, but still
    // re-print the board for the shuffling step)
    std::cout << *this;
}

void Board::scramble(){
    // Generate random moves to scramble the tiles.
    for (int i{0}; i < g_scrambleFactor; ++i){
        Direction randomDirection { Direction::generateRandomDirection() };
        moveTile(randomDirection);

        std::cout << "Scrambling tiles... ";
        if(i != (g_scrambleFactor - 1)){
            std::cout << i << "%\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(g_scramblePause));
    }
    std::cout << "Done.\n";
    std::cout << "Enter 'w', 'a', 's', 'd' to move tiles around, 'q' to quit.\n";
}

bool Board::isSolved() const
{
    int expected {1};
    for (int row {0}; row < numRows; ++row) {
        for (int col {0}; col < numCols; ++col) {
            const bool isLast = (row == numRows - 1) && (col == numCols - 1);
            if (isLast) {
                return m_tiles[row][col].isEmpty();
            }
            if (m_tiles[row][col].getNum() != expected++) {
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Board& b){
    clearScreen();

    for (int row {0}; row < Board::numRows; row++) {
        for (int col {0}; col < Board::numCols; col++) {
            out << b.m_tiles[row][col];
        }
        out << '\n';
    }
    return out;
}
