#pragma once
#include <iostream>
using namespace std;
#define MAX_SIZE 10
//---------------------------------------------------------------------------
//Динамический массив.
//---------------------------------------------------------------------------
void Dynamic_memory_new(void)
{
	int    * Arr;        // Указатель на массив
	int    i, Nn;        // Nn - длина
	int    * ip;         // Рабочая переменная для косвенной адресации
	cout << "Input Count of elements\n";
	cin >> Nn;
	Arr = new int[Nn];  // Выделение памяти для массива
//Адресация по индексу
	cout << "Input " << Nn << " elements\n";
	for (i = 0; i < Nn; i++)
		cin >> Arr[i];
		cout << endl;
//Адресация по указателю
	cout << "Is elements\n";
	for (ip = Arr; ip < Arr + Nn; ip++)
		cout << " " << *ip;
	cout << endl;
//Высвобождение памяти
	delete[]Arr;
}

//-----------------------------------------------------------------------------------
// Алгоритмы.
void Out_Arr_2(float Arr[], int len)        // Длина len не изменяется - значение.
{
	int i;
	cout.precision(3);
	cout << "Is array:\n";
	for (i = 0; i<len; i++)
		cout << "  " <<  Arr[i];
	cout << endl;;
}

void Input_Arr_2(float *Arr, int &len)        // Длина len изменяется - & адрес.
{                                          
	float *ip; //переменная-ссылка
	cout << "Input Count < " << MAX_SIZE; //msize = 10 по #define
	cin >> len;
	cout << "Input elements\n";
	for (ip = Arr; ip < Arr + len; ip++)
		cin >> *ip;                   
}

// Arr[i] = Arr[i] * 2
void transform_One(float Arr[], int len) 
{
	int i;
	for (i = 0; i<len; i++)
		Arr[i] = Arr[i] * 2;
}
// if (Arr[i] < 0) : (Arr[k] = Arr[k + 1], len--)
void transform_Two(float *Arr, int &len)
{
	int i;
	for (i = 0; i < len; i++)
		if (Arr[i] < 0)
		{
			for (int k = i; k < len - 1; k++)
				Arr[k] = Arr[k + 1];
			len--;
		}
}

//копирование через параметры
void Copy_One(float Arr[], float Arr_Copy[], int len)
{
	for (int i = 0; i < len; i++)
		Arr_Copy[i] = Arr[i]; //параметрическое копирование
}

//return Arr_Copy as float*
float * Copy_Two(float Arr[], int len)
{
	float * Arr_Copy;	     // Область ОП, связанная с указателем.
	Arr_Copy = new float[len];    //	Реальный адрес.
	for (int i = 0; i < len; i++)
		Arr_Copy[i] = Arr[i];
	return Arr_Copy;
}




