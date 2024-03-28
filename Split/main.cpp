// Split
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);

template<typename T>
void Print(T arr[], const int n);

void TestOfArrMembers(int arr[], const int n, int& even_number, int& odd_number);

int* Push_Back(int *arr, int& length, int value);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	const int n = 10;
	int arr[n];

	FillRand(arr, n);

	cout << "Исходный массив:" << endl;
	Print(arr, n);
	
	int even_number = 0;
	int odd_number = 0;

	TestOfArrMembers(arr, n, even_number, odd_number);
	
	cout << "Количество чётных членов: " << even_number << endl;
	cout << "Количество нечётных членов: " << odd_number << endl;
	cout << endl;
	
	int even_length = 0;
	int* evenArr = new int[even_length];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			evenArr = Push_Back(evenArr, even_length, arr[i]);
		}
	}
	cout << "Чётные члены исходного массива:" << endl;
	Print(evenArr, even_length);

	int odd_length = 0;
	int* oddArr = new int[odd_length];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			oddArr = Push_Back(oddArr, odd_length, arr[i]);
		}
	}
	cout << "Нечётные члены исходного массива:" << endl;
	Print(oddArr, odd_length);
	

	delete[] evenArr;
	delete[] oddArr;
	
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++) 
	{
		arr[i] = rand() % 100;
	}
}

template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
	cout << endl;
}

void TestOfArrMembers(int arr[], const int n, int& even_number, int& odd_number)
{
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] % 2 == 0) even_number++;
		else odd_number++;
	}
}

int* Push_Back(int *arr, int& length, int value)
{
	length++;
	int* buffer = new int[length];

	for (int i = 0; i < (length-1); i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	arr[length-1] = value;

	return arr;
}
