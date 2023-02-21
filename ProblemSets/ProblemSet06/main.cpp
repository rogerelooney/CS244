#include <iostream>
#include <string>
#include "Util.h"
using namespace std;

void Prompt1()
{
	int x, y;

	cout << "Enter an integer: ";
	cin >> x;
	cout << "Enter another integer: ";
	cin >> y;

	cout << "The gcd of " << x << " and " << y << " is " << PS6::GCD(x,y) << "\n";
}

int main()
{
	Prompt1(); 
	return 0;
}
