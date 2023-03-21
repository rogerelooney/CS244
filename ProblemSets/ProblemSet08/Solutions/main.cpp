#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
using namespace std;
using namespace PS8;

void Prompt1() 
{
	Person p;
	p.SetFirstName("jasmine");
	p.SetLastName("parker");
	p.SetMiddleName("ruby");
	p.SetMiddleName("Mary-Smith");
	p.SetAge(22);

	cout << p << "\n";
}

void Prompt2() 
{
	Student p;
	p.SetFirstName("jasmine");
	p.SetLastName("parker");
	p.SetMiddleName("ruby");
	p.SetAge(22);
	p.SetGPA(3.5);

	Student q = p;

	cout << p << "\n";
	cout << q << "\n";
}

void Prompt3() 
{
	Employee p;
	p.SetFirstName("jasmine");
	p.SetLastName("parker");
	p.SetMiddleName("ruby");
	p.SetAge(22);
	p.SetSalary(1000);
	p.SetHours(15);

	cout << p << "\n";
}
int main()
{
	Prompt3();
	return 0;
}
