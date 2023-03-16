#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

int main()
{
	EP::Board b[3] = {EP::Board(),EP::Board("xxxxxxx"),b[1]};

	for(int i = 0;i < 3;i += 1)
	{
		std::cout << b[i] << "\n";
	}

	return 0;
}
