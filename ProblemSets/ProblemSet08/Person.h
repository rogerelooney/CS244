#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype> // isalpha()

namespace PS8
{
    class Person
    {
        private:
        std::string firstName;
        std::string lastName;
        std::string middleName;
        unsigned int age;

        bool IsName(std::string value)
        {
            for(int i = 0; i < value.length(); i += 1)
            {
                if(!isalpha(value[i]))
                {
                    return false;
                }
            }
            return true;
        }

        std::string ToCapital(std::string value) const
        {
            if(value == "")
            {
                return "";
            }

            std::string result = "";
            result += toupper(value[0]);

            for(int i = 0; i < value.length(); i += 1)
            {
                result += tolower(value[i]);
            }
            return result;
        }

        public:
        Person()
        {
            firstName = "John";
            lastName = "Smith";
            middleName = " ";
            age = 1;
        }

        Person(const Person& obj)
        {
            firstName = obj.firstName;
            lastName = obj.lastName;
            middleName = obj.middleName;
            age = obj.age;
        }

        Person& operator=(const Person& rhs)
        {
            if(this != &rhs)
            {
                firstName = rhs.firstName;
                lastName = rhs.lastName;
                middleName = rhs.middleName;
                age = rhs.age;
            }
            return *this;
        }

        ~Person() {}

        std::string GetFirstName() const
        {
            return firstName;
        }

        std::string GetLastName() const
        {
            return lastName;
        }

        std::string GetMiddleName() const
        {
            return middleName;
        }

        unsigned int GetAge() const
        {
            return age;
        }

        void SetAge(unsigned int value)
        {
            age = value;
        }

        void SetFirstName(std::string value)
        {
            if(IsName(value))
            {
                firstName = value;
            }
        }

        void SetLastName(std::string value)
        {
            if(IsName(value))
            {
                lastName = value;
            }
        }

        void SetMiddleName(std::string value)
        {
            if(IsName(value))
            {
                middleName = value;
            }
        }

        std::string ToString() const
        {
            std::stringstream out;
            out << ToCapital(firstName) << " " << ToCapital(middleName) << " " << ToCapital(lastName) << "(" << age << ")";
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out, const Person& obj)
        {
            out << obj.ToString();
            return out;
        }
    };
}

#endif