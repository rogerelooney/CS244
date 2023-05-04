#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
    Stack<char> a;
    Queue<char> b;

    for(char c = 'A'; c <= 'Z';c += 1)
    {
        a.Push(c);
        b.Enqueue(c);
    }

    Iterator<char>* i = a.CreateIterator();

    while(i->HasNext())
    {
        std::cout << i->Next();
    }
    std::cout << "\n";
    delete i;


    i = b.CreateIterator();

    while(i->HasNext())
    {
        std::cout << i->Next();
    }
    std::cout << "\n";
    delete i;

    return 0;
}