#pragma once
#include "Character.h"
#include <iostream>

class Goblin : public Character
{

public:
	string GetName() const { return "$$$" + name + "$$$"; }
	float GetHealth() const { return health * 0.5f; }
	string GetSpcAtk() const { return "Coin Flip"; }
	void DisplayInfo() { cout << "Name: " << GetName() << "\nType: Goblin" << "\nHealth: " << GetHealth() << "\nSpecial Attack: " << GetSpcAtk() << *weapon; }
	~Goblin() {
		delete weapon;
	}
};