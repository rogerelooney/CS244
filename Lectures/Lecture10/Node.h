#ifndef NODE_H
#define NODE_H

template <class T>
class Node 
{
    private:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const Node<T>& obj);
    Node<T>& operator=(const Node<T>& rhs);

    public:
    Node() : data(T()), next(NULL), prev(NULL) {}
    Node(const T& data) : Node(data,NULL,NULL) {}
    Node(const T& data,Node<T>* prev,Node<T>* next) : data(data), prev(prev), next(next) {}
    const T& GetData() const {return data;}
    T& GetData() {return data;}
    const Node<T>* GetPrev() const {return prev;}
    const Node<T>* GetNext() const {return next;}
    Node<T>* GetPrev() {return prev;}
    Node<T>* GetNext() {return next;}
    void SetData(const T& value) {data = value;}
    void SetPrev(Node<T>* value) {prev = value;}
    void SetNext(Node<T>* value) {next = value;}  
};

/*
template <class T>
class Node
{
    public:
    T data;
    Node<T>* prev;
    Node<T>* next;
};
*/

#endif