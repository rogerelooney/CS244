#include <iostream>
#include <string>
#include "Person.h"
#include "Window.h"
#include "Pin.h"

using namespace std;
using namespace PS4;

string FormatInfo(Person& obj)
{
	return (obj.lastName + "," + obj.firstName + " (" + to_string(obj.age) + ")");
}

int main()
{
	Person a;
	a.firstName = "John";
	a.lastName = "Doe";
	a.age = 20;

	cout << FormatInfo(a) << "\n";

	return 0;
}
