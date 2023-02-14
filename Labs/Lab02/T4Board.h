#ifndef T4BOARD_H
#define T4BOARD_H

#include <iostream>
#include <string>

using namespace std;

namespace LB2
{
    class Board
    {
        public:
        string grid[16];
        int currentPlayer;
        static const string tokens = "OX";

        Board()
        {
            grid[16] = {"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"};
            currentPlayer = 0;
        }

        Board(const Board& grid)
        {}

        Board& operator=(const Board& grid)
        {}
    };
}

#endif