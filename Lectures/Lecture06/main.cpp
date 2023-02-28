#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include "DayViewer.h"
using namespace std;

void BuildMap(std::map<std::string,LZ::DayViewer::Month>& obj)
{
	LZ::DayViewer a;
	for(int i = 0;i < 12;i += 1)
	{
		a.SetMonth((LZ::DayViewer::Month)(i));
		obj.insert(std::pair<std::string,LZ::DayViewer::Month>(a.GetMonthName(),a.GetMonth()));
	}
}

void App()
{
	LZ::DayViewer a;
	char ans;
	int value;
	std::map<std::string,LZ::DayViewer::Month> months;

	BuildMap(months);

	while(true)
	{
		std::cout << "\nDate Viewer Menu:\n";
		std::cout << "1. View Date\n";
	        std::cout << "2. View Day\n";
		std::cout << "3. Change Day\n";
		std::cout << "4. View Month\n";
		std::cout << "5. Change Month\n";
		std::cout << "6. View Day Of The Week\n";
		std::cout << "\nEnter choice: ";
		std::cin >> value;

		if(value == 1)
		{
			std::cout << a << "\n";
		}
		else if(value == 2) 
		{
			std::cout << "Day: " << a.GetDay() << "\n";
		}
		else if(value == 3)
		{
			int day;

			std::cout << "Enter a day: ";
			std::cin >> day;

			a.SetDay(day);
		}
		else if(value == 4)
		{
			std::cout << "Month: " << a.GetMonthName() << "\n";
		}
		else if(value == 5)
		{
			std::string month;

			std::cout << "Enter a month (capitalized): ";
			std::cin >> month;

			if(months.find(month) != months.end())
			{
				a.SetMonth(months[month]);
			}
		}
		else if(value == 6)
		{
			std::cout << "Week Day: " << a.GetWeekDay() << "\n";
		}
		else 
		{
			std::cout << "Invalid Choice\n";
		}

		std::cout << "\nContinue [Y]: ";
		std::cin >> ans;

		if(tolower(ans) != 'y')
		{
			break;
		}
	}
}

int main()
{
	App();
	return 0;
}
