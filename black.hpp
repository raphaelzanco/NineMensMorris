#include <iostream>
#include "player.hpp"
#include "board.hpp"

#ifndef BLACK_HPP
#define BLACK_HPP

class Black : public Player
{
    public:
        Black() : Player::Player() {};
        virtual ~Black() {Player::~Player();};

        int placePiece(Board* boardObj, int letterAxis, int numAxis);
};

#endif