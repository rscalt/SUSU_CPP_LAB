#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Для srand()
using namespace std;

void Rand_Arr(int a[], int len_a)
{

// Заполнение массива. 
// Функция rand() возвращает псевдослучайное целое в диапазоне от
// 0 to RAND_MAX (32767). 
for (int i = 0; i < len_a; i++)
	a[i] = (double)rand( ) / (RAND_MAX + 1) * 50 - 25;
	    // Диапазон -25 - +25 
}

void Print_Arr (int a[], int len_a)	     // Имя (int a, int b)
{ //Вывод массива
cout << "\nIs Array:\n";
for (int i = 0; i < len_a; i++)
	cout << " " << a[i];
cout << endl;
}
void Print_Arr (float a[], int len_a)
{ //Вывод массива
	cout << "\nIs Array:\n";
	for (int i = 0; i<len_a; i++)
		cout << " " << a[i];
	cout << endl;
}

void Input_Arr(int a[], int & len_a)
{ //Ввод массива
   cout << "\nInput length of Array:\n";
   cin >> len_a;	// Сколько данных.
   cout <<"\nInput " << len_a << " elements of Array:\n";
   for (int i = 0; i < len_a; i++)
	  cin >> a[i];
}
void Input_Arr(float a[], int &len_a)
{
//Ввод массива
	cout << "\nInput length of Array:\n";
	cin >> len_a;	// Сколько данных.
	cout << "\nInput " << len_a << " elements of Array:\n";
	for (int i = 0; i<len_a; i++)
		cin >> a[i];
}

// Среднее арифметическое.
float Avg(float a[], int len)
{
float S=0;
// Суммирование элементов
for (int i=0;i<len;i++)
	S+=a[i];
return  S / (float) len;
}

// Примеры функций обработки массивов.
// 2. Минимаксы.
// 3. Удаление элемента.

// 1. Проверить, упорядочен ли.   11,22,33,5, 55
int YesUp(int a[], int n)
{ // Думаем, что упорядочен.
for (int i = 0; i<n - 1; i++)
	if (a[i + 1] >= a[i])
		return 0;
return 1;
}
int YesDown(int a[], int n)
{ // Думаем, что упорядочен.
	for (int i = 0; i<n - 1; i++)
		if (a[i + 1] <= a[i])
			return 0;
	return 1;
}
// 2. Минимакс.
int Min(int a[], int n)
{ 	// Номер наименьшего.
int min=0;
for (int i=1; i<n; i++)
	if (a[i]<a[min])
		min=i;
return min;
}
// Изменение длины массива. ! контроль выхода.
// 3. Удаление. Удаление наименьшего.
int Del(int a[], int  &n)
{
int del = Min(a,n);	// Номер наименьшего.
if (del==n-1)
	n--;
else   // Сдвиг
	{
	for (int k = del; k<n-1; k++)
      a[k] = a[k+1];
    n--;
    } 
return 1;   // Было удалено или нет. 
}

// Найти точку, наиболее удаленную от начала координат.
// Функция вернет ее номер.
int Point(float x[], float y[], int Count)
{
	int maxn = 0;
	float R = sqrt(x[0] * x[0] + y[0] * y[0]);
	for(int i=1; i<Count; i++)
		if (sqrt(x[i] * x[i] + y[i] * y[i]) > R)
		{
			maxn = i;
			R = sqrt(x[i] * x[i] + y[i] * y[i]);
		}
	return maxn;
}

struct Stud
{
	std::string Name;
	std::string NickName;
	int Weigth;
	int Age;
};


