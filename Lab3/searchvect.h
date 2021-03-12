#pragma once
#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
    // Constructor.
    SearchableVector(int s) : SimpleVector<T>(s)
    { }
    // Copy constructor.		
    SearchableVector(const SearchableVector&);
    // Additional constructor. 
    SearchableVector(const SimpleVector<T>& obj) :
        SimpleVector<T>(obj) { }
    int findItem(T);
};

//******************************************
// Definition of the copy constructor.     *
//******************************************
template <class T>
SearchableVector<T>::
SearchableVector(const SearchableVector& obj) :
    SimpleVector<T>(obj)
{
}

//******************************************
// findItem takes a parameter of type T    *
// and searches for it within the array.   *
//******************************************
template <class T>
int SearchableVector<T>::findItem(T item)
{
		int first = 0,
			last = this->size(),
			mid,
			pos = -1;
		bool found = false;

		while (!found && first <= last)
		{
			mid = (first + last)/2;
			if ((T)this->operator[](mid) == item)
			{
				found = true;
				pos = mid;
				return pos;
			}
			else if (this->operator[](mid) < item) first = mid + 1;
			else last = mid - 1;
		}
		if (pos = -1) cout << "ERROR: '" << item << "'"<< " not found" << endl;
		return pos;
	}
   

