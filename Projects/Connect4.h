#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <cmath>

class Connect4
{
    private:
    string players[2];
    
    Connect4()
    {
        players[2] = {"X", "O"};
    }

    Connect4(const Connect4& obj)
    {
        players[2] = obj.players[2];
    }

    Connect4& operator=(const Connect4& rhs)
    {
        if(this != rhs)
        {
            players[2] = rhs.players[2];
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

    }

    void Reset()
    {

    }

    const char CurrentPlayer()
    {

    }

    const string ToString()
    {

    }
};

#endif