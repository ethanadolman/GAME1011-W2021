#ifndef DYNTEMPSTACK_H
#define DYNTEMPSTACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class DynTempStack
{
private:
    class StackNode
    {
        friend class DynTempStack;
        T value;
        StackNode* next;
        // Constructor
        StackNode(T value1, StackNode* next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode* top;
public:
    DynTempStack() { top = NULL; }
    void push(T);
    void pop(T&);
    bool isEmpty() const;
};


//**************************************************
// Member function push pushes the argument onto   *
// the stack.                                      *
//**************************************************
template <class T>
void DynTempStack<T>::push(T num)
{
    top = new StackNode(num, top);
}

//*****************************************************
// Member function pop removes the value at the top   *
// of the stack and copies it into the variable       *
// passed as an argument.                             *
//*****************************************************
template <class T>
void DynTempStack<T>::pop(T& num)
{
    StackNode* temp;

    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        exit(1);
    }
    else   // Pop value off top of stack
    {
        num = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

//*****************************************************
// Member function isEmpty returns true if the stack  *
// is empty, or false otherwise.                      *
//*****************************************************
template <class T>
bool DynTempStack<T>::isEmpty() const
{
    if (!top)
        return true;
    else
        return false;
}


#endif