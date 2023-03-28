#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include <string>
#include <sstream>

#include "Position.h"
#include "AbstractPiece.h"

namespace LB4
{
    class Pawn : public ChessPiece
    {
        Pawn()
        {
            location[0] = GetX();
            location[1] = GetY();
            moves = 0;
        }

        Pawn(const Pawn& obj)
        {
            location[2] = obj.location[2];
            moves = obj.moves;
        }

        Pawn& operator=(const Pawn& rhs)
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
            
            if((GetX() == 1 || GetX() == 2) && GetY() == 0)
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
                out << "Black Pawn " << location[0] << "," << location[1];
            }
            else
            {
                out << "White Pawn " << location[0] << "," << location[1];
            }
            return out.str();
        }

    };
}

#endif