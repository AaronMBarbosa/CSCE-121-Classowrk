
#include <iostream>
using std::cin,std::cout,std::endl;


int main() {
int i;
int lowestvalue;
cin >> i;
lowestvalue=i;
if (lowestvalue==0) {
		cout << "empty"<< endl;
		exit(0); 
	}
else {
	while (i>0) {
	if (i < lowestvalue) {
		lowestvalue=i;
	}
		cin >> i;

	
}
}

cout << lowestvalue << endl;

    return 0;
}
