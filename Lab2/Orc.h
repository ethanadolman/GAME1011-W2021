#pragma once
#include "Character.h"
#include <iostream>

class Orc : public Character
{

public:
	string GetName() const { return name + " The Orc"; }
	float GetHealth() const { return health * 1.5f; }
	string GetSpcAtk() const { return "Ground Pound"; }
	void DisplayInfo() { cout << "Name: " << GetName() << "\nType: Orc" << "\nHealth: " << GetHealth() << "\nSpecial Attack: " << GetSpcAtk() << *weapon; }
	~Orc(){
		delete weapon;
	}
};

