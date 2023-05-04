#include <iostream>
#include <string>
#include "Queue.h"

int main()
{
    Queue<int> q;

    for(int i = 100;i <= 200;i += 20)
    {
        q.Enqueue(i);
        std::cout << i << " ";
    }
    std::cout << "\n";

    while(!q.IsEmpty())
    {
        std::cout << q.Peek() << " ";
        q.Dequeue();
    }
    std::cout << "\n";
    return 0;
}