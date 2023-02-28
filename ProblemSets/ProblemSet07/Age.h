#ifndef AGE_H
#define AGE_H

#include <iostream>

namespace PS7
{
    class Age
    {
        private:
        int value;
        public:
        Age()
        {
            value = 1;
        }

        Age(const Age& obj)
        {
            value = obj.value;
        }

        Age& operator=(const Age& rhs)
        {
            if(this != &rhs)
            {
                value = rhs.value;
            }
            return *this;
        }

        ~Age() {}


    };
}

#endif