#ifndef CHECKING_H
#define CHECKING_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Account.h"

namespace LZ
{
	class Checking : public Account
	{
		private:
		double overdraw;

		public:
		Checking() : Checking(50) {} 
		
		Checking(double balance) : Account(balance)
		{
			accountNumber = "6834" + accountNumber.substr(4);
			overdraw = 0;
		}

		Checking(const Checking& obj) : Account(static_cast<const Account&>(obj))
		{
			accountNumber = "6834" + accountNumber.substr(4);
			overdraw = obj.overdraw;
		}

		Checking& operator=(const Checking& rhs)
		{
			if(this != &rhs)
			{
				Account::operator=(static_cast<const Account&>(rhs));
				overdraw = rhs.overdraw;
			}
			return *this;
		}

		~Checking() {}

		void Deposit(double value) 
		{
			if(value > 0)
			{
				if(overdraw > 0 && value <= overdraw)
				{
					overdraw -= value;
				}
				else
				{
					value -= overdraw;
					overdraw = 0;
					Account::Deposit(value);
				}
			}
		}

		void Withdraw(double value)
		{
			if(value > 0)
			{
				if(value > GetBalance()) 
				{
					overdraw = value - GetBalance();
					Account::Withdraw(GetBalance());
				}
				else
				{
					Account::Withdraw(value);
				}
			}
		}

		bool IsOverdrawn() const
		{
			return (overdraw > 0);
		}

		std::string ToString() const
		{
			std::stringstream out;

			if(!IsOverdrawn())
			{
				out << Account::ToString();
			}
			else 
			{	 
				out << "Acct: " << accountNumber << "\n";
				out << "$ (" << std::fixed << std::setprecision(2) << overdraw << ")";
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Checking& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
