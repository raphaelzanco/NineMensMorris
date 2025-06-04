#include "player.hpp"
#include "black.hpp"
#include "board.hpp"
#include <iostream>

int Black::placePiece(Board* boardObj, int letterAxis, int numAxis) 
{   
    if (boardObj->Board::checkEmpty(letterAxis, numAxis) != 1)
    {
        std::cerr << "Invalid position: cannot place piece there"  << std::endl;
        return(-1);
    }

    boardObj->Board::setPieces(letterAxis, numAxis, 'B');

    if (boardObj->Board::checkMill(letterAxis, numAxis) == 1)
    {
        std::cout << "Black made a Mill" << std::endl;
    }
    else
    {
        std::cout << "Black: no Mill" << std::endl;
    }

    return(0);
}