#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <iomanip>

namespace LZ
{
	/*Abstract Class*/
	class Triangle: public Shape
	{
		private:
		double sides[3];

		void Sort()
		{
			/*sort in ascending order*/
			for(int i = 2;i > 0;i -= 1)
			{
				for(int j = 0;j < i;j += 1)
				{
					if(sides[j] > sides[j+1])
					{
						t = sides[j];
						sides[j] = sides[j+1];
						sides[j+1] = t;
					}
				}
			}
		}

		public:
		Triangle() : Triangle(1,1,1) {}

		Triangle(double a, double b, double c) : sides{a,b,c}
		{
			double t;

			if(a <= 0 || b <= 0 || c <= 0)
			{
				for(int i = 0;i < 3;i += 1)
				{
					sides[i] = 1;
				}
			}
			else
			{
				Sort();
			}
		}

		Triangle(const Triangle& obj)
		{
			for(int i = 0;i < 3;i += 1)
			{
				sides[i] = obj.sides[i];
			}
		}

		Triangle& operator=(const Triangle& rhs)
		{
			if(this != &rhs)
			{
				for(int i = 0;i < 3;i += 1)
				{
					sides[i] = rhs.sides[i];
				}
			}
			return *this;
		}

		~Triangle() {}

		double operator[](int idx) const
		{
			if(idx >= 0 && idx < 3)
			{
				return sides[idx];
			}
			throw "not a side";
		}

		double GetSide(int idx) const 
		{
			if(idx >= 0 && idx < 3)
			{
				return sides[idx];
			}
			throw "not a side";
		}

		void SetSide(int idx, double value)
		{
			if(value > 0 && idx >= 0 && idx < 3)
			{
				sides[idx] = value;
				Sort();
			}
		}

		double Perimeter() const 
		{
			double sum = 0;

			for(int i = 0;i < 3;i += 1)
			{
				sum += sides[i];
			}
			return sum;
		}

		std::string ToString() const
		{
			std::stringstream out;
			out << "[";

			for(int i = 0;i < 3;i += 1)
			{
				out << std::fixed << std::setprecision(2) << sides[i];
			       	
				if(i + 1 < 3)
				{
					out << ",";
				}
			}	
		       	out << "]";
			return out.str();
		}
	};
}

#endif
