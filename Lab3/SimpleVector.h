#pragma once
#include <iostream>
#include <cstdlib>
#include <memory>
#include <string>
#include <cstring>
using namespace std;

// Exception for index out of range
struct IndexOutOfRangeException
{
    const int index;
    IndexOutOfRangeException(int ix) : index(ix) {}
};

template <class T>
class SimpleVector
{
    unique_ptr<T[]> aptr;
    int arraySize;
    int maxSize;
public:
    SimpleVector(int);                   // Constructor
    SimpleVector(const SimpleVector&);  // Copy constructor

    int size() const { return arraySize; }
    T& operator[](int);                  // Overloaded [] operator
    void print() const;                  // outputs the array elements
    void push_back(T var);
    void pop_back();
};

//*******************************************************
// Constructor for SimpleVector class. Sets the size    *
// of the array and allocates memory for it.            *
//*******************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
        maxSize = arraySize = s;
    aptr = make_unique<T[]>(s);
    for (int count = 0; count < arraySize; count++)
        aptr[count] = T();
}
//******************************************************
// Copy Constructor for SimpleVector class.            *
//******************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
   maxSize = arraySize = obj.arraySize;
    aptr = make_unique<T[]>(obj.arraySize);
    for (int count = 0; count < arraySize; count++)
        aptr[count] = obj[count];
}


//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************
template <class T>
T& SimpleVector<T>::operator[](int sub)
{
    if (sub < 0 || sub >= arraySize)
        throw IndexOutOfRangeException(sub);
    return aptr[sub];
}
//********************************************************
// prints all the entries is the array.                  *
//********************************************************
template <class T>
void SimpleVector<T>::print() const
{
    for (int k = 0; k < arraySize; k++)
        cout << aptr[k] << "  ";
    cout << endl;
}
//********************************************************
template <class T>
void SimpleVector<T>::push_back(T var)
{
    if (arraySize < maxSize)
    {
        unique_ptr<T[]> obj = make_unique<T[]>(++arraySize);
        for (int count = 0; count < arraySize; count++)
        {
            obj[count] = aptr[count];
        }
        obj[arraySize-1] = var;
        swap(aptr, obj);
    }
    else {
        cout << "ERROR: Array is full" << endl;
    }
}

template <class T>
void SimpleVector<T>::pop_back() 
{
    if (arraySize > 0)
    {
        unique_ptr<T[]> obj = make_unique<T[]>(--arraySize);
        for (int count = 0; count < arraySize; count++)
            obj[count] = aptr[count];
        swap(aptr, obj);
    }
    
}