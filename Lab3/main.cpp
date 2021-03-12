#include "searchvect.h"
#include "SimpleVector.h"
#include "SortableVector.h"

int main()
{
	cout << "creating a int table of 2 elements" << endl;
	SearchableVector<int> IntTable(5);
	IntTable.print();
	cout << "Attempting to pushback 75 into full array" << endl;
	IntTable.push_back(75);
	cout << "popping back before pushing 77 into array" << endl;
	IntTable.pop_back();
	IntTable.push_back(77);
	IntTable.print();
	cout << "popping back to remove 77 from the array" << endl;
	IntTable.pop_back();
	IntTable.print();
	cout << "popping back several times and then pushing several different numbers into array" << endl;
	IntTable.pop_back();
	IntTable.pop_back();
	IntTable.pop_back();
	IntTable.pop_back();
	IntTable.push_back(717);
	IntTable.push_back(1211);
	IntTable.push_back(34541);
	IntTable.push_back(2123121);
	IntTable.push_back(241789311);
	IntTable.print();
	cout << "finding the location of 75" << endl;
	IntTable.findItem(75);
	cout << "finding the location of 34541" << endl;
	cout << IntTable.findItem(34541) << endl;

	cout << "creating a char table of 8 elements" << endl;
	SortableVector<char> CharTable(8);
	CharTable.print();
	cout << "Attempting to pushback 'B' into full array" << endl;
	CharTable.push_back('B');
	cout << "popping back before pushing 'a' into array" << endl;
	CharTable.pop_back();
	CharTable.push_back('a');
	CharTable.print();
	cout << "popping back to remove 'a' from the array" << endl;
	CharTable.pop_back();
	CharTable.print();
	cout << "popping back several times and then pushing several different Chars into array" << endl;
	CharTable.pop_back();
	CharTable.pop_back();
	CharTable.pop_back();
	CharTable.pop_back();
	CharTable.push_back('j');
	CharTable.push_back('c');
	CharTable.push_back('r');
	CharTable.push_back('Q');
	CharTable.push_back('t');
	CharTable.print();
	return 0;
}