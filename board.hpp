#include <iostream>
#include <array>

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
    private:
        std::array<std::array<char,7>, 7> pieces;

        void makeBoard();

    public:
        Board();
        virtual ~Board();

        void display();
        int checkEmpty(int letterAxis, int numAxis);
        char getSpaceStatus(int letterAxis, int numAxis);
        void setPieces(int letterAxis, int numAxis, char piece);
        int checkMill(int letterAxis, int numAxis);
};

#endif