#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

namespace PS6
{
    class Rational
    {
        public:
        int values[2];

        Rational()
        {
            values[0] = 0;
            values[1] = 1;
        }

        Rational(int x, int y)
        {
            x = values[0];
            y = values[1];
        }

        Rational(const Rational& obj)
        {
            values[2] = obj.values[2];
        }
        
        Rational& operator=(const Rational& rhs)
        {
            if(this != &rhs)
            {
                values[2] = rhs.values[2];
            }
            return *this;
        }
        
        ~Rational() {}

        const string ToString()
        {
            if(abs(y) = 1)
            {
            }

            if(y = 0)
            {
            }

            if(x = 0 && y != 0)
            {
            }

            if(x * y > 0)
            {
            }

            if(x * y < 0)
            {
            }
        }
    };
}

#endif