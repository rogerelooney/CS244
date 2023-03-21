#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
using namespace PS8;
using namespace std;

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
	p.SetMiddleName("Mary-Smith");
	p.SetAge(22);
	p.SetGPA(3.5);

	cout << p << "\n";
}

void Prompt2()
{
	Employee p;
	p.SetFirstName("jasmine");
	p.SetLastName("parker");
	p.SetMiddleName("ruby");
	p.SetMiddleName("Mary-Smith");
	p.SetAge(22);
	p.SetSalary(1000);
	p.SetHours(15);

	cout << p << "\n";
}

int main()
{
	Prompt1();
	return 0;
}
