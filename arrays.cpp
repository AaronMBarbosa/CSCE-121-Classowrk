#include <iostream>

using std::cout;
using std::endl;
void array_func(char array[],size_t len) {
	for (size_t i=0;i<len;i++) {
		cout << "array["<<i<<"] = " << array[i] << " (" << static_cast<unsigned  int>(array[i]) << ") " << endl;
	
	}
	array[len-1]='Y'; // ok
	array[len] = 'X'; // not ok
}

int main() {
	char canary[]= "canary";
	char array[1];
	for (int i=-10;i<10;i++) {
		cout << "array["<<i<<"] = " << array[i] << " (" << static_cast<unsigned  int>(array[i]) << ") " << endl;
	
	}
	
	cout << "---------" << endl;
	array_func(canary,6);
	
	cout << "---------" << endl;
	array_func(canary,10);
}