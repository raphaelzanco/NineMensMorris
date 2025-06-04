#include "player.hpp"
#include "white.hpp"
#include "board.hpp"
#include <iostream>

int White::placePiece(Board* boardObj, int letterAxis, int numAxis) 
{   
    if (boardObj->Board::checkEmpty(letterAxis, numAxis) != 1)
    {
        std::cerr << "Invalid position: cannot place piece there"  << std::endl;
        return(-1);
    }

    boardObj->Board::setPieces(letterAxis, numAxis, 'W');

    if (boardObj->Board::checkMill(letterAxis, numAxis) == 1)
    {
        std::cout << "White made a Mill" << std::endl;
    }
    else
    {
        std::cout << "White: no Mill" << std::endl;
    }

    return(0);
}