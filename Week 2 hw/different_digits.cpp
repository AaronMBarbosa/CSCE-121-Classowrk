#include <iostream> 
using std::cin, std::cout, std::endl, std::string;


string reverse(string test) {
	string reverse = "";
	while (test.empty()!= true) {
		reverse += test.back();
		test.pop_back();
	}
	return reverse;
	}

	bool is_palindrome(string wow) {
		
		string palintest = reverse(wow);
		if (palintest == wow) {
			return true;
		}
		return false;
	}
	
	string min(string one, string two) {
		
		if (one > two) {
			return two;
		} else {
			return one;
		}
	}
	
	string max(string one, string two) {
		
		if (one < two) {
			return two;
		} else {
			return one;
		}
	}
	
int main() {
	
	cout << "Enter a string to reverse: ";
	string test;
	cin >> test;
	string revstring = reverse(test);
	cout << revstring << endl;
	
	cout << "Enter a string to see if its a palindrome: ";
	cin >> test;
	if (is_palindrome(test) == 1) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
	
	string one;
	string two;
	
	cout << "Enter a string to compare: ";
	cin >> one;
	cout << "Enter a string to compare: ";
	cin >> two;
	
	cout << max(one,two) << "is the max";
	cout << min(one two)<< "is the min";
	
	
return 0;
}