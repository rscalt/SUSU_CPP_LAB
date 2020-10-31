//#pragma once
//#include <fstream>
//#include <iostream>
//
//
//void main(void)
//{
//	string Text;	// Конструктор по ум.
//	string Text_1("Это строка");
//	string Text_2(Text_1);
//	// Размер строк.
//	int k = Text_1.capacity();
//	k = Text_1.length();
//	k = Text_1.size();
//	Text_1.reserve(80);
//	// Обращение к символам строки: [] или at
//	char C = Text_1[0];
//	C = Text_1.at(0);
//	// Контроль выхода за пределы строки.

//	// Изменение строк.
//	// Присваивание строк.
//	Text_1 = A;
//	// Приваивание.
//	Text_1.assign("Раз, два, три, четыре, пять");
//	Text_2.assign(Text_1, 0, 3);
//	// Вставка и удаление символов.
//	// В конец строки: +=, append(что).
//	// Внутри строки: insert(номер, )
//	Text_1.insert(4, " rabbit go walk ");
//	// erase()
//	// replase()
//	Text_1.erase(0, 4);
//	Text_1.replace(1, 2, "нечто новое");
//	// Поиск в строке.
//	// substr();	// выделит подстроку.
//	Text_1.substr();
//	Text_1.substr(10);
//	Text_1.substr(Text_1.find('т'));
//	// find(value) - первое вхождение.
//	// rfind(value) - последнее вхождение.
//	// find_first_of(value) - первое вхождение символа.
//	// find_last_of(value) - последнее вхождение символа.
//
//	// Как получить строку.
//
//	/*ifstream F1("F1.txt");
//
//	string Text;
//	string Tmp;
//	do
//	{
//	getline(F1, Tmp);
//	Text.append(" ");
//	Text.append(Tmp);
//	} while (!F1.eof());*/
//	cout << Text;
//
//	// Как очистить строку: найти и убить.
//	//char Value = '.';
//	//int k=0;
//	//while (k != -1)
//	//{
//	//	k = Text.find(Value);
//	//	if (k!=-1)
//	//		Text.erase(k, 1);
//	//}
//	// Привести к одному регистру.
//
//	// Как выделить слова.
//
//	//Dict A;
//	//k = 0;
//	//string Word;
//	//do
//	//{
//	//	k = Text.find_first_of(" ");
//	//	if (k == -1) break;
//	//	// От начала строки до пробела записать в словарь.
//	//	Word = Text.substr(0, k);
//	//	// A.Add(Word);
//	//	cout << Word;
//	//	// Изменить Text;
//	//	Text.erase(0, k+1);
//	//} while (k != -1);
//
//
//
//
//
//
//
//}
