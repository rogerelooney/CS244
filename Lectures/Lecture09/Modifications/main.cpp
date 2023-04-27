#include <iostream>
#include "Array.h"
#include "Stack.h"

int main()
{
    Array<std::string> a(16);
    Array<int> b(4,9);
    Array<char> c;
    
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n\n";

    std::cout << "|a| = " << a.Length() << "\n";
    std::cout << "|b| = " << b.Capacity() << "\n";
    std::cout << "|c| = " << c.Length() << "\n\n";

    a[7] = "five"; 
    b[2] = 1;
    c[9] = 'u';

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n\n";

    a.Fill("key",0,4);
    b.Fill(8,3,3);
    c.Fill('o',6,13);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n\n";

    Array<int> d = b;
    d[1] = 6;

    std::cout << std::boolalpha;
    std::cout << (d == b) << "\n";

    Stack<std::string> states;

    states.Push("US");
    states.Push("CA");
    states.Push("OH");

    std::cout << states << "\n";

    states.Pop();

    std::cout << states << "\n";

    return 0;
}