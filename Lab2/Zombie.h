#pragma once
#include "Character.h"
#include <iostream>

class Zombie : public Character
{

public:
	string GetName() const { return "uuuurrrggghh..."+ name + "...Brraaaiinnzz"; }
	float GetHealth() const { return health * 0.8f; }
	string GetSpcAtk() const { return "Grave Digger"; }
	void DisplayInfo() { cout  <<"Name: " << GetName() << "\nType: Zombie" << "\nHealth: " << GetHealth() << "\nSpecial Attack: " << GetSpcAtk() << *weapon; }
	~Zombie() {
		delete weapon;
	}
};