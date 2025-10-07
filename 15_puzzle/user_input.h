#pragma once
#include "board.h"
#include "utils.h"

namespace UserInput{
    extern const std::array<char, g_validCommands> validCommandLiterals;
    void quit();
    bool commandValid(const char& command);
    void checkIfQuit(const char& command);
    char getCommandFromUser(Board& board);
};