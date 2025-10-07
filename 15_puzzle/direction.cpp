#include <iostream>
#include <random>
#include "direction.h"
#include "user_input.h"

const Direction Direction::up   { 'w' };
const Direction Direction::down { 's' };
const Direction Direction::left { 'a' };
const Direction Direction::right{ 'd' };

Direction::Direction(char direction) : m_direction{direction} {}

char Direction::getDirection() const{
    return m_direction;
}

Direction Direction::generateRandomDirection() {
    static std::mt19937 rng{ std::random_device{}() };

    // Pick randomly from w, a, s, d (don't include q)
    static std::uniform_int_distribution<std::size_t> dist(0, UserInput::validCommandLiterals.size() -2);

    return Direction(UserInput::validCommandLiterals[dist(rng)]);
}

Direction operator-(const Direction& d){
    switch (d.m_direction) {
        case 'w':
            return Direction('s');
        case 'a':
            return Direction('d');
        case 's':
            return Direction('w');
        case 'd':
            return Direction('a');
        default:
            return Direction('?');
    }
}

bool operator==(const Direction& d1, const Direction& d2){
    if(d1.getDirection() == d2.getDirection()){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Direction& d){
    switch (d.m_direction) {
        case 'w':
            out << "up";
            break;
        case 'a':
            out << "left";
            break;
        case 's':
            out << "down";
            break;
        case 'd':
            out << "right";
            break;
    }
    return out;
}