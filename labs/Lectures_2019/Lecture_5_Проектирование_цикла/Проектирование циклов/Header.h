#pragma once
#include <iostream>
#include <iomanip>
#include <math.h> 
// В библиотеке math.h определена константа M_PI – значение числа π. 
#define _USE_MATH_DEFINES
#define M_PI 3.14
using namespace std;
// Вычисление таблицы значений.
void Table()
{
	//double const Pi = 3.14;
	double x, y;	     // Аргумент и значение функции. 
	// Вывод шапки таблицы в текстовом режиме экрана.
	cout << "\n Таблица значений функции\n";
	cout << "------------------------------------\n";
	cout << "\t  X = " << "\t  Y=" << endl;
	cout << "------------------------------------\n";
	cout << setprecision(4);
	// x – параметр цикла, в заголовке цикла for задано полное управление.
	for (x = -(M_PI) /2.; x <= M_PI / 2.+0.01; x += 0.2)
	{
		// Логическая запись формулы вычисления.
		if (fabs(x) < M_PI /4)
			y = sin(x);
		else
			y = cos(x);
		// Вывод строки таблицы.
		cout <<"\t" << x << "\t" << y << endl;
	}
}
