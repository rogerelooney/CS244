#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <string>

class Password
{
    private:
    string value;

    public:
    Password()
    {
        value = "password";
    }

    Password(const Password& obj)
    {
        value = obj.value;
    }

    Password& operator=(const Password& rhs)
    {
        value = rhs.value;
    }

    ~Password() {}

    string setValue()
    {

    }

    const string ToString()
    {

    }

    friend ostream& operator<<(ostream& out, const Card& obj)
        {
            out << obj.ToString();
            return out;
        }
};

#endif