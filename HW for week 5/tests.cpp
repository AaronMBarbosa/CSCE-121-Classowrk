/*
Example code for local unit-testing of HW 4
*/

#include <iostream>
#include <string>
#include "dada.h"
#include "test_helper.h"

using std::cout;
using std::endl;
using std::string;

bool test_amax() {
    bool pass = true;
    
    // each testcase goes in {...} to contain scope
    {
        // the testcase is just for display purposes
        string testcase = "amax ; 8 6 7 -5 3 0 9 , 7 ; 6";
        double x[] = {8, 6, 7, -5, 3, 0, 9};
        unsigned int len = 7;
        int expected = 6;
        int actual = amax(x, len);
        
        // abuse of &=, only safe because both args are bool
        // the 3rd arg is the message to print if the test fails
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }
    
    {
        string testcase = "amax ; -4 -5 -3 -2 -1 0 1 2, 8 ; 0";
        double x[] = {-4, -5, -3, -2, -1, 0, 1, 2};
        unsigned int len = 8;
        int expected = 1;
        int actual = amax(x, len);
        
        // abuse of &=, only safe because both args are bool
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }

    return pass;
}

bool test_swap() {
    bool pass = true;
    
    {
        string testcase = "axpy ; 1 2 3 , 4 5 6 , 3 ; 4 5 6 , 1 2 3";
        double x[] = {1, 2, 3};
        double y[] = {4, 5, 6};
        unsigned int len = 3;
        double expected[3] = {4, 5,6};
        swap(x, y, len);
        double* actual = y;
        
        // abuse of &=, only safe because both args are bool
        // note the new 3rd arg is the length of the arrays
        // the 4th arg is now the message to print on failure
        pass &= EXPECT_EQ(actual, expected, len, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }
    
    return pass;
}

int main() {
    int failing = 0;
    // add 1 to failing if function returns false
    failing += test_amax() ? 0 : 1;
    
    failing += test_swap() ? 0 : 1;
    
    if (!failing) {
        cout << "ALL TESTS PASSING" << endl;
    } else {
        cout << endl << "Failing: " << failing << endl;
    }
    
    return 0;
}
