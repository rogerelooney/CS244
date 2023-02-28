#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>

namespace PS7
{
    class Word
    {
        private:
        string value;
        public:
        Word()
        {
            value = "word";
        }

        Word(const Word& obj)
        {
            value = obj.value;
        }

        Word& operator=(const Word& rhs)
        {
            if(this != &rhs)
            {
                value = rhs.value;
            }
            return *this;
        }

        ~Word() {}

        
    };
}

#endif