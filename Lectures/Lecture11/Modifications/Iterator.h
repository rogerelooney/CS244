#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator 
{
    public:
    virtual bool HasNext() const = 0;
    virtual T& Next() =0;
};

template <class T>
class Iterable 
{
    public:
    virtual Iterator<T>* CreateIterator() =0;
};

#endif