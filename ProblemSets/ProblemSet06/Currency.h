#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

class Currency
{
    public:
    double value;
    
    Currency()
    {
        value = 0;
    }

    Currency(double x)
    {
        x = value;
    }

    Currency(const Currency& obj)
    {
        value = obj.value;
    }

    Currency& operator=(const Currency& rhs)
    {
        if(this != &rhs)
        {
            value = rhs.value;
        }
        return *this;
    }

    ~Currency() {}

    const string ToString()
    {
        if(x >= 0)
        {
        }
        
        if(x < 0)
        {
        }
    }
};

#endif