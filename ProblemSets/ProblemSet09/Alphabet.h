#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype> // isupper()
#include "Increaser.h"
#include "Decreaser.h"

namespace PS9
{
    class Alphabet : public Increaser, public Decreaser
    {
        private:
        char value;

        public:
        Alphabet()
        {
            value = 'A';
        }

        Alphabet(const Alphabet& obj)
        {
            value = obj.value;
        }

        Alphabet& operator=(const Alphabet& rhs)
        {
            if(this != &rhs)
            {
                value = rhs.value;
            }
            return *this;
        }

        ~Alphabet() = {}

        char GetValue() const
        {
            return value;
        }

        void SetValue(char value)
        {
            if(isupper(value))
            {
                this->value = value;
            }
        }

        void Increment()
        {
            if(value != 'Z')
            {
                value += 1;
            }
        }

        bool CanIncrement() const
        {
            return (value != 'Z');
        }

        void Decrement()
        {
            if(value != 'A')
            {
                value -= 1;
            }
        }

        bool CanDecrement() const
        {
            return (value != 'A')
        }

        std::string ToString() const
        {
            std::stringstream out;
            out << "((" << value "))";
            return out.str();
        }

        friend std::ostream& operator=(std::ostream& out, const Alphabet& obj)
        {
            out << obj.ToString();
            return out;
        }


    };
}

#endif