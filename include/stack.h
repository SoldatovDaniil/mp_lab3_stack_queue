#include "vector.h"


template <class T>
class Stack 
{
	Vector<T> pMem;

public: 
	Stack() = default;

	Stack(const Stack& stack) 
	{
		pMem = stack.pMem;
	}
	
	void pop()
	{
		if (empty() == true)
		{
			throw ("stack is empty");
		}
		pMem.pop_back();
	}

	void push(const T& value)
	{
		pMem.push_back(value);
	}

	Stack& operator=(const Stack& stack)
	{
		if (this == &stack)
		{
			return *this;
		}
		pMem = stack.pMem;
		return *this;
	}

	T top()
	{
		if (empty() == true)
		{
			throw ("stack is empty");
		}
		int ind = (pMem.getsize()) - 1;
		return pMem[ind];
	}

	bool empty()
	{
		if (getsize() == 0)
		{
			return true; 
		}
		else
		{
			return false;
		}
	}
};