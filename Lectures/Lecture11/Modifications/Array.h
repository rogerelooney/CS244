#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>

template <class T>
class Array 
{
    private:
    T* data;
    unsigned int capacity;

    public:
    Array() : Array(20) {}

    Array(unsigned int size)
    {
        capacity = size;
        data = new T[capacity];

        for(unsigned int i = 0;i < capacity;i += 1)
        {
            data[i] = T();
        }
    }

    Array(unsigned int size,const T& value)
    {
        capacity = size;
        data = new T[capacity];

        for(unsigned int i = 0;i < capacity;i += 1)
        {
            data[i] = value;
        }
    }

    Array(const Array<T>& obj)
    {
        capacity = obj.capacity;
        data = new T[capacity];

        for(unsigned int i = 0;i < capacity;i += 1)
        {
            data[i] = obj.data[i];
        }
    }

    Array<T>& operator=(const Array<T>& rhs)
    {
        if(this != &rhs)
        {
            capacity = rhs.capacity;
            delete[] data;
            data = new T[capacity];

            for(unsigned int i = 0;i < capacity;i += 1)
            {
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }

    ~Array() 
    {
        delete[] data;
    }

    T& operator[](unsigned int idx)
    {
        if(idx >= capacity)
        {
            throw "out of bound";
        }
        return data[idx];
    } 

    const T& operator[](unsigned int idx) const
    {
        if(idx >= capacity)
        {
            throw "out of bound";
        }
        return data[idx];
    } 

    unsigned int Capacity() const 
    {
        return capacity;
    }

    unsigned int Length() const 
    {
        return capacity;
    }

    void Fill(const T& value,int sIdx,int eIdx)
    {
        for(int i = sIdx;i < capacity && i <= eIdx;i += 1)
        {
            data[i] = value;
        }
    }

    friend bool operator==(const Array<T>& lhs,const Array<T>& rhs)
    {
        if(lhs.capacity == rhs.capacity)
        {
            for(unsigned int i = 0;i < lhs.capacity;i += 1)
            {
                if(lhs.data[i] != rhs.data[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    
    std::string ToString() const 
    {
        std::stringstream out;

        out << "[";

        for(unsigned int i = 0;i < capacity;i += 1)
        {
            out << data[i];

            if(i + 1 < capacity)
            {
                out << ",";
            }
        }
        out << "]";
        return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out,const Array<T>& obj)
    {
        out << obj.ToString();
        return out;
    }
};

#endif