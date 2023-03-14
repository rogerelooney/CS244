// Derived Classes do not inherit the special member functions and friends of its base class.
// Derived Classes can inherit multiple base classes, but its not recommended at this stage.
// Derived Classes only have direct access to public and protected members of its base class.
#ifndef SAVINGS_H
#define SAVINGS_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Account.h"

namespace LZ
{
	class Savings : public Account
	{
		private:
		double interest;
		static const double interestRate;

		public:
		Savings() : Savings(50)
		{
			std::cout << "Savings Default Constructor Called\n";
		} 
		
		Savings(double balance) : Account(balance)
		{
			accountNumber = "8152" + accountNumber.substr(4);
			interest = 0;
			std::cout << "Savings Overloaded Constructor Called\n";
		}

		Savings(const Savings& obj) : Account(static_cast<const Account&>(obj))
		{
			accountNumber = "8152" + accountNumber.substr(4);
			interest = obj.interest;
			std::cout << "Savings Copy Constructor Called\n";
		}

		Savings& operator=(const Savings& rhs)
		{
			if(this != &rhs)
			{
				Account::operator=(static_cast<const Account&>(rhs)); // Invoking Base Class Method
				interest = rhs.interest;
			}
			return *this;
		}

		~Savings()
		{
			std::cout << "Savings Destructor Called\n";
		}

		double GetInterest() const
		{
			return interest;
		}

		void ApplyInterest() 
		{
			double value = (GetBalance() + interest) * interestRate;
			interest += value;
			Deposit(value);
		}

		//Function Overridding
		std::string ToString() const
		{
			std::stringstream out;
	 
			out << "Acct: " << accountNumber << "\n";
			out << "$ " << std::fixed << std::setprecision(2) << (GetBalance() + interest);
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Savings& obj)
		{
			out << obj.ToString();
			return out;
		}
	};

	const double Savings::interestRate = 0.02;
}

#endif
