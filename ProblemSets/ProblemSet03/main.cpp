#include <iostream>
#include <string>
#include "Prop.h"

using namespace std;

void Print(int a[],int n)
{
	cout << "{";

	for(int i = 0;i < n;i += 1)
	{
		cout << a[i];

		if(i + 1 < n)
		{
			cout << ",";
		}
	}
	cout << "}\n";
}

int main()
{
	int A[6] = {2, 3, 3, 3, 4, 4}, B[6] = {1, 2, 3, 4, 5, 6}, C[6];

	cout << boolalpha;
	cout << "A = "; Print(A,6);
	cout << ((PropertyA::Property(A,6))?("has property"):("does not have property")) << "\n\n";
	cout << "B = "; Print(B,6);
	cout << ((PropertyA::Property(B,6))?("has property"):("does not have property")) << "\n\n";
	return 0;
}
