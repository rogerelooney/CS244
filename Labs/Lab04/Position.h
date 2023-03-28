#ifndef POSITION_H
#define POSITIONT_H

#include <iostream>
#include <string>
#include <sstream>

namespace LB4
{
	class Position
	{
		private:
		int x;
		int y;

		public:
		Position() 
		{
			x = 0;
			y = 0;
		}

		Position(int x,int y) : Position() 
		{
			SetX(x);
			SetY(y);
		}

		Position(const Position& obj)
		{
			x = obj.x;
			y = obj.y;
		}

		Position& operator=(const Position& rhs)
		{
			if(this != &rhs)
			{
				x = rhs.x;
				y = rhs.y;
			}
			return *this;
		}

		~Position() {}

		int GetX() const 
		{
			return x;
		}

		int GetY() const 
		{
			return y;
		}

		void SetX(int value)
		{
			if(value >= 0 && value <= 7)
			{
				x = value;
			}
		}

		void SetY(int value)
		{
			if(value >= 0 && value <= 7)
			{
				y = value;
			}
		}

		std::string ToString() const
		{
			std::stringstream out;
			out << "(" << x << "," << y << ")";
			return out.str();
		}

		std::ostream& operator<<(std::ostream& out,const Position& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
