#include <iostream>
#include <stdexcept>
#include "picture_hanging.h"

#define TODO(X) cout << "[TODO] " << __FUNCTION__ << ": " << X << endl;

using std::cout;
using std::endl;
using std::ostream;
using std::out_of_range;

/*
make a copy of src (elements 0..len-1)
*/
int* copy(const int src[], const size_t len) 
{
    int* arr = new int[len];

    for (unsigned int i = 0; i < len; ++i)
    {
        arr[i] = src[i];
    }

    return arr;
}

/*
return i such that A[i] = key, or -1 if key is not in A
*/
int find(const int A[], const size_t len, const int key) 
{
    for (unsigned int i = 0; i < len; ++i)
    {
        if (A[i] == key)
            return i;
    }
    return -1;
}

/*
remove the specified number (cnt) of elements starting at specified index (idx)
*/
void remove(int A[], size_t& len, const size_t idx, const size_t cnt) 
{
	if (idx > len || cnt > len || len < idx+cnt) {
		throw std::out_of_range("Index or count is out of range.");
		return;
	}
	
	for (unsigned int i = 0; i < cnt; i++) {
		for (unsigned int l = idx; l < len-1; l++) {
			A[l] = A[l+1];
		}
	}
	len = len - cnt;
    //Thinking process
    //old: 1, 2, 3, 4, 5, 6, 7
    //New: 1, 5, 6, 7
}

/*
remove all instances of duplicate values in A (including opposites, so 1 and -1 are the same)
*/
void removeDuplicates(int A[], size_t& len) 
{	

for (unsigned int base = 0; base < 100; base++) {
	for (unsigned int i = base+1; i < len; i++) {
		if(A[base]==A[i] || A[base]==(A[i]*(-1))) {
			base = 0;
			if (i==len-1) {
				A[i] = 0;
				len--;
				
			}
			for (unsigned int l = i; l <= len; l++) {
			A[l] = A[l+1];
			}
			len--;
		}
	}
}
for (unsigned int c = 0; c < len; c++) {
	cout << A[c] << endl;
}

}

/*
returns true if str is not reducible (no canceling neighbors)
*/
bool isStable(const int A[], const size_t len) 
{
	if (len != 0) {
		for (unsigned int i = 0; i < len - 1; ++i)
		{
			if ((A[i] == A[i + 1]) ||(A[i] > A[i+1]))
				return false;
		}
	}
    return true;
}

/*
remove all instances of value
*/
void removeAll(int A[], size_t& len, const int value) 
{
  for (unsigned int l = 0; l <= len; l++) {
		if (A[l]==value) {
			for (unsigned int i = l; i <= len-1; i++) {
			A[i] = A[i+1];
			}
			l=0;
			len--;
		}
  }
	if (A[0]==value) {
		len = 0;
	}
 
}

/*
repeatedly remove any pair of neighbors which are opposites (e.g. 1 and -1).
*/
void reduce(int A[], size_t& len) 
{
    int a = 0;
	int b = 1;
	int paircount = 0;
	for (unsigned int l = 0; l <= len; l++) {
		if ((A[a]==(A[b]*(-1))) || (A[b]==(A[a]*(-1)))) {

			while (paircount < 2) {
				for (unsigned int i = a; i <= len-1; i++) {
					A[i] = A[i+1];
				}
				paircount++;
				len--;
			}
			
			a = -1;
			b = 0;
		}
		a+=1;
		b+=1;
	}
	
	if ( (len == 2) && ((A[0]==(A[1]*(-1))) || (A[1]==(A[0]*(-1))))) {
		len = 0;
	} 
    if (isStable(A, len) == false)
        reduce(A, len);
}

/*
return true if removing all instances of any value (and it's opposite, e.g. 1 and -1) causes the sequence to reduce to empty
*/
bool isCorrect(const int A[], const size_t len) 
{
    int arr[len];
    size_t newLength = len;

    for (unsigned int i = 0; i < len; ++i)
    {
        arr[i] = A[i];
    }
	removeDuplicates(arr,newLength);
	cout << newLength << endl;
    if (newLength == 0 || newLength == 1 || newLength == 2) {
        return true;
}
    return false;
}
