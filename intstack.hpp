#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
struct Link
{
    T data;
    struct Link* next;
    Link(T val);
};

template <typename T>
struct Stack
{
    struct Link<T>* top;
    Stack();
    ~Stack();
    Stack(const Stack& other);
    void Print();
    void Push(T newElement);
    T Pop();
    bool IsEmpty();
};
