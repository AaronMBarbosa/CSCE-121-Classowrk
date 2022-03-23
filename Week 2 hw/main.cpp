#include <iostream>
#include "number_peeling.h"
using std::cout, std::endl;

int main() {
	
	int number = 8675309;
	int num_digits=count_digits(number);
	cout << number << " has " << num_digits << " digits " << endl;
	
	for (int i =0; i < num_digits; ++i) {
		
		cout << number << "[" <<i<<"]= " << get_digit(number, i) << endl;
	
	}
		
	int number_R = reverse_number(number);
	cout << number << "^R =" << number_R << endl;
	
	if (is_palindrome(number)) {
		cout << number << " is a palindrome." << endl;
	} else {
		cout << number << " is NOT a palindrome."" << endl;
		
	}
	
	
	
	
	
	
	
	
}