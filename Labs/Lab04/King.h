#ifndef KING_H
#define KING_H
#include <iostream>
#include <string>
#include <sstream>

#include "Position.h"
#include "AbstractPiece.h"

namespace LB4
{
    class King : public ChessPiece
    {
        King()
        {
            location[0] = Position::GetX();
            location[1] = Position::GetY();
            moves = 0;
        }

        King(const King& obj)
        {
            location[2] = obj.location[2];
            moves = obj.moves;
        }

        King& operator=(const King& rhs)
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
            
            if(GetX() == 1 || GetX() == -1 || GetY() == 1 || GetY() == -1) // Up, Down, Right, Left
            {
                moves += 1;
                return true;
            }
            else if(GetX() == 1 && GetY() == 1) // Up, Right
            {
                moves += 1;
                return true;
            }
            else if(GetX() == 1 && GetY() == -1) // Up, Left
            {
                moves += 1;
                return true;
            }
            else if(GetX() == -1 && GetY() == 1) // Down, Right
            {
                moves += 1;
                return true;
            }
            else if(GetX() == -1 && GetY() == -1) // Down, Left
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
                out << "Black King " << location[0] << "," << location[1];
            }
            else
            {
                out << "White King " << location[0] << "," << location[1];
            }
            return out.str();
        }

    };
}

#endif