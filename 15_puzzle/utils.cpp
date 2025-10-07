/*
    Copyright (c) 2025 - Matt C
    All rights reserved.
*/

#include <iostream>
#include "utils.h"
#include "direction.h"

const int g_consoleLines{ 25 };
const int g_scrambleFactor{ 100 };
const int g_scramblePause{ 50 };

void clearScreen(){
    for(int line{ 0 }; line < g_consoleLines; line++){
        std::cout << '\n';
    }
}

void congratulate(int moves){
    std::cout << "Congratulations, you won in " << moves << " moves!\n";
}
