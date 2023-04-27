#include <iostream>
#include <string>
#include <typeinfo>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
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
	obj.Withdraw(amount);
	cout << obj << "\n";
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

void ShapeStats(const Shape& obj)
{
	cout << "Area: " << obj.Area() << "\n";
	cout << "Perimeter: " << obj.Perimeter() << "\n";
	cout << "Diminsions: " << obj << "\n";
}

void Prompt4() 
{
	Shape* a[4] = {new Rectangle(17,38), new Square(10), new Circle(4), new Triangle(3,4,5)};

	for(int i = 0;i < 4;i += 1)
	{
		cout << "Shape " << (i + 1) << ":\n";
		ShapeStats(*a[i]);
		cout << "\n";
	}

	for(int i = 0;i < 4;i += 1)
	{
		delete a[i];
	}
}

int main()
{
	Prompt1();
	return 0;
}
