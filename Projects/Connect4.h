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
    int value;
    int currentPlayer;
    
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
        value = obj.value;
        currentPlayer = obj.currentPlayer;
    }

    Connect4& operator=(const Connect4& rhs)
    {
        if(this != rhs)
        {
            players[2] = rhs.players[2];
            grid[6][7] = rhs.grid[6][7];
            value = rhs.value;
            currentPlayer = rhs.currentPlayer;
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
        // Placing the piece (If possible)
        for(int i = 6; i > value; i -= 1)
        {
            if(grid[i-1][value] == " ") // Checks row 0/grid[5][value]
            {  
                if(currentPlayer == 0)
                {
                    grid[i-1][value] = players[0];
                }
                else if(currentPlayer == 1)
                {
                    grid[i-1][value] = players[1];
                }
                break;
            }
            else if(grid[i-2][value] == " ") // Checks row 1/grid[4][value]
            {
                if(currentPlayer == 0)
                {
                    grid[i-2][value] = players[0];
                }
                else if(currentPlayer == 1)
                {
                    grid[i-2][value] = players[1];
                }
                break;
            }
            else if(grid[i-3][value] == " ") // Checks row 2/grid[3][value]
            {
                if(currentPlayer == 0)
                {
                    grid[i-3][value] = players[0];
                }
                else if(currentPlayer == 1)
                {
                    grid[i-3][value] = players[1];
                }
                break;
            }
            else if(grid[i-4][value] == " ") // Checks row 3/grid[2][value]
            {
                if(currentPlayer == 0)
                {
                    grid[i-4][value] = players[0];
                }
                else if(currentPlayer == 1)
                {
                    grid[i-4][value] = players[1];
                }
                break;
            }
            else if(grid[i-5][value] == " ") // Checks row 4/grid[1][value]
            {
                if(currentPlayer == 0)
                {
                    grid[i-5][value] = players[0];
                }
                else if(currentPlayer == 1)
                {
                    grid[i-5][value] = players[1];
                }
                break;
            }
            else if(grid[i-5][value] == " ") // Checks row 5/grid[0][value]
            {
                if(currentPlayer == 0)
                {
                    grid[i-6][value] = players[0];
                }
                else if(currentPlayer == 1)
                {
                    grid[i-6][value] = players[1];
                }
                break;
            }
            else // If column is full
            {
                cout << "Column Full.\n";
                break;
            }

        // Checking for winner
        for(int i = 0; i < 6; i += 1) // Checks Vertically
        {
            
        }

        for(int i = 0; i < 6; i += 1) // Checks Horizontally
        {

        }

        for(int i = 0; i < 6; i += 1) // Checks Diagonally
        {

        }


    }

    void Reset() // Resets Connect 4 grid
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

    const string ToString() // Prints Connect 4 board
    {
        cout << "   0   1   2   3   4   5   6 \n"; // Top of grid
        
        cout << "5 "; // Row 5
        for(int i = 0; i < 8; i += 1)
        {
            cout << "[" + grid[0][i] + "] ";
        }

        cout << "\n4 "; // Row 4
        for(int i = 0; i < 8; i += 1)
        {
            cout << "[" + grid[1][i] + "] ";
        }

        cout << "\n3 "; // Row 3
        for(int i = 0; i < 8; i += 1)
        {
            cout << "[" + grid[2][i] + "] ";
        }

        cout << "\n2 "; // Row 2
        for(int i = 0; i < 8; i += 1)
        {
            cout << "[" + grid[3][i] + "] ";
        }

        cout << "\n1 "; // Row 1
        for(int i = 0; i < 8; i += 1)
        {
            cout << "[" + grid[4][i] + "] ";
        }

        cout << "\n0 "; // Row 0
        for(int i = 0; i < 8; i += 1)
        {
            cout << "[" + grid[5][i] + "] ";
        }
    }

    friend ostream& operator<<(ostream& out, const Connect4& obj)
        {
            out << obj.ToString();
            return out;
        }
};

#endif