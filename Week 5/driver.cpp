#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	

    int noParticipants = 0;
  
	cin >> noParticipants;
	
    //TODO: deine an array for the name of the left team, and then read it from terminal
	string lteamname;
	cin >> lteamname;
	char leftTeamName[lteamname.length()];
	for (int x =0; x < lteamname.length(); x++) {
		leftTeamName[x]=lteamname.at(x);
	}
	
    //TODO: deine an array for the name of the right team, and then read it from terminal
	string rteamname;
	cin >> rteamname;
	char rightTeamName[rteamname.length()];
	for (int x =0; x < rteamname.length(); x++) {
		rightTeamName[x]=rteamname.at(x);
	}
    //TODO: deine an array for the forces of the left team (variable name is leftTeamForces)
    double leftTeamForces[noParticipants];
	
	
    //TODO: deine an array for the forces of the right team (variable name is rightTeamForces)
    double rightTeamForces[noParticipants];
	
	
    //read them from the terminal by calling function readForceValuesFromStdIn
    readForceValuesFromStdIn(leftTeamForces, rightTeamForces, noParticipants);

    //TODO: check whether the inputs are valid
   bool a = validForces(leftTeamForces, noParticipants);
	
   bool b = validForces(rightTeamForces, noParticipants);
   
   if ((a == false)&&(b==false)){
	   cout << "Both teams forces are invalid." << endl;
	   exit(0);
   }
   else if ((b==false)&&(a==true)){
		cout << "The right team is using invalide force" << endl;
   } else if ((b==true)&&(a==false)){
		cout << "The left team is using invalide force" << endl;
   }
    //compute the netforce
    double netForce = calculateForce(leftTeamForces, rightTeamForces, noParticipants);
    
    //print the result
    printWinnerToStdOut(leftTeamName, rightTeamName, netForce);


    return 0;
}
