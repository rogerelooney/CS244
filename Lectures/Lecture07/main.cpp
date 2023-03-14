#include <iostream>
#include <string>
#include <typeinfo>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
using namespace std;
using namespace LZ;

void TypeOfAccount(const Account& obj)
{
	if(typeid(obj) == typeid(Account))
	{
		std::cout << "Account Object\n";
	}
	else if(typeid(obj) == typeid(Checking))
	{
		std::cout << "Checking Object\n";
	}
	else if(typeid(obj) == typeid(Savings))
	{
		std::cout << "Savings Object\n";
	}
	else 
	{
		std::cout << "Unknown Object\n";
	}
}

void Prompt0()
{
	Account a, b(455.50), c = a;
	Checking d, e(455.50), f = d;
	Savings g, h(600.00), i = g;
	Account j = d;

	TypeOfAccount(a);
	TypeOfAccount(d);
	TypeOfAccount(g);
}

void Prompt1()
{
	Account a[4] = {Account(),Account(75.0),Account(500.0),a[1]};

	for(int i = 0;i < 4;i += 1)
	{
		cout << a[i] << "\n";
	}

	double amount;
	char c;

	for(int i = 0;i < 4;i += 1)
	{
		while(true)
		{
			cout << "For account: " << a[i].GetAccountNumber() << " would you like to\n";
			cout << "(D)eposit\n";
			cout << "(W)ithdraw\n";
			cout << "\nEnter choice: ";
			cin >> c;
			c = toupper(c);

			if(c == 'D' || c == 'W')
			{
				break;
			}
		}

		cout << "Enter the amount: ";
		cin >> amount;

		if(c == 'D')
		{
			a[i].Deposit(amount);
		}
		else
		{
			a[i].Withdraw(amount);
		}
		cout << "\nNew balance is " << a[i].GetBalance() << "\n\n";
	}
}

void Prompt2()
{
	Savings a[4] = {Savings(),Savings(75.0),Savings(500.0),a[1]};

	for(int i = 0;i < 4;i += 1)
	{
		cout << a[i] << "\n";
	}

	double amount;
	char c;

	for(int i = 0;i < 4;i += 1)
	{
		while(true)
		{
			cout << "For account: " << a[i].GetAccountNumber() << " would you like to\n";
			cout << "(D)eposit\n";
			cout << "(W)ithdraw\n";
			cout << "(A)dd Interest\n";
			cout << "\nEnter choice: ";
			cin >> c;
			c = toupper(c);

			if(c == 'D' || c == 'W' || c == 'A')
			{
				break;
			}
		}

		cout << "Enter the amount: ";
		cin >> amount;

		if(c == 'D')
		{
			a[i].Deposit(amount);
		}
		else if(c == 'W')
		{
			a[i].Withdraw(amount);
		}
		else
		{
			a[i].ApplyInterest();
		}

		cout << "\nNew balance is " << a[i].GetBalance() << "\n\n";
	}
}

int main()
{
	Prompt2();			
	return 0;
}