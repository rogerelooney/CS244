#include <iostream>
#include <string>
using namespace std;

string SpokenNumber(int n)
{
	string spoken, numbers[100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "thirty", "thirty one", "thirty two", "thirty three", "thirty four", "thirty five", "thirty six"}; // "thirty seven", ... , "ninety nine"
	
	if(n <= 0 || n >= 99)
	{
		spoken = numbers[n];
		return spoken;
	}
	else
	{
		return "Cannot Translate";
	}
}

int main()
{
	SpokenNumber(27);
	return 0;
}
