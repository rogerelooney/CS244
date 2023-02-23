#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Student.h"
using namespace std;

int main()
{
	srand(time(NULL)); //seed psuedo random generator

	LZ::Student s[4];
	std::string firstNames[4] = {"Mary","Jack","Cathy","Peter"};
	std::string lastNames[4] = {"Johnsons","Michaels","Petersons","Thompsons"};
	int assessments;

	for(int i = 0;i < 4;i += 1)
	{
		assessments = rand() % 6 + 5; //range from 5 to 10 inclusively
		s[i] = LZ::Student(firstNames[i],lastNames[i],assessments);
		
		for(int j = 0;j < assessments;j += 1)
		{
			s[i].Assessment(j,rand() % 101 + 1);
		}
	}

	const LZ::Student t;	

	std::cout << "There are a total of " << t.TotalStudents() << " students\nTheir stats are as follows:\n";

	std::cout << t << "Average: " << t.Average() << "\n\n";

	for(int i = 0;i < 4;i += 1)
	{
		std::cout << s[i] << "Average: " << s[i].Average() << "\n\n";
	}
	
	return 0;
}

