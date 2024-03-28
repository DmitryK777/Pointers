#include <iostream>
#include <conio.h>


using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define Y 89
#define y 121

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_Back(int* arr, int& n, int value);          // Добавляет значение в конец массива
int* Push_Front(int* arr, int& n, int value);         // Добавляет значение в начало массива
int* Insert(int* arr, int& n, int index, int value);  // Вставляет значение в массив по заданному индексу
int* Pop_Back(int* arr, int& n);                      // Удаляет последний элемент масива
int* Pop_Front(int* arr, int& n);                     // Удаляет нулевой (он же первый или начальный) элемент массива
int* Erase(int* arr, int& n, int index);              // Удаляет элемент из массива по заданному индексу

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите количество элементов: "; cin >> n;
	
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int value_add_end;
	cout << "Введите значение добавляемое в конец массива: "; cin >> value_add_end;
	arr = Push_Back(arr, n, value_add_end);
	Print(arr, n);
	cout << endl;

	int value_add_begin;
	cout << "Введите значение добавляемое в начало массива: "; cin >> value_add_begin;
	arr = Push_Front(arr, n, value_add_begin);
	Print(arr, n);
	cout << endl;

	int index_add;
	int value_add;
	cout << "Введите индекс в массиве добавляемого значения: "; cin >> index_add;
	cout << "Введите добавляемое значение : "; cin >> value_add;
	arr = Insert(arr, n, index_add, value_add);
	Print(arr, n);
	cout << endl;

	char key;
	cout << "Нажмите \"Y\" или \"y\" для удаления последнего элемента массива: "; cin >> key;
	if ((int)key == Y || (int)key == y)
	{
		arr = Pop_Back(arr, n);
		Print(arr, n);
		cout << endl;
	}
	else cout << "Ну не надо так не надо - как хотите!" << endl << endl;


	cout << "Нажмите \"Y\" или \"y\" для удаления начального элемента массива: "; cin >> key;
	if ((int)key == Y || (int)key == y)
	{
		arr = Pop_Front(arr, n);
		Print(arr, n);
		cout << endl;
	}
	else cout << "Ну не надо так не надо - как хотите!" << endl << endl;
	
	int index_remove;
	cout << "Введите индекс в массиве удаляемого значения элемента: "; cin >> index_remove;
	arr = Erase(arr, n, index_remove);
	Print(arr, n);
	cout << endl;


	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}

int* Push_Back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	arr[n] = value;
	n++;
	return arr;
}

int* Push_Front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		buffer[i+1] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	arr[0] = value;
	n++;
	return arr;
}

int* Insert(int* arr, int& n, int index, int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = (index + 1); i < (n+1); i++)
	{
		buffer[i] = arr[i-1];
	}

	delete[] arr;

	arr = buffer;

	arr[index] = value;
	n++;
	return arr;
}

int* Pop_Back(int* arr, int& n)
{
	int* buffer = new int[n - 1];

	for (int i = 0; i < (n-1); i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;
	n--;

	return arr;
}

int* Pop_Front(int* arr, int& n)
{
	int* buffer = new int[n - 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}

	delete[] arr;

	arr = buffer;
	n--;

	return arr;
}

int* Erase(int* arr, int& n, int index)
{
	int* buffer = new int[n - 1];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = (index); i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;

	arr = buffer;
	n--;

	return arr;
}