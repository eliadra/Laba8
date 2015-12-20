#include "Array.h"
#include "Person.h"
#include <iostream>
#include <time.h>
using namespace std;

template <class T>
void sort(Array<T> & arr)
{
	Array<T>temp(arr.getSize());
	for (int i = 0; i < arr.getSize(); i++)
	{
		int c = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				c++;
			}
		}
		for (int j = i + 1; j < arr.getSize(); j++)
		{
			if (arr[j] < arr[i])
			{
				c++;
			}
		}
		temp.setData(c, arr[i]);
	}
	arr = temp;
}

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	Array<int>arr1(rand() % 4 + 3);
	for (int i = 0; i < arr1.getSize(); i++) 
	{
		arr1.setData(i, rand() % 100);
	}

	arr1.print();

	Array<int>arr2(rand() % 4 + 3);
	for (int i = 0; i < arr2.getSize(); i++)
	{
		arr2.setData(i, rand() % 100);
	}
	arr2.print();

	cout << "Arr1 + Arr2 = ";
	Array<int>arr3 = arr1 + arr2;
	arr3.print();

	cout << "Proverka na vhogdenie:" << endl;
	cout << (arr1 > arr3);
	cout << endl;
	cout << (arr1 > arr2);
	cout << endl;


	cout << "Proverka na neravenstvo:" << endl;
	cout << (arr1 != arr2);
	cout << endl;
	cout << (arr2 != arr3);
	cout << endl;

	cout << "sort(Arr1) = ";
	sort(arr1);
	arr1.print();

	cout << "sort(Arr2) = ";
	sort(arr2);
	arr2.print();

	cout << "sort(Arr3) = ";
	sort(arr3);
	arr3.print();

	Array<Person>friends(3);
	Person Nick("Рамиль");
	friends.setData(0, Nick);
	friends.setData(1, Person("Катя"));
	friends.setData(2, Person("Ира"));
	friends.print();
	cout << "sort(friends) = ";
	sort(friends);
	friends.print();
}