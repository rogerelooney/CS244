#include <iostream>
#include <string>
using namespace std;

void ADT(double a, double b, double c, double* d)
{
	*d = a + b + c;
}

void SWP(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void Prompt1Test()
{
	double x, y, z, w;

	cout << "Enter value for x: ";
	cin >> x;
	cout << "Enter value for y: ";
	cin >> y;
	cout << "Enter value for z: ";
	cin >> z;

	ADT(x, y, z, &w);

	cout << "The sum of the values entered is " << w << "\n";
}

void Prompt2Test()
{
	int x, y;

	cout << "Enter the value of x: ";
	cin >> x;
	cout << "Enter the value of y: ";
	cin >> y;

	cout << "x is currently " << x << " and y is currently " << y << ".\n";
	cout << "However, after a swap x is now ";
	SWP(&x, &y);
	cout << x << " and y is now " << y << ".\n";
}

int main()
{
	

	return 0;
}
