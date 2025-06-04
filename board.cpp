#include "board.hpp"
#include <iostream>
#include <array>

void Board::makeBoard()
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            switch(i)
            {
                case 0:
                    this->pieces[i][j] = (((j+1) == 1) || ((j+1) == 4) || ((j+1) == 7)) ? 'E' : 'X';
                    break;
                case 1:
                    this->pieces[i][j] = ((j+1) % 2 == 0) ? 'E' : 'X';
                    break;
                case 2:
                    this->pieces[i][j] = (((j+1) == 3) || ((j+1) == 4) || ((j+1) == 5)) ? 'E' : 'X';
                    break;
                case 3:
                    this->pieces[i][j] = ((j+1) == 4) ? 'X' : 'E';
                    break;
                case 4:
                    this->pieces[i][j] = (((j+1) == 3) || ((j+1) == 4) || ((j+1) == 5)) ? 'E' : 'X';
                    break;
                case 5:
                    this->pieces[i][j] = ((j+1) % 2 == 0) ? 'E' : 'X';
                    break;
                case 6:
                    this->pieces[i][j] = (((j+1) == 1) || ((j+1) == 4) || ((j+1) == 7)) ? 'E' : 'X';
                    break;
            }
        }
    }
}

Board::Board() : pieces()  {Board::makeBoard();};
Board::~Board() {};

