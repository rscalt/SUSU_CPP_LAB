#pragma once
// Заголовок модуля.
// Данные и функции их обработки.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 10;	// Число слушателей.
// Запись слушателей на курсы. Имена выгружаются в файл с именем File
void Input_names(string File, string Names[], int &n);
// Вывод списка имен.
void Print_names(string arr[], int len);  // len – длина массива. 
// Запись баллов по завершении курсов.
void Input_balls(string Names[], int Balls[][4], int &n);
// Сохраняем в файле полную информацию. 
// В конце работы данные выгружаются в файл F_Names.
void File_Write(string F_Name, string Names[], int Balls[][4], int n);
// В начале работы данные подгружаются из файла F_Names.
void File_Read(string F_Name, string Names[], int Balls[][4], int n);
// 
void Swap(int &a, int &b);
void Swap(string &a, string &b);
// Сортировка в порядку убывания суммы баллов.
void Sort_Balls(string Names[], int Balls[][4], int n);
// Вывод на экран.
void Print(string Names[], int Balls[][4], int n);







