#include <iostream>
#include "StackDouble.h"


StackDouble::StackDouble() //Constructor
{
	A = new double[1];
	capacity = 1;
	length = 0;
}
StackDouble::~StackDouble() //Destructor
{
	delete A;
}
void StackDouble::push(double element)
{
	if (capacity == length)
	{
		capacity *=2;
		double *B = new double[capacity];
		for (int i = 0; i < capacity; ++i)
		{
				B[i] = A[i];
		}
	}
	A[length] = element;
	length++;

}
double StackDouble::pop()
{
	double element = 0.0;
	if(capacity == 0)
	{
		return 0;
	}
	element = A[length - 1];
	--length;
	return element;
}


