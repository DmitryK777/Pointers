// DynamicMemory
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define Y 89
#define y 121

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* Push_Back(int* arr, int& n, const int value);          // Добавляет значение в конец массива
int* Push_Front(int* arr, int& n, const int value);         // Добавляет значение в начало массива
int* Insert(int* arr, int& n, int index, int value);        // Вставляет значение в массив по заданному индексу
int* Pop_Back(int* arr, int& n);                            // Удаляет последний элемент масива
int* Pop_Front(int* arr, int& n);                           // Удаляет нулевой (он же первый или начальный) элемент массива
int* Erase(int* arr, int& n, int index);                    // Удаляет элемент из массива по заданному индексу

int** Allocate(const int rows, const int cols);             // Выделяет память под двумерный динамический массив
void Clear(int** arr, const int rows, const int cols);      // Удаляет двумерный динамический массив из памяти
int** push_row_back(int** arr, int& rows, const int cols);  // Добавляет строку в конец массива
int** push_row_front(int** arr, int& rows, const int cols); // Добавляет строку в начало массива
int** insert_row(int** arr, int& rows, const int cols, int index_add); // Вставляет строку в массив по указанному индексу
int** pop_row_back(int** arr, int& rows, const int cols);   // Удаляет последнюю строку из массива
int** pop_row_front(int** arr, int& rows, const int cols);  // Удаляет начальную (нулевую) строку из массива
int** erase_row(int** arr, int& rows, const int cols, int index_remove);  // Удаляет строку из массив по указанному индексу

int** push_col_back(int** arr, const int rows, int& cols);  // Добавляет столбец в конец массива
int** push_col_front(int** arr, const int rows, int& cols); // Добавляет столбец в начало массива
int** insert_col(int** arr, const int rows, int& cols, int index_add); // Вставляет столбец в массив по указанному индексу
int** pop_col_back(int** arr, const int rows, int& cols);   // Удаляет последний столбец из массива
int** pop_col_front(int** arr, const int rows, int& cols);  // Удаляет начальный (нулевой) столбец из массива
int** erase_col(int** arr, const int rows, int& cols, int index_remove);  // Удаляет столбец из массив по указанному индексу

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#if defined DYNAMIC_MEMORY_1
	int n;
	cout << "Введите количество элементов: "; cin >> n;
	
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);


	int value_add_end;
	cout << "Введите значение добавляемое в конец массива: "; cin >> value_add_end;
	arr = Push_Back(arr, n, value_add_end);
	Print(arr, n);

	int value_add_begin;
	cout << "Введите значение добавляемое в начало массива: "; cin >> value_add_begin;
	arr = Push_Front(arr, n, value_add_begin);
	Print(arr, n);

	int index_add;
	int value_add;
	cout << "Введите индекс в массиве добавляемого значения: "; cin >> index_add;
	cout << "Введите добавляемое значение : "; cin >> value_add;
	arr = Insert(arr, n, index_add, value_add);
	Print(arr, n);

	char key;
	cout << "Нажмите \"Y\" или \"y\" для удаления последнего элемента массива: "; cin >> key;
	if ((int)key == Y || (int)key == y)
	{
		arr = Pop_Back(arr, n);
		Print(arr, n);
	}
	else cout << "Ну не надо так не надо - как хотите!" << endl << endl;


	cout << "Нажмите \"Y\" или \"y\" для удаления начального элемента массива: "; cin >> key;
	if ((int)key == Y || (int)key == y)
	{
		arr = Pop_Front(arr, n);
		Print(arr, n);
	}
	else cout << "Ну не надо так не надо - как хотите!" << endl << endl;
	
	int index_remove;
	cout << "Введите индекс в массиве удаляемого значения элемента: "; cin >> index_remove;
	arr = Erase(arr, n, index_remove);
	Print(arr, n);
	cout << endl;



	delete[] arr;
#endif

