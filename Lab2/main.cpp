#include <iostream>
#include <vector>


#include "Character.h"
#include "Goblin.h"
#include "Orc.h"
#include "Zombie.h"

using namespace std;

int main()
{
	vector<Character*> character;
	int choice, secondarychoice;
	string name;
	float health;
	string description, special_ability1, special_ability2;
	double damage;
	do {
		system("cls");
		cout << "1. Create new Character\n";
		cout << "2. View all Characters\n";
		cout << "3. Delete a Character\n";
		cout << "4. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "1. Orc\n";
			cout << "2. Goblin\n";
			cout << "3. Zombie\n";
			cin >> secondarychoice;
			switch (secondarychoice)
			{
			case 1:
				character.push_back(new Orc());
				break;
			case 2:
				character.push_back(new Goblin());
				break;
			case 3:
				character.push_back(new Zombie());
				break;
			}
			character.shrink_to_fit();
			system("cls");
			cin.ignore();
			cout << "Name: ";
			getline(cin, name);
			character.back()->SetName(name);
			system("cls");
			cout << "Health: ";
			cin >> health;
			character.back()->SetHealth(health);
			system("cls");
			cin.ignore();
			cout << "Weapon Name: ";
			getline(cin, name);
			system("cls");
			cout << "Weapon Description: ";
			getline(cin, description);
			system("cls");
			cout << "Damage: ";
			cin >> damage;
			system("cls");
			cin.ignore();
			cout << "Special Ability 1: ";
			getline(cin, special_ability1);
			system("cls");
			cout << "Special Ability 2: ";
			getline(cin, special_ability2);
			character.back()->SetWeapon(name, description, damage, special_ability1, special_ability2);
			system("cls");
			break;
		case 2:
			system("cls");
			for (int i = 0; i < character.size(); i++)
			{
				cout << "-----Character(" << i+1 << ")-----\n";
				character[i]->DisplayInfo();
				cout << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			for (int i = 0; i < character.size(); i++)
			{
				character[i]->DisplayInfo();
				cout << "\n---------------\n1. Delete this Character\n";
				if (i != character.size() - 1) { cout << "2. Next Character\n"; }
				else { cout << "2. Return to menu\n"; }
				cin >> secondarychoice;
				switch(secondarychoice)
				{
				case 1:
					character.erase(character.begin() + i);
					character.shrink_to_fit();
					break;
				case 2:
					break;
				}
				system("cls");
			}
			break;
		case 4:
			system("cls");
			return 0;
			break;

		}
	} while (choice != 4);
	return 0;
}