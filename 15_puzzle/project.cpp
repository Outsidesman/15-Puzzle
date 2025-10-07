#include <iostream>
#include "board.h"
#include "utils.h"
#include "tile.h"
#include "user_input.h"
#include "direction.h"
#include "utils.h"
#include "point.h"


int main(){
    Board board;

    // Scramble the board.
    board.scramble();
    
    // Keep taking user input and checking to see if the board is
    // solved, exiting once complete.
    int numMoves{};
    while(true){
        if(board.isSolved()){
            break;
        }
        UserInput::getCommandFromUser(board);
        ++numMoves;
    }

    congratulate(numMoves);

    return 0;
}