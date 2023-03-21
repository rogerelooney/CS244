#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Person.h"

namespace PS8
{
    class Employee : public Person
    {
        private:
        double salary;
        unsigned int hours;

        public:
        Employee()
        {
            salary = 300;
            hours = 5;
        }

        Employee(const Employee& obj) : Person(static_cast<const Person&>(obj))
        {
            salary = obj.salary;
            hours = obj.hours;
        }

        Employee& operator=(const Employee& rhs)
        {
            if(this != &rhs)
            {
                Person::operator=(static_cast<const Person&>(rhs));
                salary = rhs.salary;
                hours = rhs.hours;
            }
            return *this;
        }

        ~Employee() {}

        void SetSalary(double value)
        {
            if(value >= 100)
            {
                salary = value;
            }
        }

        void SetHours(unsigned int value)
        {
            if(value >= 1 && value <= 112)
            {
                hours = value;
            }
        }

        double GetSalary() const
        {
            return salary;
        }

        unsigned int GetHours() const
        {
            return hours;
        }

        // Overridden Method
        std::string ToString() const
        {
            std:stringstream out;

            out << Person::ToString() << "\n$ ";
            out << std::fixed << std::setprecision(2) << salary;
            out << " Hours: " << hours;

            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out, const Employee& obj)
        {
            out << obj.ToString();
            return out;
        }
    };
}

#endif