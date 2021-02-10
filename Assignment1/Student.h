#pragma once
#include "Person.h"
class Student : public Person
{
protected:
	string college, program;
	int semester;
public:
	Student(string name, int age, string college, string program, int semester) : Person(name, age)
	{
		SetCollege(college);
		SetProgram(program);
		SetSemester(semester);
	}
	void SetCollege(string c) { college = c; }
	void SetProgram(string p) { program = p; }
	void SetSemester(int s) { semester = s; }

	string GetCollege() { return college; }
	string GetProgram() { return program; }
	int GetSemester() { return semester; }

	string GetName() { return name; }
	int GetAge() { return age; }
};

