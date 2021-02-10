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
	char choice2;
	const string firstname[40] = { "Liam","Noah","Oliver","William","Elijah","James","Benjamin","Lucas","Mason","Ethan","Alexander","Henry" ,"Jacob" ,"Michael" ,"Daniel" ,"Logan" ,"Jackson" ,"Sebastian" ,"Jack" ,"Aiden","Olivia","Emma","Ava","Sophia","Isabella","Charlotte","Amelia","Mia","Harper","Evelyn","Abigail","Emily","Ella","Elizabeth","Camila","Luna","Sofia","Avery","Mila","Aria" };
	const string lastname[40]{ "Smith","Johnson","Williams","Brown","Jones","Garcia","Miller","Davis","Rodriguez","Martinez","Hernandez" ,"Lopez" ,"Gonzalez" ,"Wilson" ,"Anderson" ,"Thomas" ,"Taylor" ,"Moore" ,"Jackson" ,"Martin","Lee","Perez","Thompson","White","Harris","Sanchez","Clark","Ramirez","Lewis","Robinson","Walker","Young","Allen","King","Wright","Scott","Torres","Nguyen","Hill","Flores" };
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
		if (option == 0)
		{
			NonGaming.push_back(new NonGamingStudent(firstname[rand() % 40] + " " + lastname[rand() % 40], rand() % 31 + 16, college[rand() % 3], program[rand() % 4], rand() % 12 + 1, rand() % 1000, rand() % 4));
			cout << i + 1 << ". " << NonGaming.back()->GetName() << endl;
		}
		else
		{
			Gaming.push_back(new GamingStudent(firstname[rand() % 40] + " " + lastname[rand() % 40], rand() % 31 + 16, college[rand() % 3], program[rand() % 4], rand() % 12 + 1, rand() % 1000, rand() % 4));
			cout << i + 1 << ". " << Gaming.back()->GetName() << endl;
		}
	}
	NonGaming.shrink_to_fit();
	Gaming.shrink_to_fit();

	Survey* survey = new Survey(NonGaming, Gaming);
	
	cout << "\nWould you like to process the results?(Y/N)\n>";
	cin >> choice2;
	
	system("cls");
	
	switch (choice2)
	{
	case 'y':
	case 'Y':
		cout << "Processing Results. ";
		system("pause");
		system("cls");
		break;
	case 'n':
	case 'N':
		return 0;
	}
	
	survey->Process();
}