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

int main()
{
	Account a, b(455.50), c = a;
	Checking d, e(455.50), f = d;
	Savings g, h(600.00), i = g;
	Account j = d;

	TypeOfAccount(a);
	TypeOfAccount(d);
	TypeOfAccount(g);
			
	return 0;
}
