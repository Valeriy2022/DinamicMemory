#pragma once
#include"stdafx.h"
template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** pop_row_front(T** arr, unsigned int& rows, const unsigned int cols);

//T& - ссылка на шаблонный тип
template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void pop_col_back(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void push_col_front(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void insert(T** arr, const unsigned int rows, unsigned int& cols, unsigned int index);
template<typename T>void erase(T** arr, const unsigned int rows, unsigned int& cols, unsigned int index);
