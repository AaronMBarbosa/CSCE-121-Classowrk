#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "functions.h"

using std::ifstream;
using std::string;
using std::cout, std::endl;
using std::runtime_error;

void readPrefs(string fileName, int ngames, int prefs[]) {
	ifstream fin(fileName);
    if (!fin.is_open()) {  // error in opening the file
        throw runtime_error("Invalid preferece file.");
    }
	for (int i = 0; i < ngames; i++) {
        prefs[i] = 0;
    }
	int validlines = 0;
	int gameIDs, rating;
	while (!fin.eof()) {
		fin >> gameIDs >> rating;
		if(fin.fail()) {
			fin.clear();
			fin.ignore('\n');
		} else {
			if(gameIDs >= 0 && gameIDs < ngames && rating >= 0 && rating <=5) {
				validlines++;
				prefs[gameIDs] = rating;
			}
		}
	}
}

void readPlan(string fileName, int plan[]) {
	ifstream fin(fileName);
	if (!fin.is_open()) {  // error in opening the file
        throw runtime_error("Invalid plan file.");
    }
	for (int i = 0; i < 366; i++) {
        plan[i] = 0;
    }
	int planing = 0;
	int pos = 0;
	while (!fin.eof()) {
		fin >> pos >> planing;
		plan[pos]= planing;
	}
}

int computeFunLevel(int start, int duration, int prefs[], int plan[]) {
	if (start+duration-1 > 365) {
		throw std::invalid_argument(
		"The duration exceeds the number of days remaining in the year.");
	}
	int funlvl = 0;
	for (int i = start; i < start+duration; i++) {
		funlvl+=prefs[plan[i]];
	}
	return funlvl;
}

int findBestVacation(int duration, int prefs[], int plan[]) {
	int csd = 1;
	int bsd = 0;
	int sum = 0;
	int bestsum = 0;
	if (duration >= 366) {
		throw std::invalid_argument(
		"The duration is too long.");
	}
	while((csd+duration-1) < 366) {
		sum = computeFunLevel(csd, duration, prefs, plan);
		if (sum > bestsum) {
			bestsum = sum;
			bsd = csd;
		}
		csd++;
	}
	return bsd;
}
