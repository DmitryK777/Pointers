// DynamicMemory
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define Y 89
#define y 121

template <typename T> void FillRand(T arr[], const int n, int minRand = 0, int maxRand = 100);
template <typename T> void FillRand(T** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);


template<typename T> void Print(const T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> T* Push_Back(T arr[], int& n, T value);          // Добавляет значение в конец массива
template<typename T> T* Push_Front(T* arr, int& n, const T value);         // Добавляет значение в начало массива
int* Insert(int* arr, int& n, int index, int value);        // Вставляет значение в массив по заданному индексу
template<typename T> T* Pop_Back(T* arr, int& n);                            // Удаляет последний элемент масива
int* Pop_Front(int* arr, int& n);                           // Удаляет нулевой (он же первый или начальный) элемент массива
int* Erase(int* arr, int& n, int index);                    // Удаляет элемент из массива по заданному индексу

template <typename T> T** Allocate(const int rows, const int cols);             // Выделяет память под двумерный динамический массив
template <typename T> void Clear(T** arr, const int rows);      // Удаляет двумерный динамический массив из памяти

template<typename T> T** push_row_back(T** arr, int& rows, const int cols);  // Добавляет строку в конец массива
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols);   // Удаляет последнюю строку из массива

int** push_row_front(int** arr, int& rows, const int cols); // Добавляет строку в начало массива
int** insert_row(int** arr, int& rows, const int cols, int index_add); // Вставляет строку в массив по указанному индексу

int** pop_row_front(int** arr, int& rows, const int cols);  // Удаляет начальную (нулевую) строку из массива
int** erase_row(int** arr, int& rows, const int cols, int index_remove);  // Удаляет строку из массив по указанному индексу

template <typename T> void push_col_back(T** arr, const int rows, int& cols);  // Добавляет столбец в конец массива
template <typename T> void pop_col_back(T** arr, const int rows, int& cols);   // Удаляет последний столбец из массива

void push_col_front(int** arr, const int rows, int& cols); // Добавляет столбец в начало массива
void insert_col(int** arr, const int rows, int& cols, int index_add); // Вставляет столбец в массив по указанному индексу

void pop_col_front(int** arr, const int rows, int& cols);  // Удаляет начальный (нулевой) столбец из массива
void erase_col(int** arr, const int rows, int& cols, int index_remove);  // Удаляет столбец из массив по указанному индексу

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PERFORMANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#if defined DYNAMIC_MEMORY_1
	int n;
	cout << "Введите количество элементов: "; cin >> n;
	
	int* arr = new int[n];
	//double* arr = new double[n];

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
#endif // DYNAMIC_MEMORY_1

#if defined DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	//int** arr = Allocate(rows, cols);
	double** arr = Allocate<double>(rows, cols);
	
	
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	cout << "Массив с добавленной строкой в конце:" << endl;
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	/*arr = push_row_front(arr, rows, cols);
	cout << "Массив с добавленной строкой в начале:" << endl;
	Print(arr, rows, cols);

	int index_add;
	cout << "Введите индекс добавляемой строки: "; cin >> index_add;
	arr = insert_row(arr, rows, cols, index_add);
	cout << "Массив с добавленной строкой по индексу = " << index_add << ":" << endl;
	Print(arr, rows, cols);*/

	arr = pop_row_back(arr, rows, cols);
	cout << "Массив с удалённой строкой в конце:" << endl;
	Print(arr, rows, cols);

	/*arr = pop_row_front(arr, rows, cols);
	cout << "Массив с удалённой строкой в начале:" << endl;
	Print(arr, rows, cols);

	int index_remove;
	cout << "Введите индекс удаляемой строки: "; cin >> index_remove;
	arr = erase_row(arr, rows, cols, index_remove);
	cout << "Массив с удалённой строкой по индексу = " << index_remove << ":" << endl;
	Print(arr, rows, cols);*/

	push_col_back(arr, rows, cols);
	cout << "Массив с добавленным столбцом в конце:" << endl;
	Print(arr, rows, cols);
	
	/*push_col_front(arr, rows, cols);
	cout << "Массив с добавленным столбцом в начале:" << endl;
	Print(arr, rows, cols);
	
	cout << "Введите индекс добавляемого столбца: "; cin >> index_add;
	insert_col(arr, rows, cols, index_add);
	cout << "Массив с добавленным столбцом по индексу = " << index_add << ":" << endl;
	Print(arr, rows, cols);*/
	
	pop_col_back(arr, rows, cols);
	cout << "Массив с удалённым столбцом в конце:" << endl;
	Print(arr, rows, cols);
	
	/*pop_col_front(arr, rows, cols);
	cout << "Массив с удалённым столбцом в начале:" << endl;
	Print(arr, rows, cols);
	
	cout << "Введите индекс удаляемого столбца: "; cin >> index_remove;
	erase_col(arr, rows, cols, index_remove);
	cout << "Массив с удалённым столбцом по индексу = " << index_remove << ":" << endl;
	Print(arr, rows, cols);*/
	
	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

