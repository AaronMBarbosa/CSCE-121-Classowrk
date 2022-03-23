#include "functions.h" 
#include <iostream>
#include <cmath>
using namespace std;

bool validForces(const double *forces, unsigned const int noParticipants) {
		for (int i = 0; i < noParticipants; ++i) {
			if (forces[i] < 0) {
				return false;
        }
    }
					return true;
	}
void readForceValuesFromStdIn(double* leftTeam, double* rightTeam, unsigned const int noParticipants) {
	
	for (int i = 0; i < noParticipants; i++) {
		cin >> leftTeam[i];
		cin >> rightTeam[i];
	}		
	
}
double calculateForce(const double* leftTeam, const double* rightTeam, unsigned const int noParticipants) {
	double NetForce = 0;
	double a;
	double b;
	// left is positive right is negative
	for (int i = 0; i < noParticipants; i++) {
		a = leftTeam[i];
		b = rightTeam[i];
		NetForce += a - b;
		
	}
	return NetForce;
}
void printWinnerToStdOut(const char* leftTeamName, const char* rightTeamName, const double netForce)  {
	if (netForce < -5) {
	cout << rightTeamName << " wins!" << endl;
	}		
	else if (netForce > 5) {
		cout << leftTeamName << " wins!" << endl;
	} else {
		cout << "Tie." << endl;
	}
}



