#pragma once
#include "Student.h"
class GamingStudent : public Student
{
protected:
	int device;
	int hours;
public:
	GamingStudent(string name, int age, string college, string program, int semester, int hours, int device) : Student(name, age, college, program, semester)
	{
		SetDevice(device);
		SetHours(hours);
	}
	void SetDevice(int d) { device = d; }
	void SetHours(int h) { hours = h; }

	int GetDevice() { return device; }
	int GetHours() { return hours; }
};


