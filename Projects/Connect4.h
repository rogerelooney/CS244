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
    int currentRow;
    string currentPlayer;
    bool isWinner;
    
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
        currentPlayer = " ";
        isWinner = false;
    }

    Connect4(const Connect4& obj)
    {
        players[2] = obj.players[2];
        grid[6][7] = obj.grid[6][7];
        value = obj.value;
        currentRow = obj.currentRow;
        currentPlayer = obj.currentPlayer;
        isWinner = obj.isWinner;
    }

    Connect4& operator=(const Connect4& rhs)
    {
        if(this != rhs)
        {
            players[2] = rhs.players[2];
            grid[6][7] = rhs.grid[6][7];
            value = rhs.value;
            currentRow = rhs.currentRow;
            currentPlayer = rhs.currentPlayer;
            isWinner = rhs.isWinner;
        }
        return *this;
    }

    ~Connect4() {}

    public:
    const bool HasWinner()
    {
        if(isWinner == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool MakeMove()
    {
        // Placing the piece (If possible)
        for(int i = 7; i > value; i -= 1)
        {
            if(grid[i-2][value] == " ") // Checks row 0/grid[5][value]
            {  
                grid[i-2][value] = currentPlayer;
                currentRow = 5;
                break;
            }
            else if(grid[i-3][value] == " ") // Checks row 1/grid[4][value]
            {
                grid[i-3][value] = currentPlayer;
                currentRow = 4;
                break;
            }
            else if(grid[i-4][value] == " ") // Checks row 2/grid[3][value]
            {
                grid[i-4][value] = currentPlayer;
                currentRow = 3;
                break;
            }
            else if(grid[i-5][value] == " ") // Checks row 3/grid[2][value]
            {
                grid[i-5][value] = currentPlayer;
                currentRow = 2;
                break;
            }
            else if(grid[i-6][value] == " ") // Checks row 4/grid[1][value]
            {
                grid[i-6][value] = currentPlayer;
                currentRow = 1;
                break;
            }
            else if(grid[i-7][value] == " ") // Checks row 5/grid[0][value]
            {
                grid[i-7][value] = currentPlayer;
                currentRow = 0;
                break;
            }
            else // If column is full
            {
                cout << "Column Full.\n";
                break;
            }
        }

        // Checking for winner
        
        // Checking vertically
        if(grid[currentRow + 1][value] == currentPlayer && grid[currentRow + 2][value] == currentPlayer && grid[currentRow + 3][value] == currentPlayer)
        {
            isWinner = true;
            // North
        }
        else if(grid[currentRow - 1][value] == currentPlayer && grid[currentRow - 2][value] == currentPlayer && grid[currentRow - 1][value] == currentPlayer)
        {
            isWinner = true;
            // South
        }

        // Checking Horizontally
        if(grid[currentRow][value + 1] == currentPlayer && grid[currentRow][value + 2] == currentPlayer && grid[currentRow][value + 3] == currentPlayer)
        {
            isWinner = true;
            // East
        }
        else if(grid[currentRow][value - 1] == currentPlayer && grid[currentRow][value - 2] == currentPlayer && grid[currentRow][value - 3] == currentPlayer)
        {
            isWinner = true;
            // West
        }

        // Checking Diagonally
        if(grid[currentRow + 1][value + 1] == currentPlayer && grid[currentRow + 2][value + 2] == currentPlayer && grid[currentRow + 3][value + 3] == currentPlayer)
        {
            isWinner = true;
            // Northeast
        }
        else if(grid[currentRow + 1][value - 1] == currentPlayer && grid[currentRow + 2][value - 2] == currentPlayer && grid[currentRow + 3][value - 3] == currentPlayer)
        {
            isWinner = true;
            // Northwest
        }
        else if(grid[currentRow - 1][value + 1] == currentPlayer && grid[currentRow - 2][value + 2] == currentPlayer && grid[currentRow - 3][value + 3] == currentPlayer)
        {
            isWinner = true;
            // Southeast
        }
        else if(grid[currentRow - 1][value - 1] == currentPlayer && grid[currentRow - 2][value - 2] == currentPlayer && grid[currentRow - 3][value - 3] == currentPlayer)
        {
            isWinner = true;
            // Southwest
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

        currentPlayer = " ";
    }

    const char CurrentPlayer() // Determines current player
    {
        if(currentPlayer == " ") // If the game just started, Player X (players[0]) goes first.
        {
            currentPlayer = players[0];
            return currentPlayer;
        }
        else if(currentPlayer == "X") // If the current player is Player X, it's Player O's turn.
        {
            currentPlayer = players[1];
            return currentPlayer;
        }
        else if(currentPlayer == "O") // If the current player is Player O, it's Player X's turn.
        {
            currentPlayer = players[0];
            return currentPlayer;
        }
    }

    const string ToString() // Prints Connect 4 grid
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