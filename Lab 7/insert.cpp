
#include <iostream>
using namespace std;

int remove(int array[], size_t& len, size_t capacity, const size_t idx) {
	
	if (len > capacity) {
		throw invalid_argument("len > capacity");
	}
	if (idx >= len) {
		throw out_of_range("idx >= len");
	}
	int value = array[idx];
	
	for(size_t i = idx; i < len - 1; i++) {
		array[i]= array[i+1];
	}
	
	--len;
	
	return value;
}


void insert(int array[], size_t& len, size_t capacity, const int element, const size_t idx) {
	// input validation
	if (len >= capacity) {
		throw invalid_argument("len >= capacity");
	}
	if (idx > len) {
		throw out_of_range("idx > len");
	}
	// make space !!
	for (size_t i = len-1; i >= idx; i--) {
		array[i+1]=array[i];
		
	}
	array[idx] = element;
	len = len+1;
}

int main() {
	int arraya[]={8,6,7,5};
	size_t len = 4;
	size_t capacity = 7;
	insert(arraya, len, capacity, 3, 2);
}