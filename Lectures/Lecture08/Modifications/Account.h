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
		static int accounts; //how many accounts exist
		static int accountMeter; //helps generate the account number
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
			//id = std::string(6-id.length(),'0') + id;
			accountNumber = type_branch + id;
		}

		protected:
		std::string accountNumber;

		public:
		Account() : Account(50) {} 
		
		Account(double balance)
		{
			this->balance = (balance < 50)?(50):(balance);
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

		virtual void Deposit(double amount)
		{
			if(amount > 0)
			{
				balance += amount;
			}
		}

		virtual void Withdraw(double amount)
		{
			if(amount > 0 && balance - amount >= 0)
			{
				balance -= amount;
			}
		}

		virtual std::string ToString() const 
		{
			std::stringstream out;

			out << "Account or Savings ToString()\n";
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
