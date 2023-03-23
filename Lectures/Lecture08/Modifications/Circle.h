#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iomanip>

namespace LZ
{
	class Circle: public Shape
	{
		private:
		double radius;
		static const double PI;

		public:
		Circle() : Circle(1) {}

		Circle(double radius) : radius(radius)
		{
			if(radius <= 0)
			{
				this->radius = 1;
			}
		}

		Circle(const Circle& obj)
		{
			radius = obj.radius;
		}

		Circle& operator=(const Circle& rhs)
		{
			if(this != &rhs)
			{
				radius = rhs.radius;
			}
			return *this;
		}

		~Circle() {}

		double GetRadius() const 
		{
			return radius;
		}

		void SetRadius(double value)
		{
			if(value > 0)
			{
				radius = value;
			}
		}

		virtual double Perimeter() const
		{
			return (2 * radius * PI);
		}

		virtual double Area() const
		{
			return (PI * radius * radius);
		}

		virtual std::string ToString() const
		{
			std::stringstream out;
			out << "[" << std::fixed << std::setprecision(2) << radius << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Circle& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
