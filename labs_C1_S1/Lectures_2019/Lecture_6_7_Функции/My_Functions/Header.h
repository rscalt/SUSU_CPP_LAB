#pragma once
#include <math.h>
#include <iostream>

//Тема 1. Функция, возвращающая параметры по адресу.
//Пример - переменить значения переменных.

//Пишем функцию Swap1 с параметрами по значению.
void Swap1(int x, int y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// Переменные переменились своими значениями.
}
//Пишем функцию Swap2 с параметрами по ссылке.
void Swap2(int &x, int &y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// Переменные переменились своими значениями.
}

// Тема 1. Параметры по адресу. 
// Пример функции, возвращающей периметр и площадь треугольника.
bool Square(float a, float b, float c, float  &p, float &s)
{
	p = (a + b + c);
	float pp = p*0.5;
	if (a + b > c && b + c > a && b + c > a)
	{
		s = sqrt(pp*(pp - a)*(pp - c)*(pp - b));
		return true;
	}
	else
	{
		s = p = 0;
		return false;
	}
}

// Тема 2. Перегруженная функция.
#include <stdio.h>
void print(void)       
{
	int i;                   // Локальная переменная.
	for (i = 1; i <= 50; i++)
		printf("%c", '*');
	printf("\n");
}


   // Перегруженные функции.
   // Перегрузка по числу параметров.
   // Одно имя, различется число параметров.
   // Задача: Найти наибольшее из нескольких чисел.
   // int    max (int, int);
   // int    max (int, int, int);


int max(int x, int y)
{
	return x>y ? x : y;
}

int    max(int x, int y, int z)
{
	return x>y ? (x>z ? x : z) : (y>z ? y : z);
}
int  max(int x[], int n)
{
	int max = 0;
	for (int i = 0; i < n; n++)
		if (x[max] > x[i])
			max = i;
	return max;
}


/* Функция находит площадь и периметр треугольника, заданного длинами сторон.
Возвращаемые значения - площадь и периметр.
Одно значение через return,
Два через параметры. Тип возвращаемого значения int. Смысл - проверка условия существования.
Значение = 1, если треугольник существует, равно 0, если нет.
*/

#include <math.h>

int Triangle(float a, float b, float c, float & p, float &s)
/*Описание функции - три варианта выхода */
{
	float pp;  //Полупериметр.
	if (a + b <= c || a + c <= b || b + c <= a)
		return 0;
	else
	{
		p = a + b + c;
		pp = p / 2.;
		s = sqrt(pp*(pp - a)*(pp - b)*(pp - c));
		return 1;
	}
}
