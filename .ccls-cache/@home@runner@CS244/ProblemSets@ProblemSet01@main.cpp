#include <iostream>
#include <string>
#include <cctype> //isalpha() 
using namespace std;

//Define Functions Here
void INIT(int a[], int n, int x)
{
  for(int i = 0; i < n; i += 1)
    {
      a[i] = x;
    }
}
// void PSLTEN();
// bool ISWRD();
// double M03();

int main()
{
	//Test Functions Here
	int arr[20];
  INIT(arr, 20, 7);

  cout << "{";
  for(int i = 0; i < 20; i += 1)
    {
      cout << arr[i];

      if(i + 1 < 20)
      {
        cout << ",";
      }
    }
  cout << "}\n";
	return 0;
}