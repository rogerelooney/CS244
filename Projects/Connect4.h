#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class Connect4
{
    private:
    static const string players[2]; // Players 'X' & 'O'
    string grid[6][7]; // Connect 4 grid
    int value; // Column of player's choice
    int currentRow; // The row the player's piece was placed in
    std::string currentPlayer; // Keeping track of current player
    bool isWinner; // Declares winner if any directional requirements were met
    
    Connect4()
    {
        string players[2] = {"X", "O"};
        string grid[6][7] = {
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " "}
        };
        string currentPlayer = " ";
        isWinner = false;
    }

    Connect4(const Connect4& obj)
    {
        string players[2] = obj.players[2];
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
            string players[2] = rhs.players[2];
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

    const bool HasMove()
    {
        if(grid[0][value] != " ")
        {
            return false;
        }
        else
        {
            return true;
        }

    }

    bool MakeMove(int value)
    {
        // Is "value" a coulmn?
        if(value >= 0 && value <= 6) {/* Proceed */}
        else
        {
            return false;
        }

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
                return false;
            }
        }

        // Checking for winner
        
        // Checking vertically
        if(grid[currentRow + 1][value] == currentPlayer && grid[currentRow + 2][value] == currentPlayer && grid[currentRow + 3][value] == currentPlayer)
        {
            isWinner = true;
            return true;
            // North
        }
        else if(grid[currentRow - 1][value] == currentPlayer && grid[currentRow - 2][value] == currentPlayer && grid[currentRow - 1][value] == currentPlayer)
        {
            isWinner = true;
            return true;
            // South
        }

        // Checking Horizontally
        if(grid[currentRow][value + 1] == currentPlayer && grid[currentRow][value + 2] == currentPlayer && grid[currentRow][value + 3] == currentPlayer)
        {
            isWinner = true;
            return true;
            // East
        }
        else if(grid[currentRow][value - 1] == currentPlayer && grid[currentRow][value - 2] == currentPlayer && grid[currentRow][value - 3] == currentPlayer)
        {
            isWinner = true;
            return true;
            // West
        }

        // Checking Diagonally
        if(grid[currentRow + 1][value + 1] == currentPlayer && grid[currentRow + 2][value + 2] == currentPlayer && grid[currentRow + 3][value + 3] == currentPlayer)
        {
            isWinner = true;
            return true;
            // Northeast
        }
        else if(grid[currentRow + 1][value - 1] == currentPlayer && grid[currentRow + 2][value - 2] == currentPlayer && grid[currentRow + 3][value - 3] == currentPlayer)
        {
            isWinner = true;
            return true;
            // Northwest
        }
        else if(grid[currentRow - 1][value + 1] == currentPlayer && grid[currentRow - 2][value + 2] == currentPlayer && grid[currentRow - 3][value + 3] == currentPlayer)
        {
            isWinner = true;
            return true;
            // Southeast
        }
        else if(grid[currentRow - 1][value - 1] == currentPlayer && grid[currentRow - 2][value - 2] == currentPlayer && grid[currentRow - 3][value - 3] == currentPlayer)
        {
            isWinner = true;
            return true;
            // Southwest
        }

        // Changing current player (if no winner is determined)

        if(currentPlayer == "X") // If the current player is Player X, it's Player O's turn.
        {
            currentPlayer = players[1];
        }
        else if(currentPlayer == "O") // If the current player is Player O, it's Player X's turn.
        {
            currentPlayer = players[0];
        }
    }

    void Reset() // Resets Connect 4 grid
    {
        string grid[6][7] = {
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

    const char CurrentPlayer() // Determines current player
    {
        if(currentPlayer == " ") // If the game just started, Player X (players[0]) goes first.
        {
            currentPlayer = players[0];
            return 'X';
        }
        else if(currentPlayer == "X") // If the current player is Player X, it's Player O's turn.
        {
            return 'X';
        }
        else if(currentPlayer == "O") // If the current player is Player O, it's Player X's turn.
        {
            return 'O';
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