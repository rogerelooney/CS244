#include <iostream>
#include <string>

using namespace std;

void Print(int a[],int n)
{
	std::cout << "{";

	for(int i = 0;i < n;i += 1)
	{
		std::cout << a[i];

		if(i + 1 < n)
		{
			std::cout << ",";
		}
	}
	std::cout << "}\n";
}

int main()
{
	int A[6], B[6], C[6];

	std::cout << std::boolalpha;
	return 0;
}
