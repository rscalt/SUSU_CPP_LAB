#pragma once
#include <conio.h>
#include <stdlib.h>
#include <time.h>  // Для srand()
#include <iostream>
#include <locale>
using namespace std;
using namespace std;
const int LEN = 100;
// Заполнение массива случайными числами. 
void Rand_Arr(int a[], int len_a);
//Вывод массива
void Print_Arr(int a[], int len_a);	 
void Print_Arr(float a[], int len_a);
void Input_Arr(int a[], int & len_a);
void Input_Arr(float a[], int &len_a);
// Среднее арифметическое.
float Avg(float a[], int len);
// Примеры функций обработки массивов.
// 1. Проверить, упорядочен ли.
bool YesUp(int a[], int n);
int YesDown(int a[], int n);
// 2. Минимакс.
int Min(int a[], int n);
// Изменение длины массива: удаление, вставка.
// ! контроль выхода.
// 3. Удаление. Удаление наименьшего.
void Add(int a[], int  & n, int Q);
// Что удалить? 
int Del(int a[], int  &n);
// Добавить в массив, 
bool Addd(int a[], int & len, int new_el);