#if defined DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	cout << "Массив с добавленной строкой в конце:" << endl;
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	cout << "Массив с добавленной строкой в начале:" << endl;
	Print(arr, rows, cols);

	int index_add;
	cout << "Введите индекс добавляемой строки: "; cin >> index_add;
	arr = insert_row(arr, rows, cols, index_add);
	cout << "Массив с добавленной строкой по индексу = " << index_add << ":" << endl;
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	cout << "Массив с удалённой строкой в конце:" << endl;
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	cout << "Массив с удалённой строкой в начале:" << endl;
	Print(arr, rows, cols);

	int index_remove;
	cout << "Введите индекс удаляемой строки: "; cin >> index_remove;
	arr = erase_row(arr, rows, cols, index_remove);
	cout << "Массив с удалённой строкой по индексу = " << index_remove << ":" << endl;
	Print(arr, rows, cols);

	arr = push_col_back(arr, rows, cols);
	cout << "Массив с добавленным столбцом в конце:" << endl;
	Print(arr, rows, cols);
	
	arr = push_col_front(arr, rows, cols);
	cout << "Массив с добавленным столбцом в начале:" << endl;
	Print(arr, rows, cols);
	
	cout << "Введите индекс добавляемого столбца: "; cin >> index_add;
	arr = insert_col(arr, rows, cols, index_add);
	cout << "Массив с добавленным столбцом по индексу = " << index_add << ":" << endl;
	Print(arr, rows, cols);
	
	arr = pop_col_back(arr, rows, cols);
	cout << "Массив с удалённым столбцом в конце:" << endl;
	Print(arr, rows, cols);
	
	arr = pop_col_front(arr, rows, cols);
	cout << "Массив с удалённым столбцом в начале:" << endl;
	Print(arr, rows, cols);
	
	cout << "Введите индекс удаляемого столбца: "; cin >> index_remove;
	arr = erase_col(arr, rows, cols, index_remove);
	cout << "Массив с удалённым столбцом по индексу = " << index_remove << ":" << endl;
	Print(arr, rows, cols);
	
	Clear(arr, rows, cols);
	
#endif
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int* Push_Back(int* arr, int& n, const int value)
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

int* Push_Front(int* arr, int& n, const int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}

	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
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
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i]; 
	delete[] arr;
	return buffer;
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

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}

	return arr;
}

void Clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows+1];

	for (int i = 0; i < (rows+1); i++)
	{
		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	delete[] arr;
	
	for (int i = 0; i < cols; i++)
	{
		buffer[rows][i] = rand() % 100;
	}
	rows++;
	
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < (rows + 1); i++)
	{
		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i+1][j] = arr[i][j];
		}
	}

	delete[] arr;

	for (int i = 0; i < cols; i++)
	{
		buffer[0][i] = rand() % 100;
	}
	rows++;

	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, int index_add)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < (rows + 1); i++)
	{
		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < index_add; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = index_add; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i+1][j] = arr[i][j];
		}
	}

	delete[] arr;

	for (int i = 0; i < cols; i++)
	{
		buffer[index_add][i] = rand() % 100;
	}
	rows++;

	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	delete[] arr;

	return buffer;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows-1];

	for (int i = 0; i < (rows-1); i++)
	{
		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < (rows-1); i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i+1][j];
		}
	}

	delete[] arr;
	rows--;

	return buffer;
}

int** erase_row(int** arr, int& rows, const int cols, int index_remove)
{
	int** buffer = new int* [rows - 1];

	for (int i = 0; i < (rows - 1); i++)
	{
		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < index_remove; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = index_remove; i < (rows-1); i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i+1][j];
		}
	}

	delete[] arr;

	rows--;

	return buffer;
}

int** push_col_back(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols+1] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	delete[] arr;

	for (int i = 0; i < rows; i++)
	{
		buffer[i][cols] = rand() % 100;
	}
	cols++;

	return buffer;
}

int** push_col_front(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols+1] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j+1] = arr[i][j];
		}
	}

	delete[] arr;

	for (int i = 0; i < rows; i++)
	{
		buffer[i][0] = rand() % 100;
	}
	cols++;

	return buffer;
}

int** insert_col(int** arr, const int rows, int& cols, int index_add)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols+1] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index_add; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = index_add; j < cols; j++)
		{
			buffer[i][j+1] = arr[i][j];
		}
	}

	delete[] arr;

	for (int i = 0; i < rows; i++)
	{
		buffer[i][index_add] = rand() % 100;
	}
	cols++;

	return buffer;
}

int** pop_col_back(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols-1] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < (cols-1); j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	delete[] arr;
	cols--;

	return buffer;
}

int** pop_col_front(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols-1] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < (cols-1); j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
	}

	delete[] arr;
	cols--;

	return buffer;
}

int** erase_col(int** arr, const int rows, int& cols, int index_remove)
{
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols-1] {};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index_remove; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = index_remove; j < (cols-1); j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
	}

	delete[] arr;

	cols--;

	return buffer;
}