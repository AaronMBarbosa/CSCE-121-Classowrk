#ifndef STACKDOUBLE_H_
#define STACKDOUBLE_H_

class StackDouble
{
private:
	int capacity;
	int length;
	double* A;

public:
	StackDouble(); //Constructor

	~StackDouble(); //Destructor

	void push(double);

	double pop();

};



#endif / STACKDOUBLE_H_ /
