#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

namespace EP
{
    class Board
    {
        public:
        std::string board[6];
        static const char tokens[2] = {"O","X"};

        Board()
        {
            for(int i = 0; i < 6; i += 1)
            {
                board[i] = "*******";
            }
        }

        Board(const Board& obj)
        {
            board[6] = obj.board[6];
        }

        Board& operator=(const Board& rhs)
        {
            if(this != &rhs)
            {
                board[6] = rhs.board[6];
            }
            return *this;
        }

        ~Board() {}

        const std::string GetRow(int r)
        {
            if(r <= 6 || r >= 0)
            {
                return board[r];
            }
            else
            {
                return 0;
            }
        }

        static char GetToken(int t)
        {
            if(t = 0 || t = 1)
            {
                return tokens[t];
            }
            else
            {
                return '\0';
            }
        }

        const std::string ToString()
        {
            for(int i = 0; i < 6; i += 1)
            {
                // Insert space between the individual characters within each variable in board[6].
                return board[i];
            }
        }

        std::ostream& operator=(std::ostream& out, const Board& obj)
        {
            out << obj.ToString();
            return out;
        }
    };
}

#endif