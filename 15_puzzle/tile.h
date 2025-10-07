#pragma once

class Tile{
private:
    int m_tileNum{};

public:
    Tile() = default;
    Tile(int num);

    void setNum(int num);
    int getNum() const;
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& out, const Tile& t);
};