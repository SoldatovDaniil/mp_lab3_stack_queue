#include <algorithm>


template<class T>
class Queque
{
	T* data;
	int size, copacity, left, right;
public:
	Queque(): size(0), copacity(10), left(0), right(0)
	{
		data = new T[copacity];
	}

	Queque(const Queque& q)
	{
		size = q.size;
		left = q.left;
		right = q.right;
		copacity = q.copacity;
		data = new T[copacity];
		std::copy(q.data, q.data + size, data);
	}

	~Queque()
	{
		size = 0;
		copacity = 0;
		left = 0;
		right = 0;
		delete[] data;
	}

	Queque& operator=(const Queque& q)
	{
		if (*this == q)
		{
			return *this;
		}
		left = q.left;
		right = q.right;
		size = q.size;
		copacity = q.copacity;
		delete[] data;
		data = new T[copacity];
		std::copy(q.data, q.data + q.size, data);
		return *this;
	}

	int getsize()
	{
		return size;
	}

	void resize()
	{
		copacity = size * 2;
		T* tmp = new T[copacity];
		std::copy(data + right, data + size, tmp);
		std::copy(data, data + left, tmp + size - right);
		right = size;
		left = 0;
		delete[] data;
		data = tmp;
	}

	void push(T value)
	{
		data[right] = value;
		right += 1;
		size++;
		if (right >= copacity)
		{
			right = 0;
		}
		if (size != 0 && right == left)
		{
			resize();
		}
	}

	void pop()
	{
		if (size == 0 || left > right)
		{
			throw ("Queque is empty");
		}
		data[left] = 0;
		left += 1;
		size++;
		if (left >= copacity)
		{
			left = 0;
		}
	}

	T top()
	{
		if (size <= 0)
		{
			throw ("Queque is empty");
		}
		return data[left];
	}
};