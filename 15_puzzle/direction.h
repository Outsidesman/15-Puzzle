/*
    Copyright (c) 2025 - Matt C
    All rights reserved.
*/

#pragma once
#include <iostream>


class Direction{
private:
    char m_direction{};

public:
    Direction() = default;
    Direction(char direction);

    static const Direction up;
    static const Direction down;
    static const Direction left;
    static const Direction right;

    char getDirection() const;
    static Direction generateRandomDirection();

    friend Direction operator-(const Direction& d);
    friend bool operator==(const Direction& d1, const Direction& d2);
    friend std::ostream& operator<<(std::ostream& out, const Direction& d);


};

