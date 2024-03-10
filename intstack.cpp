#include <iostream>
#include <cstdlib>
#include <ctime>
#include "intstack.hpp"

template <typename T>
Link<T>::Link(T val) : data(val), next(nullptr) {}

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::~Stack(void)
{
    while(this->top != NULL)
    {
        Pop();
    }
}

template <typename T>
Stack<T>::Stack(const Stack& other)
{
    if (other.top != NULL)
    {
        top = new Link<T>(other.top->data);
        Link<T>* current = top;
        Link<T>* otherCurrent = other.top->next;
        while(otherCurrent != NULL)
        {
            current->next = new Link<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}

template <typename T>
void Stack<T>::Print(void)
{
    std::cout << "[";
    struct Link<T>* current = top;
    for (; current != NULL && current->next != NULL ;)
    {
        std::cout << current->data << ",";
        current = current->next;
    }
    std::cout << current->data;
    std::cout << "]" << std::endl;
}

template <typename T>
void Stack<T>::Push(T newData)
{
    struct Link<T>* newLink = new Link<T>(newData);
    newLink->next = top;
    top = newLink;
}

template <typename T>
T Stack<T>::Pop(void)
{
    if (top == NULL)
    {
        return -1; //Valeur de référence pour une pile vide
    }
    T popped = top->data;
    struct Link<T>* poppedLink = top;
    top = top->next;
    delete poppedLink;
    return popped;
}

template <typename T>
bool Stack<T>::IsEmpty(void)
{
    return top == NULL;
}


int main(void)
{
    Stack<float> myStack;
    myStack.Push(1.3);
    myStack.Push(10.1);
    myStack.Print();
    float val= myStack.Pop();
    if (myStack.IsEmpty())
    {
        std::cout << ":(" << std::endl;
    }
    myStack.Pop();
    if (myStack.IsEmpty())
    {
        std::cout << val << std::endl;
    }
    return EXIT_SUCCESS;
}
