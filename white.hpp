#include <iostream>
#include "player.hpp"
#include "board.hpp"

#ifndef WHITE_HPP
#define WHITE_HPP

class White : public Player
{
    public:
        White() : Player::Player() {};
        virtual ~White() {Player::~Player();};

        int placePiece(Board* boardObj,int letterAxis, int numAxis);
};

#endif