#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <string>
#include <sstream>

#include "Position.h"
#include "AbstractPiece.h"

namespace LB4
{
    class Knight : public ChessPiece
    {
        Knight()
        {
            location[0] = Position::GetX();
            location[1] = Position::GetY();
            moves = 0;
        }

        Knight(const Knight& obj)
        {
            location[2] = obj.location[2];
            moves = obj.moves;
        }

        Knight& operator=(const Knight& rhs)
        {
            if(this != &rhs)
            {
                location[2] = rhs.location[2];
                moves = rhs.moves;
            }
            return *this;
        }

        virtual bool MoveTo()
        {
            location[0] = GetX();
            location[1] = GetY();
            
            if(GetX() == 1 && GetY() == 3) // Up 1, Right 3
            {
                moves += 1;
                return true;
            }
            else if(GetX() == -1 && GetY() == 3) // Down 1, Right 3
            {
                moves += 1;
                return true;
            }
            else if(GetX() == 1 && GetY() == -3) // Up 1, Left 3
            {
                moves += 1;
                return true;
            }
            else if(GetX() == -1 && GetY() == -3) // Down 1, Left 3
            {
                moves += 1;
                return true;
            }
            if(GetX() == 3 && GetY() == 1) // Up 3, Right 1
            {
                moves += 1;
                return true;
            }
            else if(GetX() == -3 && GetY() == 1) // Down 3, Right 1
            {
                moves += 1;
                return true;
            }
            else if(GetX() == 3 && GetY() == -1) // Up 3, Left 1
            {
                moves += 1;
                return true;
            }
            else if(GetX() == -3 && GetY() == -1) // Down 3, Left 1
            {
                moves += 1;
                return true;
            }
            else
            {
                return false;
            }
        }

        virtual std::string ToString() const
        {
            std::stringstream out;
            if(team == true)
            {
                out << "Black Knight " << location[0] << "," << location[1];
            }
            else
            {
                out << "White Knight " << location[0] << "," << location[1];
            }
            return out.str();
        }

    };
}

#endif