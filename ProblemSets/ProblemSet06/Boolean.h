#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <iostream>
#include <string>

class Boolean
{
    public:
    bool value;

    Boolean()
    {
        value = false;
    }

    Boolean(double x)
    {
        x = value;
    }

    Boolean(const Boolean& obj)
    {
        value = obj.value;
    }

    Boolean& operator=(const Boolean& rhs)
    {
        if(this != &rhs)
        {
            value = rhs.value;
        }
        return *this;
    }

    ~Boolean() {}

    const string ToString()
    {
        if(x = true)
        {
        }
        
        if(x = false)
        {
        }
    }
};

#endif