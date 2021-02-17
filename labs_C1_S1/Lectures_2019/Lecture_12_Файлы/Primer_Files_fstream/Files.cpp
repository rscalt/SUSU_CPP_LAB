#pragma once
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include "Files.h"
using namespace std;
//---------------------------------------------------------------------------
 /*Чтение массива из файла.
  Длина массива может быть определена при вводе.
  Массив в текстовом файле "data.txt". Там же результат. */
#define  LEN_MAX 10

int main(void)
{
setlocale(LC_ALL, ".1251");
cout << "Привет, мир!" << endl;

ofstream F_out; 	// Имя объекта потока.
F_out.open("World.txt");	// Открытие файла.  
   F_out << "Привет, мир!" << endl;
F_out.close();		// Закрытие файла.


string World;
cin >> World;

ifstream F_in; 	// Имя объекта потока.
F_in.open("World.txt");	// Открытие файла.
F_in >>  World;
F_in.close();		// Закрытие файла.
// Вывод: чтение строки - до первого пробельного символа.
// Вывод: getline(откуда, куда): getline(cin, World); getline(F_in, World);

// Пример 1. Вывод массива в текстовый файл.
int   Arr[LEN_MAX] = {1,2,3,4,5};
int   len=5;

Print_arr(Arr,len);			// На консоль.

// Вывод в текстовый файл
string Name = "Data.txt";
Print_arr(Name, Arr,len);	// В файл Data.txt.


// Пример 2. Ввод массива из текстового файла.
Input_arr(Arr, len);		// Из консоли
Print_arr(Arr, len);

Input_arr("In_data.txt", Arr, len);		// Из файла In_data.txt. len определяется при вводе.
Print_arr(Arr, len);

// Пример 3. Чтение(запись) строк из текстового файла.
string Text[10];
int ls = 0;
Input_text("Text.txt", Text, ls);

}









//  прототипы:
//	char *fgets(char *s, int n,  FILE *stream);
//	int fputs  (const char *s,   FILE *stream);