void Board::display()
{
    std::cout << "   A   B   C   D   E   F   G" << std::endl << std::endl;

    for (int i = 0; i < 13; i++)
    {
        int k = i/2;
        std::cout << (i+1) << ((i < 9) ? "  " : " ");

       for (int j = 0; j < 7; j++)
       {
            switch(i)
            {
                case 0:
                    if (this->pieces[k][j] == 'E')
                    {
                        std::cout << "◯ " << ((j != 6) ? "— " : "");
                    }
                    else if (this->pieces[k][j] == 'B')
                    {
                        std::cout << "⚫" << ((j != 6) ? "— " : "");
                    }
                    else if (this->pieces[k][j] == 'W')
                    {
                        std::cout << "⚪" << ((j != 6) ? "— " : "");
                    }
                    else 
                    {
                        std::cout << "— — ";
                    }
                    break;
            
                case 1:
                    if (this->pieces[i-1][j] != 'X')
                    {
                        std::cout << "|" << ((j != 6) ? "           " : " ");
                    }
                    break;

                case 2:
                    if (this->pieces[k-1][j] != 'X' && this->pieces[k][j] == 'X')
                    {
                        std::cout << "|" << ((j == 0) ? "   " : " ");
                    }
                    else if (this->pieces[k][j] == 'E')
                    {
                        std::cout << "◯ " << ((j != 5) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'B')
                    {
                        std::cout << "⚫" << ((j != 5) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'W')
                    {
                        std::cout << "⚪" << ((j != 5) ? "— " : "  ");
                    }
                    else
                    {
                        std::cout << "— — ";
                    }
                    break;
            
                case 3:
                    if (this->pieces[i-3][j] != 'X' || this->pieces[i-2][j] != 'X')
                    {
                        std::cout << "|" << ((j != 6) ? "   " : " ");
                    }
                    else
                    {
                        std::cout << "    ";
                    }
                    break;

                case 4:
                    if ((this->pieces[k-2][j] != 'X' || this->pieces[k-1][j] != 'X') && this->pieces[k][j] == 'X')
                    {
                        std::cout << "|" << ((j != 6) ? "   " : " ");
                    }
                    else if (this->pieces[k][j] == 'E')
                    {
                        std::cout << "◯ " << ((j != 4) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'B')
                    {
                        std::cout << "⚫" << ((j != 4) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'W')
                    {
                        std::cout << "⚪" << ((j != 4) ? "— " : "  ");
                    }
                    else
                    {
                        std::cout << "    ";
                    }
                    break;

                case 5:
                    if ((this->pieces[i-5][j] != 'X' || this->pieces[i-2][j] != 'X') && j != 3)
                    {
                        std::cout << "|" << ((j != 6) ? "   " : " ");
                    }
                    else
                    {
                        std::cout << "    ";
                    }
                    break;

                case 6:
                    if (this->pieces[k][j] == 'E')
                    {
                        std::cout << "◯ " << (((j != 2) && (j != 6)) ? "— " : "");
                    }
                    else if (this->pieces[k][j] == 'B')
                    {
                        std::cout << "⚫" << (((j != 2) && (j != 6)) ? "— " : "");
                    }
                    else if (this->pieces[k][j] == 'W')
                    {
                        std::cout << "⚪" << (((j != 2) && (j != 6)) ? "— " : "");
                    }
                    else
                    {
                        std::cout << "      ";
                    }
                    break;

                case 7: //concertar
                    if ((this->pieces[i-1][j] != 'X' || this->pieces[i-4][j] != 'X') && j != 3)
                    {
                        std::cout << "|" << ((j != 6) ? "   " : " ");
                    }
                    else
                    {
                        std::cout << "    ";
                    }
                    break;
                
                case 8:
                    if ((this->pieces[k+2][j] != 'X' || this->pieces[k+1][j] != 'X') && this->pieces[k][j] == 'X')
                    {
                        std::cout << "|" << ((j != 6) ? "   " : " ");
                    }
                    else if (this->pieces[k][j] == 'E')
                    {
                        std::cout << "◯ " << ((j != 4) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'B')
                    {
                        std::cout << "⚫" << ((j != 4) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'W')
                    {
                        std::cout << "⚪" << ((j != 4) ? "— " : "  ");
                    }
                    else
                    {
                        std::cout << "    ";
                    }
                    break;
                
                case 9:
                    if (this->pieces[i-3][j] != 'X' || this->pieces[i-4][j] != 'X')
                    {
                        std::cout << "|" << ((j != 6) ? "   " : " ");
                    }
                    else
                    {
                        std::cout << "    ";
                    }
                    break;
                
                case 10:
                    if (this->pieces[k+1][j] != 'X' && this->pieces[k][j] == 'X')
                    {
                        std::cout << "|" << ((j == 0) ? "   " : " ");
                    }
                    else if (this->pieces[k][j] == 'E')
                    {
                        std::cout << "◯ " << ((j != 5) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'B')
                    {
                        std::cout << "⚫" << ((j != 5) ? "— " : "  ");
                    }
                    else if (this->pieces[k][j] == 'W')
                    {
                        std::cout << "⚪" << ((j != 5) ? "— " : "  ");
                    }
                    else
                    {
                        std::cout << "— — ";
                    }
                    break;

                case 11:
                    if (this->pieces[i-5][j] != 'X')
                    {
                        std::cout << "|" << ((j != 6) ? "           " : " ");
                    }
                    break;

                case 12:
                    if (this->pieces[k][j] == 'E')
                    {
                        std::cout << "◯ " << ((j != 6) ? "— " : "");
                    }
                    else if (this->pieces[k][j] == 'B')
                    {
                        std::cout << "⚫" << ((j != 6) ? "— " : "");
                    }
                    else if (this->pieces[k][j] == 'W')
                    {
                        std::cout << "⚪" << ((j != 6) ? "— " : "");
                    }
                    else 
                    {
                        std::cout << "— — ";
                    }
                    break;
            }
       }
       std::cout << " " << (i+1) << std::endl;
    }
    std::cout << std::endl << "   A   B   C   D   E   F   G" << std::endl << std::endl;
}

int Board::checkEmpty(int letterAxis, int numAxis)
{
    letterAxis -= 65;
    numAxis = ((numAxis-1)/2);
    int result = (this->pieces[numAxis][letterAxis] == 'E') ? 1 : 0;

    return(result);

}

char Board::getSpaceStatus(int letterAxis, int numAxis)
{
    letterAxis -= 65;
    numAxis = ((numAxis-1)/2);

    return(this->pieces[numAxis][letterAxis]);

}

void Board::setPieces(int letterAxis, int numAxis, char piece)
{
    letterAxis -= 65;
    numAxis = ((numAxis-1)/2);

    this->pieces[numAxis][letterAxis] = piece;
}

int Board::checkMill(int letterAxis, int numAxis)
{
    letterAxis -= 65;
    numAxis = ((numAxis-1)/2);

    if (letterAxis == 0 || letterAxis == 6)
    {
        if (this->pieces[0][letterAxis] == this->pieces[3][letterAxis] && this->pieces[0][letterAxis] == this->pieces[6][letterAxis])
        {
            return(1);
        }
        else if(numAxis == 3 && letterAxis == 0)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+1] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+2])
            {
                return(1);
            }
        }
        else if (numAxis == 3 && letterAxis == 6)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-1] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-2])
            {
                return(1);
            }
        }
        else if (numAxis == 0 || numAxis == 6)
        {
            if (this->pieces[numAxis][0] == this->pieces[numAxis][3] && this->pieces[numAxis][0] == this->pieces[numAxis][6])
            {
                return(1);
            }
        }
    }
    else if (letterAxis == 3)
    {
        if (numAxis == 0)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis+1][letterAxis] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis+2][letterAxis])
            {
                return(1);
            }
            else if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-3] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+3])
            {
                return(1);
            }
        }
        else if (numAxis == 1 || numAxis == 5)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis+1][letterAxis] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis-1][letterAxis])
            {
                return(1);
            }
            else if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-2] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+2])
            {
                return(1);
            }
        }
        else if (numAxis == 2)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis-1][letterAxis] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis-2][letterAxis])
            {
                return(1);
            }
        }
        else if (numAxis == 4)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis+1][letterAxis] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis+2][letterAxis])
            {
                return(1);
            }
        }
        else if (numAxis == 6)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis-1][letterAxis] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis-2][letterAxis])
            {
                return(1);
            }
            else if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-3] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+3])
            {
                return(1);
            }
        }
    }
    if (letterAxis == 1 || letterAxis == 5)
    {
        if (this->pieces[1][letterAxis] == this->pieces[3][letterAxis] && this->pieces[1][letterAxis] == this->pieces[5][letterAxis])
        {
            return(1);
        }
        else if(numAxis == 3 && letterAxis == 1)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-1] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+1])
            {
                return(1);
            }
        }
        else if (numAxis == 3 && letterAxis == 5)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-1] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+1])
            {
                return(1);
            }
        }
        else if (numAxis == 1 || numAxis == 5)
        {
            if (this->pieces[numAxis][1] == this->pieces[numAxis][3] && this->pieces[numAxis][1] == this->pieces[numAxis][5])
            {
                return(1);
            }
        }
    }
    else if (letterAxis == 2 || letterAxis == 4)
    {
        if (numAxis == 2 || numAxis == 4)
        {
            if (this->pieces[numAxis][2] == this->pieces[numAxis][3] && this->pieces[numAxis][2] == this->pieces[numAxis][4])
            {
                return(1);
            }
            else if (this->pieces[numAxis][2] == this->pieces[numAxis+1][3] && this->pieces[numAxis][2] == this->pieces[numAxis+2][4])
            {
                //rever mill vertical C e E
                return(1);
            }
        }
        else if (letterAxis == 2 && numAxis == 3)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-1] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis-2])
            {
                return(1);
            }
        }
        else if (letterAxis == 4 && numAxis == 3)
        {
            if (this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+1] && this->pieces[numAxis][letterAxis] == this->pieces[numAxis][letterAxis+2])
            {
                return(1);
            }
        }
    }

    return(0);
}