#ifndef T4WIN_H
#define T4WIN_H

#include "T4Board.h"

namespace LB2
{
    bool Won(const Board& grid)
    {
        for(int i = 0; i < 16; i += 1)
        {
            if(grid[i] != "*")
            {
                currentPlayer += 1;
            }

            if(currentPlayer < 3)
            {
                return true;
            }
        }
        return false;
    }
}

#endif