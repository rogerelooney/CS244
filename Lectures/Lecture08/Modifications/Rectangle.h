#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iomanip>

namespace LZ
{
	class Rectangle: public Shape
	{
		private:
		double length, width;

		public:
		Rectangle() : Rectangle(1,1) {}

		Rectangle(double length,double width)
		{
			if(length <= 0 || width <= 0)
			{
				this->length = 1;
				this->width = 1;
			}
			else if(length >= width)
			{
				this->length = length;
				this->width = width;
			}
			else
			{
				this->length = width;
				this->width = length;
			}
		}

		Rectangle(const Rectangle& obj)
		{
			length = obj.length;
			width = obj.width;
		}

		Rectangle& operator=(const Rectangle& rhs)
		{
			if(this != &rhs)
			{
				length = rhs.length;
				width = rhs.width;
			}
			return *this;
		}

		~Rectangle() {}

		double GetLength() const 
		{
			return length;
		}

		double GetWidth() const 
		{
			return width;
		}

		void SetLength(double value)
		{
			if(value > 0 && value >= width)
			{
				length = value;
			}
		}

		void SetWidth(double value)
		{
			if(value > 0 && value <= length)
			{
				width = value;
			}
		}

		virtual double Perimeter() const
		{
			return 2 * (length + width);
		}

		double Area() const
		{
			return (length * width);
		}

		virtual std::string ToString() const
		{
			std::stringstream out;
			out << "[" << std::fixed << std::setprecision(2) << width << "," << std::fixed << std::setprecision(2) << length << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Rectangle& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
