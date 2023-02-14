#ifndef T4DISPLAY_H
#define T4DISPLAY_H

#include "T4Board.h"

namespace LB2
{
    void Display(const Board& grid)
    {
        cout << "  0 1 2 3\n0 ";
        for(int i = 0; i < 16; i += 1)
        {
            if(i = 4)
            {
                cout << "\n1 ";
            }

            if(i = 8)
            {
                cout << "\n2 ";
            }

            if(i = 12)
            {
                cout << "\n3 ";
            }

            cout << grid[i] << " ";

        }
    }
}

#endif