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

void Prompt1()
{
	Account a, b(455.50), c = a;
	Checking d, e(455.50), f = d;
	Savings g, h(600.00), i = g;
	Account j = d;

	TypeOfAccount(a);
	TypeOfAccount(d);
	TypeOfAccount(g);
}

void WidthdrawAccount(Account& obj,double amount)
{
	if(obj.GetAccountNumber().substr(0,4) == "9999")
	{
		obj.Withdraw(amount);
		cout << obj << "\n";

	}
	else if(obj.GetAccountNumber().substr(0,4) == "8152")
	{
		static_cast<Savings&>(obj).Withdraw(amount);
		cout << static_cast<Savings&>(obj) << "\n";

	}
	else
	{
		static_cast<Checking&>(obj).Withdraw(amount);
		cout << static_cast<Checking&>(obj) << "\n";

	}
}

void Prompt2()
{
	Account a;
	Savings s;
	Checking c;

	WidthdrawAccount(a,100);
	WidthdrawAccount(s,100);
	WidthdrawAccount(c,100);			
}
	
int main()
{
	return 0;
}
