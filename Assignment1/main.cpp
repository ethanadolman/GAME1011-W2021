#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

#include "NonGamingStudent.h"
#include "GamingStudent.h"
#include "Survey.h"

using namespace std;

int main()
{
	vector<NonGamingStudent*> NonGaming;
	vector<GamingStudent*> Gaming;
	int choice;
	const string name[10][2] = { {"Liam","Smith"},{"Noah","Johnson"},{"Oliver","Williams"},{"William","Brown"},{"Elijah","Jones"},{"James","Garcia"},{"Benjamin","Miller"},{"Lucas","Davis"},{"Mason","Rodriguez"},{"Ethan","Martinez"} };
	const string college[3] = { "Humber","George Brown","Seneca" };
	const string program[4] = { "Arts","Buisness/Finance","Computer Science","Engineering" };
	const enum service { NETFLIX, CRAVE, DISNEY_PLUS, HULU };
	const enum device { COMPUTER, CONSOLE, PHONE, TABLET };

	cout << "Welcome to the Survey Generator" << endl;
	do {
		cout << "Input Amount of Participants(1-500):\n> ";
		cin >> choice;
		system("cls");
	} while (choice > 500 || choice < 1);
	srand(time(NULL));
	for (int i = 0; i < choice; i++)
	{
		int option = rand() % 2;
		if (option == 0) { NonGaming.push_back(new NonGamingStudent(name[rand() % 10][0] + " " + name[rand() % 10][1], rand() % 31 + 16, college[rand() % 3], program[rand() % 4], rand() % 12 + 1, rand() % 1000, rand() % 4)); }
		else { Gaming.push_back(new GamingStudent(name[rand() % 10][0] + " " + name[rand() % 10][1], rand() % 31 + 16, college[rand() % 3], program[rand() % 4], rand() % 12 + 1, rand() % 1000, rand() % 4)); }
	}
	NonGaming.shrink_to_fit();
	Gaming.shrink_to_fit();

	Survey* survey = new Survey(NonGaming, Gaming);
	survey->Process();
}