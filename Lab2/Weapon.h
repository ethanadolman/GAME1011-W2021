#pragma once
#include <string>
#include <iostream>
using namespace std;

class Weapon
{
private:
	string name, description, special_abilities[2];
	double damage;
public:
	Weapon(string name, string description, double damage, string special_ability1, string special_ability2)
	{
		this->name = name;
		this->description = description;
		this->damage = damage;
		this->special_abilities[0] = special_ability1;
		this->special_abilities[1] = special_ability2;
	}
	string GetName() { return name; };
	string GetDescription() { return description; };
	double GetDamage() { return damage; };
	string GetSpecialAbility(int i) { return special_abilities[i]; };
	friend ostream& operator<<(ostream& out, Weapon w);

};

