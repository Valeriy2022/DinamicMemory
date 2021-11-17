#include"D_Arr_2.h"

template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T* [rows + 1]{};	//Создаем новый массив указателей
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	delete[] arr;	//Удаляем старый массив указателей
	arr = buffer;
	arr[rows] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T* [--rows]{};
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	delete[] arr[rows];	//Удаляем последнюю строку из памяти
	delete[] arr;	//Удаляем старый массив указателей
	return buffer;
}
template<typename T>T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T* [rows + 1]{};	//Создаем новый массив указателей
	for (int i = 0; i < rows; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;	//Удаляем старый массив указателей
	arr = buffer;
	arr[0] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** pop_row_front(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T* [rows - 1]{};	//Создаем новый массив указателей
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;	//Удаляем старый массив указателей
	arr = buffer;
	rows--;
	return arr;
}

template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void pop_col_back(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void push_col_front(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void insert(T** arr, const unsigned int rows, unsigned int& cols, unsigned int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void erase(T** arr, const unsigned int rows, unsigned int& cols, unsigned int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}