#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <sstream>

namespace LZ
{
	/*Interface*/
	/*interfaces are abstract classes that contains only pure virtual methods*/

	class Shape
	{
		public:
		virtual double Perimeter() const = 0;
		virtual double Area() const = 0;
		virtual std::string ToString() const = 0;
	};
}

#endif
