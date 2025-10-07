/*
    Copyright (c) 2025 - Matt C
    All rights reserved.
*/

#include <iostream>
#include "user_input.h"
#include "board.h"
#include "utils.h"

namespace UserInput{
    constexpr std::array<char, g_validCommands> validCommandLiterals{ 'w', 'a', 's', 'd', 'q' };

    // Exit the game
    void quit(){
        std::cout << "\n\n\nBye!\n";
        exit(0);
    }

    // Check if the user's command was valid
    bool commandValid(const char& command){
        for (auto validCommand : validCommandLiterals){
            if (command == validCommand){
                return true;
            }
        }
        return false;
    }

    // Quit if they choose to
    void checkIfQuit(const char& command){
        if(command == 'q'){
            quit();
        }
        return;
    }

    // Get user input
    char getCommandFromUser(Board& board){
        char command{};
        std::cin >> command;

        if(std::cin){
            if(commandValid(command)){
                checkIfQuit(command);

                // Call moveTile here
                board.moveTile(Direction{command});
            }

        }
        return command;
    }
};
