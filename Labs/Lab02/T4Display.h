#ifndef T4DISPLAY_H
#define T4DISPLAY_H

namespace LB2
{
    void Display(const Board& obj)
    {
        cout << "  0 1 2 3\n0 ";
        for(int i = 0; i < 16; i += 1)
        {
            if(i = 4)
            {
                cout << "\n1 ";
            } else if(i = 8)
            {
                cout << "\n2 ";
            } else if(i = 12)
            {
                cout << "\n3 ";
            }

            cout << grid[i] << " ";

        }
    }
}

#endif