#ifdef PERFORMANCE_CHECK

	int rows, cols;
	cout << "введите количество строк: "; cin >> rows;
	cout << "введите количество элементов строки: "; cin >> cols;
	int** arr = Allocate(rows, cols);
	cout << "memory allocated" << endl;
	system("pause");
	arr = push_row_back(arr, rows, cols);
	cout << "add row complete" << endl;
	Clear(arr, rows);

#endif // PERFORMANCE_CHECK

}

template <typename T> void FillRand(T arr[], const int n, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		T buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	if (typeid(arr) == typeid(double*) || typeid(arr) == typeid(float*))
	{
		minRand *= 100;
		maxRand *= 100;
	}

	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand-minRand) + minRand;
		if (typeid(arr) == typeid(double*) || typeid(arr) == typeid(float*))
		{
			arr[i] /= 100;
		}
	}
}

template<typename T> void FillRand(T** arr, const int rows, const int cols, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		T buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}

	if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))
	{
		minRand *= 100;
		maxRand *= 100;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))arr[i][j] /= 100;
			
		}
	}
}

template<typename T> void Print(const T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

template<typename T> void Print(T** arr, const int rows, const int cols)
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

template<typename T> T* Push_Back(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];

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

template<typename T> T* Push_Front(T* arr, int& n, const T value)
{
	T* buffer = new T[n + 1];

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

template<typename T> T* Pop_Back(T* arr, int& n)
{
	T* buffer = new T[--n];
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

template <typename T> T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}

	return arr;
}

template <typename T> void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T*[rows+1];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	
	buffer[rows] = new T[cols] {};
	rows++;
	for (int i = 0; i < cols; i++) 	buffer[rows-1][i] = rand() % 100;
	
	return buffer;
}

template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	delete[] arr[rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++) buffer[i+1] = arr[i];
	delete[] arr;
	
	buffer[0] = new int[cols] {};
	rows++;
	
	for (int i = 0; i < cols; i++) 	buffer[0][i] = rand() % 100;

	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, int index_add)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index_add; i++) buffer[i] = arr[i];
	for (int i = index_add; i < rows; i++) buffer[i + 1] = arr[i];
	delete[] arr;

	buffer[index_add] = new int[cols] {};
	rows++;

	for (int i = 0; i < cols; i++) buffer[index_add][i] = rand() % 100;

	return buffer;
}



int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows-1];
	for (int i = 0; i < (rows-1); i++) buffer[i] = arr[i+1];
	delete[] arr[0];
	delete[] arr;
	rows--;

	return buffer;
}

int** erase_row(int** arr, int& rows, const int cols, int index_remove)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < index_remove; i++) buffer[i] = arr[i];
	for (int i = index_remove; i < rows; i++) buffer[i] = arr[i+1];
	delete[] arr[index_remove];
	delete[] arr;
	rows--;

	return buffer;
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;

	for (int i = 0; i < rows; i++) arr[i][cols - 1] = rand() % 100;
}

template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;

	for (int i = 0; i < rows; i++) arr[i][0] = rand() % 100;
}

void insert_col(int** arr, const int rows, int& cols, int index_add)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index_add; j++) buffer[j] = arr[i][j];
		for (int j = index_add; j < cols; j++) buffer[j+1] = arr[i][j];

		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;

	for (int i = 0; i < rows; i++) arr[i][index_add] = rand() % 100;
}

void pop_col_front(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void erase_col(int** arr, const int rows, int& cols, int index_remove)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < index_remove; j++) buffer[j] = arr[i][j];
		for (int j = index_remove; j < cols; j++) buffer[j] = arr[i][j+1];

		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}