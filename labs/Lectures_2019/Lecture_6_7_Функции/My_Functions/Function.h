#include <math.h>
#include <iostream>
using namespace std;
// 
// Тема 1. функция, возвращающая значение.
// Имеет тип, имеет имя, // имеет список параметров.
// Функция находит среднее арифметическое 
// трех чисел.

float Avg(float a, float b, float c)
{
	float T = (a + b + c) / 3.;
	return T;	// Тип совпадает с типом функции.
}

// void функция
void Table(double x0, double xn, int count)
{
	double y;
	double delta = (xn - x0) / (double) count;
	cout <<  " x= " << " y=" << endl;
	for (double x = x0; x<xn; x+=delta)
	{
		y = sin(x);
		cout << x << " " << y << endl;
	}
}


// Найти сумму натурального ряда.
int Summ(int n)
{
	int S = 0;
	for (int k = 1; k <= n; k++)
		S += k;
	return S;
}
// Найти все делители некоторого натурального числа.
void Del (int n)
{
	for (int k = 2; k <= n / 2; k++)
		if (n%k == 0)
			std::cout << "K=" << k << std::endl;
}




// Параметры по адресу. 
// Найти периметр и площадь треугольника.
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

// Тема 2. Функция типа void.
// Перегруженная функция.

#include <stdio.h>
void print (void)        // Функции типа void без параметров.
{
int i;                   // Локальная переменная.
for (i = 1; i <= 50; i++)
   printf("%c",'*');
printf("\n");
}
void print (int n)                // Функции типа void без параметров.
{
int i;                          // Локальная переменная.
for (i=1; i <=n ; i++)
   printf("%c",'*');
printf("\n");
}
void print(char c)                // Функции типа void без параметров.
{
	int i;                          // Локальная переменная.
	for (i = 1; i <= 50; i++)
		printf("%c", c);
	printf("\n");
}

void print (int n, char c)                // Функции типа void без параметров.
{
int i;   // Локальная переменная.
if (n>80) 
	n=80;
for (int i=1;i<=n;i++)
   printf("%c",c);

printf("\n");
for (int i = 1; i <= n; i++)
printf("%c", c);
}


void print(int n, char c1, char c2)                // Функции типа void без параметров.
{
	int i;   // Локальная переменная.
	if (n>80)
		n = 80;
	for (i = 1; i <= n; i++)
		printf("%c%c ", c1,c2);
	printf("\n");
}

//Тема 3. Функция, возвращающая параметры.
//Пример - переменить значения переменных.

//Пишем функцию Swap1 с параметрами по значению.
void Swap1 (int x, int y)
{ 	
	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// Переменные переменились своими значениями.
}

//Пишем функцию Swap2 с параметрами по ссылке.
void Swap2 (int &x, int &y)
{ 	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// Переменные переменились своими значениями.
}

// Параметры по значению - защита данных.
int Sum1 (int n)
{
int	S = 0;			// Переменная для накопления значения суммы.
int	i; 			// Управляющая переменная для цикла суммирования.
	for (i = 1; i<= n; i++)
		S += i;
return	S;
}
// В этом примере локальная переменная i не необходима. Зная, что параметр,
// передаваемый по значению, не будет изменен функцией, его можно использовать
// как рабочую переменную для управления циклом.

int Sum2 (int n)
{
   int S;
	for ( S = 0; n > 0; n--)	// При n=0 цикл будет завершен.
		S += n;
return	S;
}  // Функция не изменит значения n.


// Перегруженные функции.
// Перегрузка по числу параметров.
// Одно имя, различется число параметров.
// Задача: Найти наибольшее из нескольких чисел.
// int    max (int, int);
// int    max (int, int, int);


int max (int x, int y)
{
    return x>y ? x : y;
}

int    max (int x, int y, int z)
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

int Triangle(float a,float b, float c, float & p, float &s)
       /*Описание функции - три варианта выхода */
{
float pp;  //Полупериметр.
if (a+b <=c || a+c<=b || b+c<=a)
    return 0;
    else
    {
    p=a+b+c;
    pp=p/2.;
    s=sqrt(pp*(pp-a)*(pp-b)*(pp-c));
    return 1;
    }
}
#include <conio.h>
/*
void My_window (void)
{
	 window(1,1,80,25);
     textbackground(WHITE);
     clrscr();
     textbackground(BLACK);
     window(15,5,65,20);
     clrscr();
     textbackground(CYAN);
     window(16,6,64,19);
	 clrscr();
getch();
}*/

