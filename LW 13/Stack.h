#ifndef STACK_H_
#define STACK_H_

template <class T>
class Stack
{
private:
	int capacity;
	int length;
	T* A;

public:
	Stack() //Constructor
	{
		A = new T[1];
		capacity = 1;
		length = 0;
	} //Constructor

	~Stack() //Destructor
	{
		delete[] A;
	}

	void push(T element)
	{
		if (capacity == length)
		{
			capacity *=2;
			T *B = new T[capacity];
			for (int i = 0; i < capacity; ++i)
			{
					B[i] = A[i];
			}
		}
		A[length] = element;
		length++;

	}

	T pop()
	{
		T element = 0.0;
		if(capacity == 0)
		{
			return 0;
		}
		element = A[length - 1];
		--length;
		return element;
	}

	bool isEmpty()
	{
		if(length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
#endif