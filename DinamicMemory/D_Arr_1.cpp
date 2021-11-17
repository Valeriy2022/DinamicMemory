#include"D_Arr_1.h"
template<typename T>T* push_back(T arr[], unsigned int& n, T value)
{
	//1) Создаем буферный массив:
	T* buffer = new T[n + 1]{};
	//2) Копируем значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Теперь buffer выглядит точно так же, как должен выглядить arr
	//поэтому подменяем адрес старого массива адресом ного (буферного) массива:
	arr = buffer;	//перезаписываем адрес старого массива адресом нового массива
	//5) Только после всего этого в массив arr можно добавить значение:
	arr[n] = value;	//Добавляем значение в конец массива
	//6) После того как в массиве добавился элемент, количество его элементов увеличивается на 1
	n++;
	//7) Значение добавлено
	return arr;	//Возвращаем адрес нового массива, с добавленным значением.
}
template<typename T>T* push_front(T arr[], unsigned int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>T* insert(T arr[], unsigned int& n, T value, unsigned int index)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
template<typename T>T* pop_back(T arr[], unsigned int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T arr[], unsigned int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T>T* erase(T arr[], unsigned int& n, unsigned int index)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}