#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <iomanip>

namespace LZ
{
	class Square: public Rectangle
	{
		private:
		/*modify access to base members*/
		using Rectangle::GetLength;
		using Rectangle::GetWidth;
		using Rectangle::SetLength;
		using Rectangle::SetWidth;

		public:
		Square() : Rectangle(1,1) {}

		Square(double side) : Rectangle(side,side) {}

		Square(const Square& obj) : Rectangle(static_cast<const Rectangle&>(obj)) {}

		Square& operator=(const Square& rhs)
		{
			if(this != &rhs)
			{
				Rectangle::operator=(static_cast<const Rectangle&>(rhs));
			}
			return *this;
		}

		~Square() {}

		double GetSide() const 
		{
			return Rectangle::GetLength();
		}

		void SetSide(double value)
		{
			if(value > 0 && value > GetSide())
			{
				Rectangle::SetLength(value);
				Rectangle::SetWidth(value);
			}
			else
			{
				Rectangle::SetWidth(value);
				Rectangle::SetLength(value);
			}
		}

		std::string ToString() const
		{
			std::stringstream out;
			out << "[" << std::fixed << std::setprecision(2) << GetSide() << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Square& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
