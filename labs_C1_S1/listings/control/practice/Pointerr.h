#pragma once
#include <iostream>
using namespace std;
#define MAX_SIZE 10
//---------------------------------------------------------------------------
//ƒинамический массив.
//---------------------------------------------------------------------------
void Dynamic_memory_new(void)
{
	int    * Arr;        // ”казатель на массив
	int    i, Nn;        // Nn - длина
	int    * ip;         // –абоча€ переменна€ дл€ косвенной адресации
	cout << "Input Count of elements\n";
	cin >> Nn;
	Arr = new int[Nn];  // ¬ыделение пам€ти дл€ массива
//јдресаци€ по индексу
	cout << "Input " << Nn << " elements\n";
	for (i = 0; i < Nn; i++)
		cin >> Arr[i];
		cout << endl;
//јдресаци€ по указателю
	cout << "Is elements\n";
	for (ip = Arr; ip < Arr + Nn; ip++)
		cout << " " << *ip;
	cout << endl;
//¬ысвобождение пам€ти
	delete[]Arr;
}

//-----------------------------------------------------------------------------------
// јлгоритмы.
void Out_Arr_2(float Arr[], int len)        // ƒлина len не измен€етс€ - значение.
{
	int i;
	cout.precision(3);
	cout << "Is array:\n";
	for (i = 0; i<len; i++)
		cout << "  " <<  Arr[i];
	cout << endl;;
}

void Input_Arr_2(float *Arr, int &len)        // ƒлина len измен€етс€ - & адрес.
{                                          
	float *ip; //переменна€-ссылка
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
	float * Arr_Copy;	     // ќбласть ќѕ, св€занна€ с указателем.
	Arr_Copy = new float[len];    //	–еальный адрес.
	for (int i = 0; i < len; i++)
		Arr_Copy[i] = Arr[i];
	return Arr_Copy;
}

//======================================================================
//”пражение 3 - опишем twoArr()
float* twoArr
(float *mix_arr, int size, 
 float *two_arr_ptr, 
 int& positive_counter, //по ссылке
 int& negative_counter) //по ссылке

{ 	//перед выделением пам€ти нужно подсчитать количество положительных и отрицательных значений (без нулей!)
	for (int i = 0; i < size; i++)
	{
		if (mix_arr[i] != 0) //нулевые значени€ пропускаютс€
		{
			if (mix_arr[i] < 0)
				negative_counter++;
			else
			if (mix_arr[i] > 0)
				positive_counter++;
			else continue;
		}
	else continue;
	}
	//выдел€ем пам€ть под новый массив (массивы)
	two_arr_ptr = new float[positive_counter+negative_counter]();

	
	int delta_pos = 0;
	int delta_neg = 0;

	for (int i = 0; i < size; i++)
	{
		if (mix_arr[i] != 0) 
		{
			if (mix_arr[i] < 0)
			{	//positive_counter - смещение дл€ расстановки элементов второго массива (-)
				two_arr_ptr[positive_counter+delta_neg] = mix_arr[i];
				delta_neg++;
			}
			if (mix_arr[i] > 0) 
			{
				two_arr_ptr[delta_pos] = mix_arr[i];
				delta_pos++; 
			}
		}
		else continue;
	}
	return two_arr_ptr; //указатель на начало массива из двух массивов
	//решение достаточно: теперь мы можем оперировать двум€ указател€ми первых элементов (&arr[0]) и соответствующими двум€ длинами непрерывной однородной пам€ти
}


//дл€ упражнени€ є4 - возврат адреса целочисленного массива
int *new_arr(const unsigned int size)
{
    int *new_arr = new int[size]();
    for (int i = 0; i < size; i++)
    {
        if ((i+1)%2 == 0) 
             new_arr[i] = -(i+1)/2;
        else new_arr[i] =  (i+2)/2;
    }
    return new_arr;
}




