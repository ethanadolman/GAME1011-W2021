#include "Classes.h" 

vector<Platform*> platform;
void PlatformBuilder(int p);
void GameBuilder(int p, int g);
void AchievementBuilder(int p, int g, int a);
void menu();

int main() {
	menu();
	return 0;
}

void PlatformBuilder(int p) {
	string name, manufacturer;
	int MAX_GAMES;
	cout << "Platform " << p + 1 << " Name:\n> ";
	cin.ignore();
	getline(cin, name);
	cout << "Platform " << p + 1 << " Manufacturer:\n> ";
	getline(cin, manufacturer);
	cout << "Amount of Games for Platform " << p + 1 << ":\n> ";
	cin >> MAX_GAMES;
	platform.push_back(new Platform(name, manufacturer, MAX_GAMES));
	platform.shrink_to_fit();
	system("cls");
	for (int g = 0; g < MAX_GAMES; g++) { GameBuilder(p, g); }
}

void GameBuilder(int p, int g) {
	string name, developer, publisher;
	int MAX_ACHIEVEMENTS;
	cout << "(" << platform[p]->GetName() << ")" << " Game " << g + 1 << " Name:\n> ";
	cin.ignore();
	getline(cin, name);
	cout << "(" << platform[p]->GetName() << ")" << " Game " << g + 1 << " Developer:\n> ";
	getline(cin, developer);
	cout << "(" << platform[p]->GetName() << ")" << " Game " << g + 1 << " Publisher:\n> ";
	getline(cin, publisher);
	cout << "(" << platform[p]->GetName() << ")" << " Amount of Achievements for Game " << g + 1 << ":\n> ";
	cin >> MAX_ACHIEVEMENTS;
	platform[p]->CreateGame(name, developer, publisher, MAX_ACHIEVEMENTS);
	system("cls");
	for (int a = 0; a < MAX_ACHIEVEMENTS; a++) { AchievementBuilder(p, g, a); }

}

void AchievementBuilder(int p, int g, int a) {
	string title, description;
	int pointvalue;
	cout << "(" << platform[p]->GetName() << ")" << " (" << platform[p]->GetGame(g)->GetName() << ")" << " Achievement " << a + 1 << " Title:\n> ";
	cin.ignore();
	getline(cin, title);
	cout << "(" << platform[p]->GetName() << ")" << " (" << platform[p]->GetGame(g)->GetName() << ")" << " Achievement " << a + 1 << " Description:\n> ";
	getline(cin, description);
	cout << "(" << platform[p]->GetName() << ")" << " (" << platform[p]->GetGame(g)->GetName() << ")" << " Achievement " << a + 1 << " Point Value:\n> ";
	cin >> pointvalue;
	system("cls");
	platform[p]->GetGame(g)->CreateAchievement(title, description, pointvalue);
}

void menu() {
	int choice, secondarychoice, tertiarychoice;
	do {
		system("cls");
		cout << "Please make a selection(1-5):\n";
		cout << "1. View All\n";
		cout << "2. Add Platform\n";
		cout << "3. Add Game\n";
		cout << "4. Add Achievement\n";
		cout << "5. Exit\n> ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			for (int p = 0; p < MAX_PLATFORMS; p++)
			{
				cout << platform[p]->GetInfo() << endl;
				for (int g = 0; g < platform[p]->GetMax(); g++)
				{
					cout << platform[p]->GetGame(g)->GetInfo() << endl;
					for (int a = 0; a < platform[p]->GetGame(g)->GetMax(); a++) { cout << platform[p]->GetGame(g)->GetAchievement(a)->GetInfo() << endl; }
				}
			}
			system("pause");
			break;
		case 2:
			PlatformBuilder(MAX_PLATFORMS++);
			break;
		case 3:
			cout << "Choose a Platform(1-" << MAX_PLATFORMS + 1 << "):" << endl;
			for (int p = 0; p < MAX_PLATFORMS; p++) { cout << p + 1 << ". " << platform[p]->GetName() << endl; }
			cout << MAX_PLATFORMS + 1 << ". Return to Menu" << endl;
			cin >> secondarychoice;
			if (secondarychoice == MAX_PLATFORMS + 1);
			else if (secondarychoice >= 1 && secondarychoice <= MAX_PLATFORMS) { GameBuilder(secondarychoice - 1, platform[secondarychoice - 1]->GetMax()); }
			break;
		case 4:
			cout << "Choose a Platform(1-" << MAX_PLATFORMS + 1 << "):" << endl;
			for (int p = 0; p < MAX_PLATFORMS; p++) { cout << p + 1 << ". " << platform[p]->GetName() << endl; }
			cout << MAX_PLATFORMS + 1 << ". Return to Menu" << endl;
			cin >> secondarychoice;
			if (secondarychoice == MAX_PLATFORMS + 1);
			else if (secondarychoice >= 1 && secondarychoice <= MAX_PLATFORMS) {
				system("cls");
				cout << "Choose a Game(1-" << platform[secondarychoice - 1]->GetMax() + 1 << "):" << endl;
				for (int g = 0; g < platform[secondarychoice - 1]->GetMax(); g++) { cout << g + 1 << ". " << platform[secondarychoice - 1]->GetGame(g)->GetName() << endl; }
				cout << platform[secondarychoice - 1]->GetMax() + 1 << ". Return to Menu" << endl;
				cin >> tertiarychoice;
				if (tertiarychoice == platform[secondarychoice - 1]->GetMax() + 1);
				else if (tertiarychoice >= 1 && tertiarychoice <= platform[secondarychoice - 1]->GetMax()) { AchievementBuilder(secondarychoice - 1, platform[secondarychoice - 1]->GetMax() - 1, platform[secondarychoice - 1]->GetGame(tertiarychoice - 1)->GetMax()); }
			}
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (choice != '5');
}