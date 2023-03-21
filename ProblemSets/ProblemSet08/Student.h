#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Person.h"

namespace PS8
{
    class Student : public Person
    {
        private:
        double GPA;

        public:
        Student()
        {
            GPA = 0;
        }

        Student(const Student& obj) : Person(static_cast<const Person&>(obj))
        {
            GPA = obj.GPA;
        }

        Student& operator=(const Student& rhs)
        {
            if(this != &rhs)
            {
                Person::operator=(static_cast<const Person&>(rhs));
                GPA = rhs.GPA;
            }
            return *this;
        }

        ~Student() {}

        void SetGPA(double value)
        {
            if(value >= 0 && value <= 5)
            {
                GPA = value;
            }
        }

        double GetGPA() const
        {
            return GPA;
        }

        // Overridden Method
        std::string ToString() const
        {
            std:stringstream out;

            out << Person::ToString() << "\nGPA: ";
            out << std::fixed << std::setprecision(1) << GPA;

            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out, const Student& obj)
        {
            out << obj.ToString();
            return out;
        }
    };
}

#endif