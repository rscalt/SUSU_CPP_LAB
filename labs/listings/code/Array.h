#include <iostream>
#include <iomanip> 
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>  // Для srand()

using namespace std;
//===================================================

void Rand_Arr(int a[], int len_a)
{
// Заполнение массива. 
// Функция rand() возвращает псевдослучайное целое в диапазоне от
// 0 to RAND_MAX (32767). 
for (int i = 0; i < len_a; i++)
	a[i] = (double)rand( ) / (RAND_MAX + 1) * 50 - 25;
	    // Диапазон -25 - +25 
}

void Rand_Arr(int a[], int b[], int len) //заполнение двух парралельных массивов
{

for (int i = 0; i < len; i++)
	{
		a[i] = (double)rand( ) / (RAND_MAX + 1) * 50 - 25;
		b[i] = (double)rand( ) / (RAND_MAX + 1) * 50 - 25;
	    // Диапазон -25 - +25 
	}
}

void Rand_Arr(float a[], int len_a) //перегрузка для вещественных массивов
{
// Заполнение массива. 
// Функция rand() возвращает псевдослучайное целое в диапазоне от
// 0 to RAND_MAX (32767). 
for (int i = 0; i < len_a; i++)
	a[i] = (float)rand( ) / (RAND_MAX + 1) * 50 - 25;
	    // Диапазон -25 - +25 
}
//===================================================

void Print_Arr (int a[], int len_a)	     // Имя (int a, int b)
{ //Вывод массива
cout << "\nIs Array:\n";
for (int i=0; i<len_a; i++)
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
//===================================================

void Input_Arr(int a[], int &len_a)
{ //Ввод массива
   cout << "\nInput length of Array:\n";
   cin >> len_a;	// Сколько данных.
   cout <<"\nInput " << len_a << " elements of Array:\n";
   for (int i=0; i<len_a; i++)
	  cin >> a[i];
	}

void Input_Arr(float a[], int &len_a)
{
//Ввод массива
	cout << "\nInput length of Array:\n";
	cin >> len_a;	// Сколько данных.
	cout << "\nInput " << len_a << " elements of Array:\n";
	for (int i = 0; i<len_a; i++) //здесь -1 же
		cin >> a[i];
}
//===================================================

// Среднее арифметическое.
float Avg(float a[], int len)
{
float S=0;
// Суммирование элементов
for (int i=0;i<len;i++)
	S+=a[i];
return  S / (float) len;
}

//===================================================

// Примеры функций обработки массивов.
// 1. Проверить, упорядочен ли.
int YesUp(int a[], int n)
{ // Думаем, что упорядочен.
for (int i = 0; i< n - 1; i++)
	if (a[i + 1] >= a[i])
		return 0;
return 1;
}
int YesDown(int a[], int n)
{ // Думаем, что упорядочен.
	for (int i = 0; i< n - 1; i++)
		if (a[i + 1] <= a[i])
			return 0;
	return 1;
}

//===================================================

// 2. Минимакс находит и возвращает номер наименьшего элемента.
	int Min(int a[], int n)
	{ 	// Номер наименьшего.
	int min=0;
	for (int i=1; i<n; i++)
		if (a[i]<a[min])
			min=i;
	return min;
	}

int Min(float a[], int n) //добавим перегрузку для float-массива
{ 	// Номер наименьшего.
int min = 0;
for (int i = 1; i<n; i++)
	if (a[i]<a[min])
		min=i;
return min;
}

int Max(float a[], int n) //добавим функцию поиска индекса максимального элемента float-массива
{ 	// Индекс наибольшего
int max = n-1;
for (int i = max; i >= 0 ; i--)
	if (a[i] > a[max])
		max = i;
return max;
}

//===================================================

// Изменение длины массива. ! контроль выхода.
// 3. Удаление. Удаление наименьшего элемента массива.
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

int remove_farpoint(int x[], int y[], int  &n, int ind_far) //удаление самой дальней точки заданной через два параллельных массива
{
int del = ind_far;	// индекс самой дальней точки = точка сдвига
if (del == n-1)
	n--; //элемент отсекается изменением !ссылочной! длины массива
else   // Сдвиг
	{
	for (int k = del; k < n-1; k++) //сдвиг правой стороны влево
      {
	  x[k] = x[k+1]; 
      y[k] = y[k+1]; 
	  }    
	  n--; //отсекаем последний элемент, т.к. k = k+1
    } 
cout << " Point deleted sucessfully!";
return 1;   // Было удалено или нет. 

}
//===================================================

// Параллельные массивы.
// Найти точку, наиболее удаленную от начала координат.
// Функция вернет ее номер.
int Point(int x[], int y[], int Count)
{
	int maxn = 0;
	float R = sqrt(x[0] * x[0] + y[0] * y[0]);

	for(int i=1; i<Count; i++)
		if (sqrt(x[i] * x[i] + y[i] * y[i]) > R)
		{
			maxn = i;
			R = sqrt(x[i] * x[i] + y[i] * y[i]);
			//cout << i << ". R is " << R << "\n";
		}
	return maxn;
}

//=============================================
// авторские функции, в т.ч. по упражнениям

void print_array (float arr[], int arr_length) //элегантный вывод float
{
        cout << "Array at " << arr << ":\n";

        cout << "index\t" << "element\t";
		cout << "hex_address\t" << "dec_address\n";
    for (int i = 0; i < arr_length; i++)
		{
        cout << setw(2) << i << "\t";
		cout << setw(5) << setprecision(2) << arr[i] << "\t";
		cout << setw(10) << &arr[i] << "\t";
		printf("%d",&arr[i]);
		cout << "\n";
		}
}

void print_array (int arr[], int arr_length) //элегантный вывод int
{
        cout << "Array " << arr << ":\n";
		cout << "index\t" << "element\n";
    for (int i = 0; i < arr_length; i++)
        cout << setw(2) << i << "\t" << setw(5) << arr[i] << "\n";   
}

void print_array (int arr_a[], int arr_b[], int arr_length) //элегантный вывод двух параллельных int-массивов
{
        cout << "\nArrays " << arr_a << " and " << arr_b << ":\n";
		cout << "index\t" << setw(6) << "x\t" << "y\n";
    for (int i = 0; i < arr_length; i++)
        {
			cout << setw(2) << i << "\t" << setw(5) 
			<< arr_a[i] << "  " << arr_b[i] << "\n";   
		}
}

void transform_array (float arr[], int arr_length) //замена элементов, которые больше среднего - самим средним значением
{
    cout << "transform_array() initialized...\n";
    float arr_avg = Avg(arr, arr_length);
    for (int i = 0; i < arr_length; i++)
    {
        if (arr[i] > arr_avg) 
        {
            cout << arr[i] << " > "<< arr_avg << "; ";
            arr[i] = arr_avg;
            cout << "replacing arr["<< i << "] with average... \n"; //замена соответствующих значений средним значением
        }
    }
    cout << "Done!\n\n";
}

//===================================================

struct Stud
{
	std::string Name;
	std::string NickName;
	int Weigth;
	int Age;
};



