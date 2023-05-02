#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <string>
#include <sstring>
#include <cctype>
using namespace std;

namespace EX
{
    class Name
    {
        private:
        string name[3];

        public:
        Name()
        {
            for(int i = 0; i < 3; i += 1)
            {
                if(i == 0)
                {
                    name[i] = "Jane";
                }

                if(i == 1)
                {
                    name[i] = "";
                }

                if(i == 2)
                {
                    name[i] = "Doe";
                }
            }
        }

        Name(const Name& obj)
        {
            for(int i = 0; i < 3; i += 1)
            {
                name[i] = obj.name[i];
            }
        }

        Name operator=(const Name& rhs)
        {
            if(this != rhs)
            {
                for(int i = 0; i < 3; i += 1)
                {
                    name[i] = rhs.name[i];
                }
            }
            return *this;
        }

        Name() {}

        string GetGivenName() const
        {
            return name[0] << " " << name[2];
        }

        string GetSurname() const
        {
            return name[2];
        }

        void SetFirstName(string value)
        {
            if(isAlpha(value))
            {
                name[0] = value;
            }
        }

        void SetMiddleName(string value)
        {
            if(isAlpha(value))
            {
                name[1] = value;
            }
        }

        void SetLastName(string value)
        {
            if(isAlpha(value))
            {
                name[2] = value;
            }
        }

        virtual string ToString() const
        {
            stringstream out;

            out << name[2] << "," << name[0];
            
            if(name[1] != "")
            {
                out << " " << name[1];
            }

            return out.str();
        }

        string ostream& operator<<(ostream out, const ToString& obj)
        {
            out << obj.Tostring();
            return out;
    };
}

#endif