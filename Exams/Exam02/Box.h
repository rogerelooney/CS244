#ifndef BOX_H
#define BOX_H

#include <string>
#include <sstream>

namespace EX
{
    class Box
    {
        private:
        int length, width;

        public:
        Box()
        {
            length = 1;
            width = 1;
        }

        Box(const Box& obj)
        {
            length = obj.length;
            width = obj.width;
        }

        Box operator=(const Box& rhs)
        {
            if(this != rhs)
            {
                length = rhs.length;
                width = rhs.width;
            }
            return *this;
        }

        ~Box() {}

        int GetWidth() const
        {
            return width;
        }

        int GetLength() const
        {
            return length;
        }

        int SetWidth(int value)
        {
            if(value >= 1 && value <= length)
            {
                width = value;
            }
        }

        int SetLength(int value)
        {
            if(value >= width)
            {

            }
        }

        virtual std::string ToString() const
        {
            std::stringstream out;
            out << "(" << width << "," << length << ")";
            return out.str();
        }

        std::string ostream& operator<<(ostream out, const ToString& obj)
        {
            out << obj.Tostring();
            return out;
        }
    };
}

#endif