#include <iostream>
#include "picture_hanging.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
	
	int length = 0;
	cin >> length;
	if (cin.fail() || length <=0) {
	cout << "invalid input"<<endl;
	return 1;
	}
	int* A = new int[length];
	int checker=0;
	for (int i = 0; i < length; i++) {
		cin >> checker;
		if (cin.fail() || length <=0) {
			cout << "invalid input"<<endl;
			return 1;
		} else {
			A[i]=checker;
		}
		
	}
	return 0;
}