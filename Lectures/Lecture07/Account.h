#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace LZ
{
	class Account
	{
		private:
		static int accounts;
		static int accountMeter;
		double balance;

		void GenerateAccountNumber()
		{
			std::string type_branch = "9999319244";
			std::string id = std::to_string(accounts) + std::to_string(accountMeter);
			accountMeter += 1;
			
			while(id.length() < 6)
			{
				id = "0" + id;
			}
			accountNumber = type_branch + id;
		}

		protected:
		std::string accountNumber;

		public:
		Account() : Account(100) {} 
		
		Account(double balance)
		{
			this->balance = (balance < 100)?(100):(balance);
			GenerateAccountNumber();
			accounts += 1;
		}

		Account(const Account& obj)
		{
			balance = obj.balance;
			GenerateAccountNumber();
			accounts += 1;
		}

		Account& operator=(const Account& rhs)
		{
			if(this != &rhs)
			{
				balance = rhs.balance;
			}
			return *this;
		}

		~Account() 
		{
			accounts -= 1;
		}

		double GetBalance() const 
		{
			return balance;
		}

		std::string GetAccountNumber() const 
		{
			return accountNumber;
		}

		static int GetTotalAccounts() 
		{
			return accounts;
		}

		void Deposit(double amount)
		{
			if(amount > 0)
			{
				balance += amount;
			}
		}

		void Withdraw(double amount)
		{
			if(amount > 0 && balance - amount >= 0)
			{
				balance -= amount;
			}
		}

		std::string ToString() const 
		{
			std::stringstream out;

			out << "Acct: " << accountNumber << "\n";
			out << "$ " << std::fixed << std::setprecision(2) << balance;
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Account& obj)
		{
			out << obj.ToString();
			return out;
		}
	};

	int Account::accounts = 0;
	int Account::accountMeter = 7000;		
}

#endif
