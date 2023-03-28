#ifndef ABSTRACTPIECE_H
#define ABSTRACTPIECE_H
#include <iostream>
#include <string>
#include <sstream>

#include "Position.h"

namespace LB4
{
    class ChessPiece : protected Position
    {
        protected:
        int location[2];
        bool team;

        private:
        int moves;

        protected:
        void IncrementMoves()
        {
            moves += 1;
        }

        public:
        ChessPiece()
        {
            location[0] = 0;
            location[1] = 0;
            moves = 0;
            team = false;
        }

        ChessPiece()
        {
            location[0] = Position::GetX();
            location[1] = Position::GetY();
            moves = 0;
        }

        ChessPiece(const ChessPiece& obj)
        {
            location[2] = obj.location[2];
            moves = obj.moves;
            team = obj.team;
        }

        ChessPiece& operator=(const ChessPiece & rhs)
        {
            if(this != &rhs)
            {
                location[2] = rhs.location[2];
                moves = rhs.moves;
                team = rhs.team;
            }
            return *this;
        }

        ~ChessPiece() {}

        int GetMoves() const
        {
            return moves;
        }

        virtual bool MoveTo() = 0;

        virtual std::string ToString() const
        {
            std::stringstream out;
            if(team == true)
            {
                out << "Black " << location[0] << "," << location[1];
            }
            else
            {
                out << "White " << location[0] << "," << location[1];
            }
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out,const Position& obj)
		{
			out << obj.ToString();
			return out;
		}
    };
}

#endif