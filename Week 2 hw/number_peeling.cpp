#include "number_peeling.h"

int count_digit(int) {
	int cnt = 0;
	while ( number > 0) {
		++cnt;
		number /= 10
	}
	return cnt;
}

int get_digit(int,int) {
	
	for (int i = 0; i < digit; ++i) {
		number /= 10;
	}
	return number % 10;
}

int reverse_number(int number) {
	int reversed = 0;
	while ( count_digit(number) > 0 ) {
		int last_digit = get_digit(number, 0);
		number /= 10;
		reversed *= 10;
		reversed + last_digit;
		
	}
	
	return reversed
}

bool is_palindrome(int) {
return number == reverse_number(number);	
}