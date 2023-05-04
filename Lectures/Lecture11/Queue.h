#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

template <class T>
class Queue 
{
    private:
    Node<T>* front;
    Node<T>* back;

    public:
    Queue() 
    {
        front = NULL;
        back = NULL;
    }

    void Enqueue(const T& value)
    {
        if(front == NULL)
        {
            front = new Node<T>(value);
            back = front;
        }
        else
        {
            back->SetNext(new Node<T>(value));
            back->GetNext()->SetPrev(back);
            back = back->GetNext();
        }
    }

    void Dequeue()
    {
        if(front != NULL)
        {
            if(front == back)
            {
                delete front;
                front = NULL;
                back = NULL;
            }
            else
            {
                Node<T>* t = front;
                front = front->GetNext();
                front->SetPrev(NULL);
                delete t;
            }
        }
    }

    const T& Peek() const 
    {
        if(front != NULL)
        {
            return front->GetData();
        }
        throw "empty queue";
    }

    bool IsEmpty() const 
    {
        return (front == NULL);
    }

    ~Queue() 
    {
        Node<T>* t;

        while(front != NULL)
        {
            t = front;
            front = front->GetNext();
            delete t;
            t = NULL;
        }
    }
};

#endif