#pragma once
#include <initializer_list>
#include <iostream>


using namespace std;
template <class T>
class Vector
{
	T* data{ nullptr };
	int size{ 0 };
	int copacity{ 0 };

public:
	Vector()
	{
		copacity = 0;
		size = 0;
		data = nullptr;
	}

	Vector(int len) : size(len), copacity(len)
	{
		if (len <= 0)
			throw ("Size should be greater than zero");
		data = new T[copacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}

	Vector(const Vector& v) : Vector(v.size)
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = v.data[i];
		}
	}

	Vector(const initializer_list<T>& initList) : Vector(initList.size())
	{
		int ind = 0;
		for (auto i = initList.begin(); i != initList.end(); ++i)
		{
			data[ind] = *i;
			ind++;
		}
	}

	Vector(Vector&& v) noexcept
	{
		if (this != &v)
		{
			delete[] data;
			size = v.size;
			copacity = v.copacity; 
			data = v.data; 
			v.data = nullptr;
			v.size = 0;
			v.copacity = 0;
		}
	}

	~Vector()
	{
		delete[] data;
		data = nullptr;
		copacity = 0;
		size = 0;
	}

	void resize(int newSize)
	{
		if (size >= newSize)
		{
			size = newSize;
		}
		else
		{
			copacity = 2 * newSize;
		}

		T* newData = new T[copacity];
		for (int i = 0; i < newSize; i++)
		{
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		size = newSize;
	}

	Vector& operator=(const initializer_list<T>& initList)
	{
		copacity = initList.copacity;
		size = initList.size;
		data = new T[copacity];
		for (auto i = initList.begin(); i != initList.end(); ++i)
		{
			data[i] = *i;
		}

		return *this;
	}

	Vector& operator=(const Vector& v)
	{
		if (&v == this)
		{
			return *this;
		}
		delete[] data;
		copacity = v.copacity;
		size = v.size;
		data = new T[copacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = v.data[i];
		}
		return *this;
	}

	Vector& operator=(Vector&& v) 
	{
		if (this == &v) {
			return *this;
		}
		delete[] data;
		data = v.data;
		copacity = v.copacity;
		size = v.size;
		v.data = nullptr;
		v.copacity = 0;
		v.size = 0;
		return *this;
	}

	bool operator==(const Vector<T>& v) const
	{
		if (this == &v)
		{
			return true;
		}
		if (size == v.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] != v.data[i])
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	bool operator!=(const Vector<T>& v) const 
	{
		return !(*this == v);
	}
	void push_back(T value)
	{
		if (copacity < size + 1)
		{
			resize(size + 1);
		}
		else
		{
			size++;
		}
		data[size - 1] = value;
	}

	T pop_back()
	{
		if (size() == 0)
			throw ("Vector is empty");
		T tmp = data[size - 1];
		size--;
		return tmp;
	}

	void insert(int pos, T value)
	{
		Vector newV(size + 1);
		for (int i = 0; i < pos; i++)
		{
			newV.data[i] = data[i];
		}

		newV.data[pos] = value;

		for (int i = pos; i < size; i++)
		{
			newV.data[i + 1] = data[i];
		}

		resize(size + 1);
		for (int i = 0; i < size; i++)
		{
			data[i] = newV.data[i];
		}
	}

	T erase(int pos)
	{
		if (index > size)
			throw "index is out of range";
		T tmp = data[pos];
		for (int i = pos + 1; i < size; i++)
		{
			data[i - 1] = data[i];
		}
		size--;
		return tmp;
	}

	T& operator[](int i)
	{
		if ((i = > size) || (i < 0))
		{
			throw ("index out of range")
		}
		return data[i];
	}

	int getsize()
	{
		return size;
	}

	T operator[](int i) const
	{
		if ((i = > size) || (i < 0))
		{
			throw ("index out of range")
		}
		return data[i];
	}

	friend ostream& operator<<(ostream& out, const Vector& v) {
		out << "[\t";
		for (int count = 0; count < v.size; count++) {
			out << v.data[count] << "\t";
		}
		out << "]";
		return out;
	}
	friend istream& operator>>(istream& in, Vector& v) {
		for (int count = 0; count < size; count++) {
			cout << "[" << count << "] = "; in >> data[count];
		}
		return in;
	}
};
