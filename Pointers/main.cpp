//Pointers
#include <iostream>
using namespace std;

#define POINTERS_BASICS
//#define POINTERS_AND_ARRAYS

void main()
{
	setlocale(LC_ALL, "");
#if defined POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // вывод значения переменной 'а'
	cout << &a << endl; // взятие адреса переменной а прямо при выводе
	cout << pa << endl;
	cout << *pa << endl;
	cout << typeid(pa).name() << endl;
	cout << pa[0] << endl;
#endif

#if defined POINTERS_AND_ARRAYS

	const int n = 6;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << &arr[0] << endl;

	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

#endif

}
