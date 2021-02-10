#pragma once
#include <string>

using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	Person(string name, int age)
	{
		SetName(name);
		SetAge(age);
	}

	void SetName(string n) { name = n; }
	void SetAge(int a) { age = a; }
};

