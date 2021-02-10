#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "NonGamingStudent.h"
#include "GamingStudent.h"

using namespace std;

class Survey
{
private:
	vector<NonGamingStudent*> NonGaming;
	vector<GamingStudent*> Gaming;
public:
	Survey(vector<NonGamingStudent*> NGS, vector<GamingStudent*> GS)
	{
		NonGaming = NGS;
		Gaming = GS;
	}
	void Process();
};

