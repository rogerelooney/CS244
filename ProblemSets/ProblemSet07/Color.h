#ifndef COLOR_H
#define COLOR_H

#include <iostream>

namespace PS7
{
    class Color
    {
        private:
        int red, green, blue;
        public:

        Color()
        {
            red = 0;
            green = 0;
            blue = 0;
        }

        Color(const Color& obj)
        {
            red = obj.red;
            green = obj.green;
            blue = obj.blue;
        }

        Color& operator=(const Color& rhs)
        {
            if(this != &rhs)
            {
                red = rhs.red;
                green = rhs.green;
                blue = rhs.blue;
            }
            return *this;
        }

        ~Color() {};
    };
}

#endif