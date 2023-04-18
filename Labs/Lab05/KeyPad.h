#ifndef KEYPAD_H
#define KEYPAD_H
#include <string>
#include <sstream>

using namespace std;

namespace LB5
{
    class Encoder
    {
        public:
        virtual std::string Encipher() = 0;
    };

    class KeyPad
    {
        private:
        std::string contents;

        public:
        KeyPad()
        {
            contents = " ";
        }

        KeyPad(const KeyPad& obj)
        {
            contents = obj.contents;
        }

        KeyPad operator=(const KeyPad& rhs)
        {
            if(this != &rhs)
            {
                contents = rhs.contents;
            }
            return *this;
        }

        ~KeyPad() {}

        virtual std::string CreateEncoder() = 0;

        void AddValue(char value)
        {
            if(value == 0 || value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7 || value == 8 || value == 9)
            {
                contents = contents + value;
            }
        }

        virtual std::string ToString() const
        {
            std::stringstream out;
            out << Encipher();
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out,const KeyPad& obj)
		{
			out << obj.ToString();
			return out;
		}
    };
}

#endif