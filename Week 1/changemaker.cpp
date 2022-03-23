#include <iostream>
int main() {
    int cents = 0;
	int dollar = 0;
	int cointot = 0;
	int quarters = 0;
	int pennies = 0;
	int nickels = 0;
	int dimes = 0;
	int trunk = 0;
	
	
	std::cout << "Enter dollars: ";
	std::cin >> dollar;
	std::cout << "Enter cents: ";
	std::cin >> cents;
	
	if (dollar > 0) {
		quarters = 4 * dollar;
		
	}
	if ((cents / 25) >= 0) {
		trunk = cents/25;
		quarters+= trunk;
		cents = cents - (25 * trunk);
		trunk = 0;
	}
	if ((cents / 10) >= 0) {
		trunk = cents/10;
		dimes+= trunk;
		cents -= 10 * trunk;
		trunk = 0;
	}
	if ((cents / 5) >= 0) {
		trunk = cents/5;
		nickels+= trunk;
		cents -= 5 * trunk;
		trunk = 0;
	}
	if ((cents / 1) >= 0) {
		trunk = cents/1;
		pennies+= trunk;
		cents -= 1 * trunk;
		trunk = 0;
	}

	
	cointot = cointot + quarters + dimes + nickels + pennies;
	std::cout << "Pennies: " << pennies << std::endl;
	std::cout << "Nickels: " << nickels << std::endl;
	std::cout << "Dimes: " << dimes << std::endl;
	std::cout << "Quarters: " << quarters << std::endl;
	
	std::cout << "Total coins used: " << cointot << std::endl;
	
    return 0;
}