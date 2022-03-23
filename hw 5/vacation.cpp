#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "functions.h"
#include "provided.h"
using std::cin, std::cout, std::endl, std::string;

int main() {
	int ngames, duration;
	cout << "Please enter the number of games and the duration: ";
	cin >> ngames;
	cin >> duration;
	if (ngames > 0 && ngames < 200 && duration > 0 && duration <=366) {
	cout << "Please enter name of file with titles: ";
	string fileName;
	string gameTitle[MAX_NB_GAMES];
	cin >> fileName;
	std::fstream fin;
	fin.open(fileName);
	cout << "Please enter name of file with preferences: ";
	string preffile;
	int prefs[MAX_NB_GAMES];
	cin >> preffile;
	cout << "Please enter name of file with plan: ";
	string planfile;
	cin >> planfile;
	int plan[366];
	if (!fin.is_open()) { 
        cout << "Invalid titles file.";
		return 0;
    } else {
	fin.close();
	}
	readGameTitles(fileName, ngames, gameTitle);
	readPrefs(preffile, ngames, prefs);
	readPlan(planfile, plan);
	int bestday = findBestVacation(duration, prefs, plan);
	cout << "Best start day is " << bestday << endl;
	cout << "Games to be played:" << endl;
	printGamesPlayedInVacation(bestday, duration, plan, gameTitle, ngames);
	} else {
		cout << "Invalid input.";
	}
	
	return 0;
}

