#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include "Array.h"

template <class T>
class Stack
{
    private:
    Array<T> data;
    unsigned int top;

    public:
    Stack() : Stack(100) {}

    Stack(unsigned int size) : top(0)
    {
        data = Array<T>(size);
    }

    Stack(const Stack<T>& obj)
    {
        top = obj.top;
        data = obj.data;
    }

    Stack<T>& operator=(const Stack<T>& rhs)
    {
        if(this != &rhs)
        {
            top = rhs.top;
            data = rhs.data;
        }
        return *this;
    }

    ~Stack() {}

    void Push(const T& value)
    {
        if(top < data.Length())
        {
            data[top] = value;
            top += 1;
        }
    } 

    void Pop() 
    {
        if(top > 0)
        {
            top -= 1;
        }
    }

    const T& Top() const 
    {
        if(top == 0)
        {
            throw "stack is empty";
        }
        return data[top-1];
    }

    bool IsEmpty() const 
    {
        return (top == 0);
    }

    bool IsFull() const 
    {
        return (top == data.Length());
    }
    
    std::string ToString() const 
    {
        std::stringstream out;

        for(int i = top-1;i >= 0;i -= 1)
        {
            out << data[i] << "\n";
        }
        return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
    {
        out << obj.ToString();
        return out;
    }
};

#endif