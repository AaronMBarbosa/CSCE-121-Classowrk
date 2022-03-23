#include <iostream>
#include "number_peeling.h"
using std::cout, std::endl, std::cin;

int main() {
	
	int userNum=0;
	cout << "Enter n>=0: ";
	cin >> userNum;
	int i;
	long factorial = userNum;
	for (i=0 ; i < userNum; ++i) {
		factorial/=i;
	}
	cout << "The number is " << factorial <<"! The largest prime factor is."; 
	
	
}