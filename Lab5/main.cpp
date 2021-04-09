#include <iostream>
#include "DynTempStack.h"
#include "DynTempQueue.h"
#include <string>
using namespace std;

struct Rectangle {
	int x, y;
	Rectangle(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};


struct Person {
	string first, last;
	Person(string first, string last)
	{
		this->first = first;
		this->last = last;
	}
};

int main()
{
	char RemovedChar;
	DynTempQueue<char> CharQueue;
	CharQueue.enqueue('a');
	CharQueue.enqueue('b');
	CharQueue.enqueue('c');
	CharQueue.dequeue(RemovedChar);
	cout << RemovedChar << endl;
	CharQueue.enqueue('d');
	CharQueue.enqueue('e');
	CharQueue.dequeue(RemovedChar);
	cout << RemovedChar << endl;
	CharQueue.dequeue(RemovedChar);
	cout << RemovedChar << endl;
	CharQueue.clear();
	//CharQueue.dequeue(RemovedChar);

	Rectangle* RemovedRectangle;
	DynTempQueue<Rectangle*> RectangleQueue;
	RectangleQueue.enqueue(new Rectangle(5,5));
	RectangleQueue.enqueue(new Rectangle(10,4));
	RectangleQueue.enqueue(new Rectangle(8,6));
	RectangleQueue.dequeue(RemovedRectangle);
	cout << "("<< RemovedRectangle->x << ", " << RemovedRectangle->y << ")" << endl;
	RectangleQueue.enqueue(new Rectangle(2,6));
	RectangleQueue.enqueue(new Rectangle(2,4));
	RectangleQueue.dequeue(RemovedRectangle);
	cout << "(" << RemovedRectangle->x << ", " << RemovedRectangle->y << ")" << endl;
	RectangleQueue.dequeue(RemovedRectangle);
	cout << "(" << RemovedRectangle->x << ", " << RemovedRectangle->y << ")" << endl;
	RectangleQueue.clear();
	//RectangleQueue.dequeue(RemovedRectangle);

	cout << endl;

	float RemovedFloat;
	DynTempStack<float> FloatStack;
	//FloatStack.pop(RemovedFloat);
	FloatStack.push(6.3f);
	FloatStack.push(18.234f);
	FloatStack.push(8.23f);
	FloatStack.pop(RemovedFloat);
	cout << RemovedFloat << endl;
	FloatStack.push(10.95f);
	FloatStack.push(7.0f);
	FloatStack.pop(RemovedFloat);
	cout << RemovedFloat << endl;
	FloatStack.pop(RemovedFloat);
	cout << RemovedFloat << endl;


	Person* RemovedPerson;
	DynTempStack<Person*> PersonStack;
	//PersonStack.pop(RemovedPerson);
	PersonStack.push(new Person("Ethan","Dolman"));
	PersonStack.push(new Person("John", "Doe"));
	PersonStack.push(new Person("Bob", "Smith"));
	PersonStack.pop(RemovedPerson);
	cout << "(" << RemovedPerson->first << ", " << RemovedPerson->last << ")" << endl;
	PersonStack.push(new Person("Jack", "Miller"));
	PersonStack.push(new Person("Bill", "Johnson"));
	PersonStack.pop(RemovedPerson);
	cout << "(" << RemovedPerson->first << ", " << RemovedPerson->last << ")" << endl;
	PersonStack.pop(RemovedPerson);
	cout << "(" << RemovedPerson->first << ", " << RemovedPerson->last << ")" << endl;
	return 0;
}