/*
    Copyright (c) 2025 - Matt C
    All rights reserved.
*/

#pragma once
extern const int g_consoleLines;
extern const int g_scrambleFactor;
extern const int g_scramblePause;
inline constexpr std::size_t g_validCommands{ 5 };

void clearScreen();
void congratulate(int moves);
