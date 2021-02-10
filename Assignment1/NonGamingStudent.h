#pragma once
#include "Student.h"
class NonGamingStudent : public Student
{
protected:
	int service;
	int hours;
public:
	NonGamingStudent(string name, int age, string college, string program, int semester, int hours, int service) : Student(name, age, college, program, semester)
	{
		SetService(service);
		SetHours(hours);
	}
	void SetService(int s) { service = s; }
	void SetHours(int h) { hours = h; }

	int GetService() { return service; }
	int GetHours() { return hours; }
};

