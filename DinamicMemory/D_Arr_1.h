#pragma once
#include"stdafx.h"
template<typename T>T* push_back(T arr[], unsigned int& n, T value);
template<typename T>T* push_front(T arr[], unsigned int& n, T value);
template<typename T>T* insert(T arr[], unsigned int& n, T value, unsigned int index);
template<typename T>T* pop_back(T arr[], unsigned int& n);
template<typename T>T* pop_front(T arr[], unsigned int& n);
//T* - ”казатель на шаблонный тип
template<typename T>T* erase(T arr[], unsigned int& n, int value, unsigned int index);

