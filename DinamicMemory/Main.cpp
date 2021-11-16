#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const unsigned int n);
void Print(int** arr, const int rows, const int cols);

//int* push_back(int arr[], unsigned int& n, int value);
//int* push_front(int arr[], unsigned int& n, int value);
//int* insert(int arr[], unsigned int& n, int value, unsigned int index);
//int* pop_back(int arr[], unsigned int& n);
//int* pop_front(int arr[], unsigned int& n);
//int* erase(int arr[], unsigned int& n, unsigned int index);

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);

int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** pop_row_front(int** arr, unsigned int& rows, const unsigned int cols);

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols);
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols);
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols);
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols);
void insert(int** arr, const unsigned int rows, unsigned int& cols, unsigned int index);
void erase(int** arr, const unsigned int rows, unsigned int& cols, unsigned int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PREFORMANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	unsigned int n;	//������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ������ ������������ ��������: ";
	cin >> index;
	cout << "������� ����������� ��������: ";
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
	cout << "������� ������ ���������� ��������: ";
	cin >> index1;
	arr = erase(arr, n, index1);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = allocate(rows, cols);
	///////////////////////////////////////////////////////////////////////////////
	////////////	������������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "���������� ������ � ����� �������:\n";
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��������� ����������� ������ ���������� �������:\n";
	FillRand(arr[rows - 1], cols, 1000, 2000);
	Print(arr, rows, cols);
	cout << "������� ��������� ������ �� �������:\n";
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "���������  ������ � ������ �������:\n";
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ ������ �� �������:\n";
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "��������� ������� � ����� �������:\n";
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������� � ����� �������:\n";
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��������� ������� � ������ �������:\n";
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������� �� ������ �������:\n";
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��������� ������� �� ������� � ������:\n";
	int index3;
	cout << "������� ������ ������������ �������: ";
	cin >> index3;
	insert(arr, rows, cols, index3);
	Print(arr, rows, cols);
	int index4;
	cout << "������� ������ ���������� �������: ";
	cin >> index4;
	erase(arr, rows, cols, index4);
	Print(arr, rows, cols);
	clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

#ifdef PREFORMANCE_CHECK
	unsigned int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = allocate(rows, cols);
	cout << "������ ��������, ��� ���������� ������ ������� ����� �������\n";
	system("PAUSE");
	arr = push_row_back(arr, rows, cols);
	clear(arr, rows);
#endif // PREFORMANCE_CHECK

}

void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
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
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		//cout << arr[i] << ":\t";
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* push_back(int arr[], unsigned int& n, int value)
{
	//1) ������� �������� ������:
	int* buffer = new int[n + 1]{};
	//2) �������� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ������ buffer �������� ����� ��� ��, ��� ������ ��������� arr
	//������� ��������� ����� ������� ������� ������� ���� (���������) �������:
	arr = buffer;	//�������������� ����� ������� ������� ������� ������ �������
	//5) ������ ����� ����� ����� � ������ arr ����� �������� ��������:
	arr[n] = value;	//��������� �������� � ����� �������
	//6) ����� ���� ��� � ������� ��������� �������, ���������� ��� ��������� ������������� �� 1
	n++;
	//7) �������� ���������
	return arr;	//���������� ����� ������ �������, � ����������� ���������.
}
int* push_front(int arr[], unsigned int& n, int value)
{
	int* buffer = new int[n + 1]{};
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
int* insert(int arr[], unsigned int& n, int value, unsigned int index)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], unsigned int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], unsigned int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* erase(int arr[], unsigned int& n, unsigned int index)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** allocate(const unsigned int rows, const unsigned int cols)
{
	///////////////////////////////////////////////////////////////////////////////
	////////////		���������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////
	int** arr = new int* [rows];	//������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};	//�������� ������ ��� ������ ���������� �������
		//� �������� ������ ����� � �������� ������� ����������.
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	///////////////////////////////////////////////////////////////////////////////
	////////////		�������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////
	//1) ������� ������ ���������� �������:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) ������� ������ ����������:
	delete[] arr;
}

int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};	//������� ����� ������ ����������
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	delete[] arr;	//������� ������ ������ ����������
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	delete[] arr[rows];	//������� ��������� ������ �� ������
	delete[] arr;	//������� ������ ������ ����������
	return buffer;
}
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};	//������� ����� ������ ����������
	for (int i = 0; i < rows; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;	//������� ������ ������ ����������
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows - 1]{};	//������� ����� ������ ����������
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;	//������� ������ ������ ����������
	arr = buffer;
	rows--;
	return arr;
}

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void insert(int** arr, const unsigned int rows, unsigned int& cols, unsigned int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void erase(int** arr, const unsigned int rows, unsigned int& cols, unsigned int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}