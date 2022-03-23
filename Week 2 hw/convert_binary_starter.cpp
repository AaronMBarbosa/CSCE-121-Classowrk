#include <iostream>
#include <string>
#include <math.h>
using namespace std; 

namespace {
    int tests_passed = 0;
    int tests_failed = 0;
}

template<typename T>
void assert_eq(T expected, T actual, int line_number) {
    if (actual == expected) {
        cout << "[PASS] ";
        ++tests_passed;
    } else {
        cout << "[FAIL] ";
        ++tests_failed;
    }
    cout << "test at line: " << line_number << endl;
    cout << "\texpected: " << expected << endl;
    cout << "\t  actual: " << actual << endl;
}

int bin2dec(string bits) {
	int decimal=0;
	for (int i = bits.length()-1; i >= 0; --i) {
		if ((bits.at(i) == '1') && (i==bits.length()-1)) {
			decimal+=1;
			cout << "decimal after spot " << i << " is " << decimal << endl;
			
		}
		if ((bits.at(i)== '1') && (i!=0)) {
			int temp = pow(2,bits.length() - i);
			decimal+=temp;
			cout << "decimal after spot " << i << " is " << decimal << endl;
		}
	}
	cout << "decimal is " << decimal;
	
	return decimal;
}



int main() {
    {
        string bits = "1101";
        int expected = 13;
        int actual = bin2dec(bits);
        assert_eq(expected, actual, __LINE__);
    }

   /* {
        int number = 20;
        string expected = "10100";
        string actual = dec2bin(number);
        assert_eq(expected, actual, __LINE__);
    }*/

    cout << "DONE" << endl;

    cout << tests_passed << " tests passed." << endl;
    cout << tests_failed << " tests failed." << endl;
} 