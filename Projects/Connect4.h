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
    string grid[6][7]; // Connect 4 grid
    int currentRow; // The row the player's piece was placed in
    string currentPlayer; // Keeping track of current player
    bool isWinner; // Declares winner if any requirements were met
    
    public:
    Connect4()
    {
        for(int i = 0, j = 0; i < 6; i += 1)
        {
            if(j == 6)
            {
                break;
            }
            
            grid[i][j] = " ";
            
            if(i == 5)
            {
                i = 0;
                j += 1;
            }
        }
        currentRow = 0;
        currentPlayer = "X";
        isWinner = false;
    }

    Connect4(const Connect4& obj)
    {
        for(int i = 0, j = 0; i < 6; i += 1)
        {
            if(j == 6)
            {
                break;
            }
            
            grid[i][j] = obj.grid[i][j];
            
            if(i == 5)
            {
                i = 0;
                j += 1;
            }
        }
        currentRow = obj.currentRow;
        currentPlayer = obj.currentPlayer;
        isWinner = obj.isWinner;
    }

    Connect4& operator=(const Connect4& rhs)
    {
        if(this != &rhs)
        {
            for(int i = 0, j = 0; i < 6; i += 1)
            {
                if(j == 6)
                {
                    break;
                }
            
                grid[i][j] = rhs.grid[i][j];
            
                if(i == 5)
                {
                    i = 0;
                    j += 1;
                }
            }
            currentRow = rhs.currentRow;
            currentPlayer = rhs.currentPlayer;
            isWinner = rhs.isWinner;
        }
        return *this;
    }

    ~Connect4() {}

    private:
    // Getters

    string GetGrid(int r, int c) const 
    {
        // r = Row, c = Column
        return grid[r][c];
    }

    int GetCurrentRow() const
    {
        return currentRow;
    }

    string GetCurrentPlayer() const
    {
        return currentPlayer;
    }

    bool GetIsWinner() const
    {
        return isWinner;
    }

    // Setters

    void SetGrid(int r, int c, string value)
    {
        grid[r][c] = value;
    }

    void SetCurrentRow(int value)
    {
        currentRow = value;
    }

    void SetCurrentPlayer(string value)
    {
        currentPlayer = value;
    }

    void SetIsWinner(bool value)
    {
        isWinner = value;
    }

    public:
    // Other Methods

    bool HasWinner() const
    {
        return GetIsWinner();
    }

    bool HasMove() const // Determines if there are blank spaces left on the board.
    {
        for(int i = 0, full = 0; i < 7; i += 1)
        {
            if(grid[0][i] != " ")
            {
              full += 1;
            }

            if(full == 6)
            {
              return false;
            }
        }
        return true;
    }

    bool MakeMove(int value)
    {
        // Placing the piece (If possible).
        for(int i = 5; i > value; i -= 1)
        {
            if(GetGrid(i, value) == " ") // Checks row 0/grid[5][value]
            {  
                SetGrid(i, value, GetCurrentPlayer());
                SetCurrentRow(i);
                break;
            }
            else
            {
                return false;
            }
        }

        // Checking vertically for winner (NS)
        if(GetGrid(GetCurrentRow()+1, value) == GetCurrentPlayer() && GetGrid(GetCurrentRow()+2, value) == GetCurrentPlayer() && GetGrid(GetCurrentRow()+3, value) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // North
        }
        else if(GetGrid(GetCurrentRow()-1, value) == GetCurrentPlayer() && GetGrid(GetCurrentRow()-2, value) == GetCurrentPlayer() && GetGrid(GetCurrentRow()-3, value) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // South
        }

        // Checking Horizontally for winner (EW)
        if(GetGrid(GetCurrentRow(), value+1) == GetCurrentPlayer() && GetGrid(GetCurrentRow(), value+2) == GetCurrentPlayer() && GetGrid(GetCurrentRow(), value+3) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // East
        }
        else if(GetGrid(GetCurrentRow(), value-1) == GetCurrentPlayer() && GetGrid(GetCurrentRow(), value-2)== GetCurrentPlayer() && GetGrid(GetCurrentRow(), value-3) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // West
        }

        // Checking Diagonally for winner (NSEW)
        if(GetGrid(GetCurrentRow()+1, value+1) == GetCurrentPlayer() && GetGrid(GetCurrentRow()+2, value+2) == GetCurrentPlayer() && GetGrid(GetCurrentRow()+3, value+3) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // Northeast
        }
        else if(GetGrid(GetCurrentRow()+1, value-1) == GetCurrentPlayer() && GetGrid(GetCurrentRow()+2, value-2) == GetCurrentPlayer() && GetGrid(GetCurrentRow()+3, value-3) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // Northwest
        }
        else if(GetGrid(GetCurrentRow()-1, value+1) == GetCurrentPlayer() && GetGrid(GetCurrentRow()-2, value+2) == GetCurrentPlayer() && GetGrid(GetCurrentRow()-3, value+3) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // Southeast
        }
        else if(GetGrid(GetCurrentRow()-1, value-1) == GetCurrentPlayer() && GetGrid(GetCurrentRow()-2, value-2) == GetCurrentPlayer() && GetGrid(GetCurrentRow()-3, value-3) == GetCurrentPlayer())
        {
            SetIsWinner(true);
            // Southwest
        }

        //If a winner is determined...
        if(GetIsWinner() == true)
        {
            return true;
        }
        else if(GetCurrentPlayer() == "X") // Else if the current player is Player X, it's Player O's turn.
        {
            SetCurrentPlayer("O");
            return true;
        }
        else if(GetCurrentPlayer() == "O") // Else if the current player is Player O, it's Player X's turn.
        {
            SetCurrentPlayer("X");
            return true;
        }
    }

    void Reset() // Resets Connect 4 grid
    {
       for(int i = 0, j = 0; i < 6; i += 1)
        {
            if(j == 6)
            {
                break;
            }
            
            grid[i][j] = " ";
            
            if(i == 5)
            {
                i = 0;
                j += 1;
            }
        }
        currentRow = 0;
        currentPlayer = "X";
        isWinner = false;
    }

    char CurrentPlayer() const // Determines current player
    {
        if(GetCurrentPlayer() == "X")
        {
            return 'X';
        }
        else if(GetCurrentPlayer() == "O")
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
            out << "[" + GetGrid(0, i) + "] ";
        }
        out << "\n4 "; // Row 4
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + GetGrid(1, i) + "] ";
        }
        out << "\n3 "; // Row 3
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + GetGrid(2, i) + "] ";
        }
        out << "\n2 "; // Row 2
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + GetGrid(3, i) + "] ";
        }
        out << "\n1 "; // Row 1
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + GetGrid(4, i) + "] ";
        }
        out << "\n0 "; // Row 0
        for(int i = 0; i < 8; i += 1)
        {
            out << "[" + GetGrid(5, i) + "] ";
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