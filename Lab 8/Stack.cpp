#include <iostream>
#include <string>
#include <cmath>
#include "Stack.h"


// add element to the top of Stack s
// if Stack s is full, resize the underlying array
void push(Stack& s, double element){
	if (s.length==s.capacity) {
		s.capacity++;
	}
	s.A[s.length]=element;
	s.length++;
}

// remove and return the element on top of Stack s
// if Stack s is empty, return NAN
double pop(Stack& s) {
	if (s.length==0) {
		return NAN;
	}
double ret = s.A[s.length-1];
s.length--;
return ret;
}

