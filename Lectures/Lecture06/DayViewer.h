/***Lecture 06***
 * Encapsulation is the process of protecting data [and other members] from direct access. 
 * It is implemented by using the private access specifier; and using methods for read and/or write access to fields (or field conceptions). 
 * Methods used strictly for reading (accessing but not assigning) fields are called getter methods
 * The standard format of a getter method is: <<return-type>> <<identifier>>() const
 * The return type of a getter method is the data type of the field the getter method is providing access to
 * A getter method does not need to be constant
 * Methods used strictly for writing to (assigning) fields are called setter methods
 * The standard format of a setter method is: void <<identifier>>(<<data-type>>) 
 * The data type of the parameter of the setter method is the data type of the field the setter method is providing access to
 * A setter method can never be constant
 * For array fields, both getter and setter methods take an additional parameter for the index. 
 * Likewise, the subscript operator ([]) can be overloaded for array fields. Usually, only use it 
 * as a getter method if there are special criteria for assigning values to the elements of the array
 * field.
 */
#ifndef DAYVIEWER_H
#define DAYVIEWER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace LZ
{
	class DayViewer
	{
		public:
		/*Enumeration*/
		enum Month
		{
			JANUARY = 0,
			FEBRUARY,
			MARCH,
			APRIL, 
			MAY,
			JUNE,
			JULY,
			AUGUST,
			SEPTEMBER,
			OCTOBER,
			NOVEMBER,
			DECEMBER
		};

		private:
		Month month;
		int day;
		int weekDay;
		bool mode;
		static const std::string WEEKDAYS[7];
		static const std::string MONTHS[12];
		static const int MONTHS_DAYS[12];
		static const int OFFSETS[12];

		/*Setter Method for weekDay field*/
		/*The format differs from the standard format since the weekDay
		 * field is modified whenever the other fields are modified*/ 
		void SetWeekDay() 
		{
			weekDay = (month * 30 + OFFSETS[month] + (day - 1)) % 7;
		}

		public:
		DayViewer() : month(JANUARY), day(1), mode(true) 
		{
			SetWeekDay();
		}
		
		DayViewer(const DayViewer& obj)
		{
			month = obj.month;
			day = obj.day;
			weekDay = obj.weekDay;
		}

		DayViewer& operator=(const DayViewer& rhs)
		{
			if(this != &rhs)
			{
				month = rhs.month;
				day = rhs.day;
				weekDay = rhs.weekDay;
			}
			return *this;
		}

		~DayViewer() {}

		/*Getter Methods*/
		Month GetMonth() const 
		{
			return month;
		}

		int GetDay() const 
		{
			return day;
		}

		std::string GetWeekDay() const 
		{
			return WEEKDAYS[weekDay];
		}

		std::string GetMonthName() const
		{
			return MONTHS[month];
		}

		/*Setter Methods*/
		void SetMonth(Month value)
		{
			if(value >= JANUARY && value <= DECEMBER) 
			{
				month = value;
				
				if(day > MONTHS_DAYS[month])
				{
					day = 1;
				}
				SetWeekDay();
			}
		}

		void SetDay(int value)
		{
			if(value > 0 && value <= MONTHS_DAYS[month])
			{
				day = value;
				SetWeekDay();
			}
		}	

		void ToggleMode() 
		{
			mode = !mode;
		}

		/*ToString() Method*/
		std::string ToString() const 
		{
			std::stringstream out;

			if(mode)
			{
				out << WEEKDAYS[weekDay] << ", " << MONTHS[month] << " " << std::setw(2) << std::setfill('0') << day;
			}
			else 
			{
				out << std::setw(2) << std::setfill('0') << ((int)(month) + 1) << "/" << std::setw(2) << std::setfill('0') << day << "/2023 (" << WEEKDAYS[weekDay] << ")"; 
			}
		    return out.str();
		}

		/*osteam operator*/
		friend std::ostream& operator<<(std::ostream& out,const DayViewer& obj)
		{
			out << obj.ToString();
			return out;
		}	
	};

	const std::string DayViewer::WEEKDAYS[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	const std::string DayViewer::MONTHS[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	const int DayViewer::MONTHS_DAYS[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	const int DayViewer::OFFSETS[12] = {0,1,-1,0,0,1,1,2,3,3,4,4};

}
#endif
