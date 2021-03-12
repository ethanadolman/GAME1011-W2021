#pragma once
#include "SimpleVector.h"
template <class T>
class SortableVector : public SimpleVector<T>
{
public:
	// Constructor.
	SortableVector(int s) : SimpleVector<T>(s)
	{ }
	// Copy constructor.		
	SortableVector(const SortableVector&);
	// Additional constructor. 
	SortableVector(const SimpleVector<T>& obj) :
		SimpleVector<T>(obj) { }
	void sort();
};


//******************************************
// Definition of the copy constructor.     *
//******************************************
template <class T>
SortableVector<T>::
SortableVector(const SortableVector& obj) :
	SimpleVector<T>(obj)
{
}

//******************************************
// Sort Orginizes the values of the array  *
// in ascending order					   *
//******************************************
template <class T>
void SortableVector<T>::sort() {
	bool swapping;
	do {
		swapping = false;
		for (int j = 0; j < this->size()-1; j++)
		{
			if (this->operator[](j) > this->operator[](j+1)) {
				swap(this->operator[](j), this->operator[](j+1));
				swapping = true;
			}
		}
	} while (swapping);
}
