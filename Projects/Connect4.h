#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <cmath>

using namespace std;

class Connect4
{
    private:
    string players[2];
    string grid[6][7];
    
    Connect4()
    {
        players[2] = {"X", "O"};
        grid[6][7] = {
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "}
        };
    }

    Connect4(const Connect4& obj)
    {
        players[2] = obj.players[2];
        grid[6][7] = obj.grid[6][7];
    }

    Connect4& operator=(const Connect4& rhs)
    {
        if(this != rhs)
        {
            players[2] = rhs.players[2];
            grid[6][7] = rhs.grid[6][7];
        }
        return *this;
    }

    ~Connect4() {}

    public:
    const bool HasWinner()
    {

    }

    bool MakeMove()
    {
        int x;

    }

    void Reset()
    {
        grid[6][7] = {
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "}
        };
    }

    const char CurrentPlayer()
    {

    }

    const string ToString()
    {
        cout << "   0   1   2   3   4   5   6 \n"; // Top of grid
        
        cout << "5 ";
        for(int i = 0; i < 8; i += 1)
        {
            cout << "[" + grid[0][i] + "] ";
        }
    }

    friend ostream& operator<<(ostream& out, const Connect4& obj)
        {
            out << obj.ToString();
            return out;
        }
};

#endif