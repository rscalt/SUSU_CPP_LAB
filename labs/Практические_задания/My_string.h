#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>
#include <clocale>
using namespace std;
void Code(void)
{
	int  i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{ // if (16*i+j >7 && 16*i+j<14) continue;
			cout << (char) (16 * i + j)<< " " ;     //символьное представление числового кода
		}
		cout << endl;
	}
}
// Пример 1. Методы редактирования строки.
// Функция удалит из строки первое и последнее слова. 
// Параметр функции - объект.
void F1(string T)
{
	int k = T.find_first_of(' ');
	T.erase(0, k);
	k = T.rfind(' ');
	T.erase(k);
}
// Параметр функции - объект. Функция получает новую строку.
string F2(const string T)
{
	string Tmp(T);
	int k = Tmp.find_first_of(' ');
	Tmp.erase(0, k);
	k = Tmp.rfind(' ');
	Tmp.erase(k);
	return Tmp;
}
// Пример 2. Методы извлечения символов строки.
// Каждый 5-й символ заменить разделителем '!'. 
// Параметр функции - объект.
void remove_E(string &T)
{
	for (int i = 5; i < T.size(); i+=5)
		T.at(i) = '!';
}
// Пример 3. Извлечение строк. 
// Задача: из строки текста получить массив - словарь слов указанного текста.
void Dictionary(string Words[], int &len, string Text)
{
	len = 0;
	int k = 0;
	string Word;
	Text.append(" ");
	do
	{
		k = Text.find_first_of(" ");
		if (k == -1) break;
		// От начала строки до пробела записать в словарь.
		Words[len++] = Text.substr(0, k);
		Text.erase(0, k + 1);		// Изменить Text;
	} while (k != -1);
}

// Пример 4. Сравнение строк.
// Упорядочить по возрастанию слова. 
// 1. Из строки получить массив.
// 2. Упорядочить.
// 3. Собрать в строку.
