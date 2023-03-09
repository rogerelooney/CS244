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
		Savings() : Savings(100) {} 
		
		Savings(double balance) : Account(balance)
		{
			accountNumber = "8152" + accountNumber.substr(4);
			interest = 0;
		}

		Savings(const Savings& obj) : Account(static_cast<const Account&>(obj))
		{
			accountNumber = "8152" + accountNumber.substr(4);
			interest = obj.interest;
		}

		Savings& operator=(const Savings& rhs)
		{
			if(this != &rhs)
			{
				Account::operator=(static_cast<const Account&>(rhs));
				interest = rhs.interest;
			}
			return *this;
		}

		~Savings() {}

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
