/***Methods***/
/* Method Information:
 * 01. methods are shared members; hence there is a single copy of a method in a class
 * 02. there are three types of methods, namely instance methods, constant methods, and static methods
 * 03. instance methods modify the fields of the correct class object because it implicitly contains 
 * the this pointer as a parameter.
 * 04. instance methods cannot be accessed by constant class objects
 * 05. constant methods are similar to instance methods except for the implicit this pointer parameter is
 * constant
 * 06. fields cannot be modifed in constant methods.
 * 07. only constant methods can be invoked in constant methods.
 * 08. constant methods can be alloed by any type of class object.
 * 09. static methods do not contain the implicit this pointer parameter; hence, they cannot allow
 * instance fields.
 * 10. static methods can allow static fields.
 * 11. static methods can be allowed with or without a class object.
 * 12. static methods can be allowed by any type of class object.
 * 13. static methods cannot be constant methods.
 * 14. making the ostream operator a friend of a class, allows class objects to be displayed by 
 * any ostream object such as cout
 * 15. instance method syntax: <<FUNCTION-HEADER>> {<<BODY>>}
 * 16. constant method syntax: <<FUNCTION-HEADER>> const {<<BODY>>}
 * 17. static method syntax: static <<FUNCTION-HEADER>> {<<BODY>>}
 * 18. ostream operator syntax: 
 * friend operator<<(ostream& <<IDENTIFIER>>,const <<CLASS-NAME>>& <<IDENTIFIER>>) {<<BODY>>}
 */
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace LZ
{
	class Student
	{
		public:
		double* grades;
		int amount;
		std::string firstName;
		std::string lastName;
		static int count;

		/*Default Constructor*/
		Student() 
		{
			firstName = "John";
			lastName = "Smith";
			amount = 4;
			grades = new double[amount];
			count += 1;

			for(int i = 0;i < 4;i += 1)
			{
				grades[i] = 0.0;
			}
		}

		/*Overloaded Construtor*/
		Student(std::string firstName,std::string lastName,int assessments)
		{
			this->firstName = firstName;
			this->lastName = lastName;
			this->amount = (assessments > 1)?(assessments):(4);
			grades = new double[amount];
			count += 1;

			for(int i = 0;i < amount;i += 1)
			{
				grades[i] = 0.0;
			}
		}

		/*Overloaded Construtor - uses member-initialization list to delegate initialization
		 * to another constructor*/
		Student(std::string firstName,std::string lastName) : Student(firstName,lastName,4) {}

		/*Copy Constructor - performs a deep copy*/
		Student(const Student& obj)
		{
			firstName = obj.firstName;
			lastName = obj.lastName;
			amount = obj.amount;
			grades = new double[amount];

			for(int i = 0;i < amount;i += 1)
			{
				grades[i] = obj.grades[i];
			}
			count += 1;
		}

		/*Assignment Operator - performs a deep copy*/
		Student& operator=(const Student& rhs)
		{
			if(this != &rhs)
			{
				firstName = rhs.firstName;
				lastName = rhs.lastName;
				amount = rhs.amount;
				/*must deallocate first*/
				delete[] grades;
				grades = new double[amount];

				for(int i = 0;i < amount;i += 1)
				{
					grades[i] = rhs.grades[i];
				}
			}
			return *this;
		}

		/*Destructor*/
		~Student() 
		{
			delete[] grades;
			count -= 1;
		}

		/*Instance Method*/
		bool Assessment(unsigned int idx,double grade)
		{
			if(idx >= amount)
			{
				return false;
			}
			grades[idx] = grade;
			return true;
		}

		/*Instance Method*/
		int Assessments() 
		{
			return amount;
		}

		/*Constant Method - its an overloaded function*/
		int Assessments() const
		{
			return amount;
		}

		/*Constant Method*/
		double Average() const 
		{
			double sum = 0.0;

			for(int i = 0;i < amount;i += 1)
			{
				sum += grades[i];
			}
			return (sum / amount);
		}

		/*Static Method*/
		static int TotalStudents() 
		{
			return count;
		}

		/*ToString() Constant Method - uses stringstream object to format string outcome*/
		std::string ToString() const
		{
			std::stringstream out; 
			
			out << lastName << ", " << firstName << "\n";
			out << "Grades:\n";

			for(int i = 0;i < amount;i += 1)
			{
				out << "Assessment ";
			       	if(i < 9)
				{
					out << "0" << (i + 1);
				}
				else
				{
					out << (i + 1);
				}
				out << std::setw(4) << " " <<  std::fixed << std::setprecision(1) << grades[i] << "\n";
			}
			return out.str();
		}

		/*Friend Function Ostream Operator - allows Student object to be displayed using cout*/
		friend std::ostream& operator<<(std::ostream& out,const Student& obj)
		{
			out << obj.ToString();
			return out;
		}	
	};

	int Student::count = 0;	

}

#endif
