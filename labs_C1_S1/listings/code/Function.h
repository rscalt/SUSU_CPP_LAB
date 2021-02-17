#pragma once
#include <math.h>
#include <iostream>
using namespace std;
// Тема 1. функция, возвращающая значение.
// Имеет тип, имеет имя, имеет список параметров.
// Функция находит среднее арифметическое трех чисел.
// Упражнение 1. Обращение к функции.

float Avg(float a, float b, float c)
{
	float T = (a + b + c) / 3.;

    cout << a << "\t";
    cout << b << "\t";
    cout << c << "\t";
    return T;
	 //через переменные
  	// Тип совпадает с типом функции.
	
}

// Упражнение 2. Написать функцию, которя найдет площадь треугольника по заданным длинам сторон.
// float Square(float a, float b, float c)

//см. файл area_heron ==========================

// Упражнение 3. Функция, не возвращающая значение.
// Имеет тип, имеет имя, имеет список параметров.
// Найдем таблицу значений функции y = sin(x)
// на произвольном диапазоне значений от x0 до xn

void Table(double x0, double xn, int Count)
{
	double x, y;
	double Delta = (xn-x0) / (double) Count;
	for (x = x0; x <= xn; x += Delta)
	{
		y = sin(x);
		cout << "x=" << x << " y=" << y << endl;
	}
}

// Упражнение 4. Написать функцию, которая найдет 
// таблицу значений функции y = A*sin(fi*x) 
// на произвольном диапазоне. Это означает, что список  
// параметров будет расширен добавлением A, fi. 

void Table_A(double x0, double xn, int Count, double A, double fi)
{
	double x, y;
	double Delta = (fi*xn-x0) / (double) Count;

	for (x = x0; x <= fi*xn; x += Delta)
	{
		y = A*sin(fi*x);
		cout << "x_A=" << x << " y_A=" << y << endl;
	}
}
