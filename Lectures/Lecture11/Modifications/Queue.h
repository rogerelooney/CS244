#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "Iterator.h"

template <class T>
class NodeIterator : public Iterator<T>
{
    Node<T>* data;

    public:
    NodeIterator() : data(NULL) {}

    NodeIterator(Node<T>* data) : data(data) {}

    bool HasNext() const 
    {
        return data != NULL;
    }

    T& Next() 
    {
        if(data->GetNext() != NULL)
        {
            data = data->GetNext();
            return data->GetPrev()->GetData();
        }
        else 
        {
            Node<T>* t = data;
            data = data->GetNext();
            return t->GetData();
        }
    }
};

template <class T>
class Queue : public Iterable<T> 
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

    Iterator<T>* CreateIterator() 
    {
        return new NodeIterator<T>(front);
    }
};

#endif