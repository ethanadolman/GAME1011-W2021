#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int MAX_PLATFORMS;

class Achievement {
private:
	string title, description;
	int pointvalue;
public:
	Achievement(string title, string description, int pointvalue) {
		this->title = title;
		this->description = description;
		this->pointvalue = pointvalue;
	}
	string GetTitle() { return title; }
	string GetDescription() { return description; }
	int GetPointvalue() { return pointvalue; }
	string GetInfo() { return "--------------------\nTitle: " + GetTitle() + "\nDescription: " + GetDescription() + "\nPoint Value: " + to_string(GetPointvalue()); }
};

class Game {
private:
	string name, publisher, developer;
	vector<Achievement*> achievement;
	int MAX_ACHIEVEMENTS;
public:
	Game(string name, string developer, string publisher, int MAX_ACHIEVEMENTS) {
		this->name = name;
		this->developer = developer;
		this->publisher = publisher;
		this->MAX_ACHIEVEMENTS = MAX_ACHIEVEMENTS;
	}
	void CreateAchievement(string title, string description, int pointvalue)
	{
		achievement.push_back(new Achievement(title, description, pointvalue));
		achievement.shrink_to_fit();
		if ((int)achievement.size() > MAX_ACHIEVEMENTS) { MAX_ACHIEVEMENTS = (int)achievement.size(); }
	}
	string GetName() { return name; }
	string GetDeveloper() { return developer; }
	string GetPublisher() { return publisher; }
	int GetMax() { return MAX_ACHIEVEMENTS; }
	string GetInfo() { return "--------------------\nName: " + GetName() + "\nDeveloper: " + GetDeveloper() + "\nPublisher: " + GetPublisher() + "\nAchievements: " + to_string(GetMax()); }
	Achievement* GetAchievement(int i) { return achievement[i]; }
};


class Platform {
private:
	string name, manufacturer;
	vector<Game*> game;
	int MAX_GAMES;

public:
	Platform(string name, string manufacturer, int MAX_GAMES) {
		this->name = name;
		this->manufacturer = manufacturer;
		this->MAX_GAMES = MAX_GAMES;
	}
	void CreateGame(string name, string developer, string publisher, int MAX_ACHIEVEMENTS) {
		game.push_back(new Game(name, developer, publisher, MAX_ACHIEVEMENTS));
		game.shrink_to_fit();
		if ((int)game.size() > MAX_GAMES) { MAX_GAMES = (int)game.size(); }
	}
	string GetName() { return name; }
	string GetManufacturer() { return manufacturer; }
	int GetMax() { return MAX_GAMES; }
	string GetInfo() { return "--------------------\nName: " + GetName() + "\nManufacturer: " + GetManufacturer() + "\nGames: " + to_string(GetMax()); }

	Game* GetGame(int i) { return game[i]; }
	//Game* GetGame(string name) { for (int i = 0; i < MAX_GAMES; i++) { if (game[i]->GetName() == name) { return game[i]; } } }
};


