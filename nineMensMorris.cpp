//◯ ⚫ ⚪ — |
// Fazer com que não importe se foi digitado letra maiúscula ou minúscula, ela será passada maiúscula (colcoar dentro das instâncias de player)
//Rever anotação para Mills em C e F

#include <iostream>
#include "board.hpp"
#include "player.hpp"
#include "white.hpp"
#include "black.hpp"

int main() 
{
    Board* gameBoard = new Board();

    Player* blacky = new Black();
    Player* whity = new White();

    blacky->placePiece(gameBoard, 'E', 7);
    gameBoard->display();
    blacky->placePiece(gameBoard, 'E', 7);
    gameBoard->display();
    blacky->placePiece(gameBoard, 'E', 7);
    gameBoard->display();
    whity->placePiece(gameBoard, 'F', 11);
    gameBoard->display();

    delete gameBoard;
    delete blacky;
    delete whity;

    return(0);
}

