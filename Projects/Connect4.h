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
    string currentPlayer; // Keeping track of current player
    bool isWinner; // Declares winner if any requirements were met
    
    public:
    Connect4()
    {
        string players[2] = {"X","O"};
        string grid[6][7] = {
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "}
        };
        string currentPlayer = " ";
        isWinner = false;
    }

    Connect4(const Connect4& obj)
    {
        value = obj.value;
        currentRow = obj.currentRow;
        currentPlayer = obj.currentPlayer;
        isWinner = obj.isWinner;
    }

    Connect4& operator=(const Connect4& rhs)
    {
        if(this != &rhs)
        {
            value = rhs.value;
            currentRow = rhs.currentRow;
            currentPlayer = rhs.currentPlayer;
            isWinner = rhs.isWinner;
        }
        return *this;
    }

    ~Connect4() {}

    bool HasWinner() const
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

    bool HasMove() const // Determines if there are blank spaces left on the board
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

        // Checking vertically for winner (NS)
        if(grid[currentRow + 1][value] == currentPlayer && grid[currentRow + 2][value] == currentPlayer && grid[currentRow + 3][value] == currentPlayer)
        {
            isWinner = true;
            // North
        }
        else if(grid[currentRow - 1][value] == currentPlayer && grid[currentRow - 2][value] == currentPlayer && grid[currentRow - 3][value] == currentPlayer)
        {
            isWinner = true;
            // South
        }

        // Checking Horizontally for winner (EW)
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

        // Checking Diagonally for winner (NSEW)
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

        //If a winner is determined...
        if(isWinner == true)
        {
            return true;
        }
        else if(currentPlayer == "X") // Else if the current player is Player X, it's Player O's turn.
        {
            currentPlayer = "O";
            return true;
        }
        else if(currentPlayer == "O") // Else if the current player is Player O, it's Player X's turn.
        {
            currentPlayer = "X";
            return true;
        }
    }

    void Reset() // Resets Connect 4 grid
    {
        string grid[6][7] = {
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "}
        };

        currentPlayer = " ";
        isWinner = false;
    }

    char CurrentPlayer() const // Determines current player
    {
        if(currentPlayer == " ") // If the game just started, Player X (players[0]) goes first.
        {
            string currentPlayer = "X";
            return 'X';
        }
        else if(currentPlayer == "X")
        {
            return 'X';
        }
        else
        {
            return 'O';
        }
    }

    string ToString() const // Prints Connect 4 grid
    {
        stringstream out;
        out << "   0   1   2   3   4   5   6 "; // Top of grid
        out << "\n5 "; // Row 5
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + grid[0][i] + "] ";
        }
        out << "\n4 "; // Row 4
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + grid[1][i] + "] ";
        }
        out << "\n3 "; // Row 3
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + grid[2][i] + "] ";
        }
        out << "\n2 "; // Row 2
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + grid[3][i] + "] ";
        }
        out << "\n1 "; // Row 1
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + grid[4][i] + "] ";
        }
        out << "\n0 "; // Row 0
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + grid[5][i] + "] ";
        }
        return out.str();
    }

    friend ostream& operator<<(ostream& out, const Connect4& obj)
        {
            out << obj.ToString();
            return out;
        }
};

#endif