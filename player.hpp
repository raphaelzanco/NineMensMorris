#include <iostream>
#include "board.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
    private:
        int totalPieces;
    
    public:
        Player() : totalPieces(9) {};
        virtual ~Player() {};

        virtual int placePiece(Board* boardObj, int letterAxis, int numAxis) = 0;
};

#endif