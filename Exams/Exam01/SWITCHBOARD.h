#ifndef SWITCHBOARD_H
#define SWITCHBOARD_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

namespace EX
{
    class SwitchBoard
    {
        public:
        bool switches[10];

        SwitchBoard()
        {
            for(int i = 0; i < 9; i += 1)
            {
                switches[i] = false;
            }
        }

        /* Copy Constructor ???

        SwitchBoard& operator=(rhs)
        {
            switches[10] = switches[10].rhs;
        }

        */

        /* Assignment Operator ???

        */

        ~SwitchBoard() {}

        const int TotalOn()
        {
            int tr;
            
            for(int i = 0, total = 0; i < 9; i += 1)
            {
                if(switches[i] == true)
                {
                    tr += 1;
                }
            }

            cout << tr;
        }

        const int TotalOff()
        {
            int fa;
            
            for(int i = 0; i < 9; i += 1)
            {
                if(switches[i] == false)
                {
                    fa += 1;
                }
            }

            cout << fa;
        }

        void Invert()
        {
            for(int i = 0; i < 9; i += 1)
            {
                if(switches[i] == true){

                    switches[i] = false;

                }else if(switches[i] == false){

                    switches[i] = true;

                }
            }
        }

        const string ToString()
        {
            for(int i = 0; i < 9; i += 1)
            {
                cout << "[";
                
                if(switches[i] == true){

                    cout << "1";
                    
                }else if(switches[i] == false){

                    cout << "0";

                }

                cout << "]";
            }
        }

        // Ostream Operator ???
    };
}

#endif