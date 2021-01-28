#pragma once
#include <string>
#include "Weapon.h"
using namespace std;

class Character
{
protected:
	string name;
	float health;
	Weapon* weapon;
	
public:
	void SetName(string name) { this->name = name; }
	void SetHealth(float health) { this->health = health; };
	void SetWeapon(string name, string description, double damage, string special_ability1, string special_ability2)
	{ this->weapon = new Weapon(name, description, damage, special_ability1, special_ability2); }
	virtual void DisplayInfo(){};
	virtual ~Character(){};

	//Weapon weapon;
};

