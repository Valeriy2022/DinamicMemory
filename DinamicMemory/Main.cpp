#include"stdafx.h"
#include"FillRand.h"//Если функция НЕ шаблонная, то *.cpp-файл НИ В КОЕМ СЛУЧАЕ НЕ ПОДКЛЮЧАЕТСЯ
#include"Print.h"
#include"Print.cpp"	//Если функция шаблонная, то подключается еще и *.cpp-файл
#include"D_Arr_1.h"
#include"D_Arr_2.h"
#include"D_Arr_1.cpp"
#include"D_Arr_2.cpp"
#include"MknclrArr.cpp"
#include"MknclrArr.h"


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PREFORMANCE_CHECK

void main()
{
	using namespace std;
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	unsigned int n;	//Размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: ";
	cin >> index;
	cout << "Введите добавляемое значение: ";
	cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "\n---------------------------------------------\n";
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "\n---------------------------------------------\n";
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << "\n---------------------------------------------\n";
	int index1;
	cout << "Введите индекс удаляемого элемента: ";
	cin >> index1;
	arr = erase(arr, n, index1);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	double** arr = allocate<double>(rows, cols);
	///////////////////////////////////////////////////////////////////////////////
	////////////	Использование двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавление строки в конец массива:\n";
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Заполняем добавленную строку случайными числами:\n";
	FillRand(arr[rows - 1], cols, 1000, 2000);
	Print(arr, rows, cols);
	cout << "Удаляем последнюю строку из массива:\n";
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавляем  строку в начало массива:\n";
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Удаляем первую строку из массива:\n";
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляем столбец в конец массива:\n";
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Удаляем столбец с конца массива:\n";
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавляем столбец в начало массива:\n";
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Удаляем столбец из начала массива:\n";
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Вставляем столбец по индексу в массив:\n";
	int index3;
	cout << "Введите индекс добавляемого столбца: \n";
	cin >> index3;
	insert(arr, rows, cols, index3);
	Print(arr, rows, cols);
	int index4;
	cout << "Введите индекс удаляемого столбца: \n";
	cin >> index4;
	erase(arr, rows, cols, index4);
	Print(arr, rows, cols);
	clear(arr, rows);
	
	////https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F
	/*size_t d_rows, d_cols;
	cout << "Введите количество строк: "; cin >> d_rows;
	cout << "Введите количество элементов строки: "; cin >> d_cols;
	double** d_arr_2 = allocate<double>(d_rows, d_cols);
	FillRand(d_arr_2, d_rows, d_cols);
	Print(d_arr_2, d_rows, d_cols);
	clear(d_arr_2, d_rows);*/
#endif // DYNAMIC_MEMORY_2

#ifdef PREFORMANCE_CHECK
	unsigned int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	cout << "Память выделена, для добавления строки нажмите любую клавишу\n";
	system("PAUSE");
	arr = push_row_back(arr, rows, cols);
	clear(arr, rows);
#endif // PREFORMANCE_CHECK

}



