#pragma once
#include <iostream>
using namespace std;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

template <class T>
class Array {
	T*data = new T[0];
	int size = 0;
public:
	Array(int size)
	{
		delete[]data;
		data = new T[size];
		this->size = size;
	}

	Array(Array & arr)
	{
		delete[]data;
		size = arr.getSize();
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr.data[i];
		}
	}

	~Array() 
	{
		delete[] data;
	}

	void setData(int index, T data)
	{
		if (index > -1 && index < size)
		{
			this->data[index] = data;
		}
	}

	T getData(int index)
	{
		if (index > -1 && index < size)
		{
			return data[index];
		}
	}

	int getSize()
	{
		return size;
	}

	void print() 
	{
		cout << "Array: (";
		for (int i = 0; i < size; i++) {
			if (i > 0) {
				cout << ", ";
			}
			else {
				cout << " ";
			}
			cout << data[i];
		}
		cout << " )\n";
	}

	friend Array operator+ (const Array &a, const Array &b)
	{
		Array A(a.size + b.size);
		for (int i = 0; i < a.size; i++)
		{
			A.data[i] = a.data[i];
		}

		for (int j = 0; j < b.size; j++)
		{
			A.data[j + a.size] = b.data[j];
		}

		return A;
	}

	T operator [](int index)
	{
		return getData(index);
	}

	friend bool operator != (const Array&a, const Array&b)
	{
		if (a.size != b.size)
			return 1;
		else
		for (int i = 0; i < a.size; i++)
		{
			if (a.data[i] != b.data[i])
				return 1;
		}
		return 0;
	}

	Array<T> & operator = (Array<T> & arr)
	{
		delete[]data;
		size = arr.getSize();
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr.data[i];
		}
		return *this;
	}

	friend bool operator >(const Array &a, const Array&b)
	{
		for (int i = 0; i < a.size; i++)
		{
			bool y = 0;
			for (int n = 0; n < b.size; n++)
			{
				if (b.data[i] == a.data[n])
				{
					y = 1;
					break;
				}

			}
			if (y == 0)
			{
				return 0;
			}
		}
		return 1;
	}

};