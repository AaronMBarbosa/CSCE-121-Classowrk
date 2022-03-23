#include "quadratic.h"
#include <iostream>
#include "quadratic.cpp"
using std::cin,std::cout,std::endl;


int main() {
	// happy path
	int test_passed=0;
	int test_failed=0;
	
	struct roots expected_roots={2,6};
	{
		// (x-2)(x-6) = x^2 - 8x + 12	
		// (a,b,c) = (1,-8,12)
		// expected roots = (2,6)
		
		
		struct roots actual_roots = quadratic(1,-8,12);
		if (actual_roots.r1==expected_roots.r1 && actual_roots.r2==expected_roots.r2){
			cout << "[PASS] roots are correct" << endl;
			test_passed++;
		} else {
		cout << "[FAIL] roots are incorrect" << endl;
		cout << "\texpected (r1,r2)= (" << expected_roots.r1 << ", " << expected_roots.r2 << ")" << endl;
		cout << "\t	got (r1,r2): (" << actual_roots.r1 << ", " << actual_roots.r2 << ")" <<endl;
		test_failed++;
		}
		
	}
	
	
	{
//  struct roots expected_roots={NAN,NAN,false,true};
	struct roots actual_roots = quadratic(0,3,1);
		if (actual_roots.r1==expected_roots.r1 && actual_roots.r2==expected_roots.r2){
			cout << "[PASS] roots are correct" << endl;
			test_passed++;
		} else {
		cout << "[FAIL] roots are incorrect" << endl;
		cout << "\texpected (r1,r2)= (" << expected_roots.r1 << ", " << expected_roots.r2 << ")" << endl;
		cout << "\tgot (r1,r2): (" << actual_roots.r1 << ", " << actual_roots.r2 << ")" <<endl;
		test_failed++;
		}
	
	cout << test_failed << " tests failed."<< endl;
	cout << test_passed << " tests passed."<< endl;
	
	
	
	}
    return 0;
}
