#ifndef BISHOP_H
#define BISHOP_H
#include <iostream>
#include <string>
#include <sstream>

#include "Position.h"
#include "AbstractPiece.h"

namespace LB4
{
    class Bishop : public ChessPiece
    {
        Bishop()
        {
            location[0] = Position::GetX();
            location[1] = Position::GetY();
            moves = 0;
        }

        Bishop(const Bishop& obj)
        {
            location[2] = obj.location[2];
            moves = obj.moves;
        }

        Bishop& operator=(const Bishop& rhs)
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
            
            if(GetX() >= 0 && GetX() <= 7 && GetY() >= 0 && GetY() <= 7)
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
                out << "Black Bishop " << location[0] << "," << location[1];
            }
            else
            {
                out << "White Bishop " << location[0] << "," << location[1];
            }
            return out.str();
        }

    };
}

#endif