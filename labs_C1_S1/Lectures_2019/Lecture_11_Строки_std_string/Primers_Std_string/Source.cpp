
#include <iostream>
#include <string>
#include <locale>
//#include <Windows.h>
//#include <clocale>
#include "My_string.h"
#include <fstream>
using namespace std;
int main()
{
	
// 	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	string R;
	cin >> R;
							  // Коды символов.
	//Code();

	string Ss = F2("Раз два три четыре");
	cout << Ss << endl;
	string T("Раз два три четыре");
	F1(T);
	cout << T << endl;


	// Си-строка:
	char My_str[100];

	// Си++ строка: порождает объект типа string 
	string Name;

	//cout << "Enter your name: ";
	//getline(std::cin, Name);

	//// cin >> str;
	//cout << "Hello, " << Name << "!!! \n";
	
	
	// Объявление и инициализация строк: вызывается метод - конструктор.
	// Пустая строка:
	string One;
	// Строка получает константу:
	string Two("Моя строка\n");
	// Строка, получает копию другой строки:
	string Three(Two);
	

	// Свойства строк:
	// Размер и емкость строки.
	int capacity = Name.size();
	int Len = Name.length();


	// Методы строк:
	// empty() - метод, возвращающий true для пустой строки и false для непустой.
	bool B = Name.empty();

	// Присваивание, копирование: перегружена операция =.
	One = Two;     // Копирует  Two в One.
	
	// Для конкатенации строк перегружена операция сложения + и операция сложения с присваиванием += :
	
	string str1 = "Hello";
	string str2 = "World!";
	
	string str3 = str1 + ", " + str2;   // В строке str3 : "Hello, World".




	Name = "Василий";
	// Операции сравнения строк:
	string str_new("Вася");
	if (Name == str_new)
		cout << "Yes, " << Name << "!!! \n";	 // одно решение
	else
		cout << "No, " << Name << "!!! \n"; 	 // другое решение
	
	// Операции сравнения:
	//	== < > <= >= != выполняют сравнение в лексикографическом порядке.
	
	string foo = "Алла";
	string bar = "Анна";
	if (foo == bar) cout << "Строки равны\n";
	if (foo != bar) cout << " Строки не равны\n";
	if (foo< bar) cout << "Первая меньше\n"; 
	if (foo> bar) cout << "Первая больше\n";

	// Метод compare.
	int Res = foo.compare(bar);
	cout << Res << endl;
	Res = bar.compare(foo);
	cout << Res << endl;

	// Доступ к отдельным символам строки : операция индексации[] или метод at().
	string strS = "Hello, World!";
	
	cout << strS[7] << strS[0] << endl;     // На консоли: wh
	// Для метода at() индекс, это аргумент функции:
	
	cout << strS.at(7) << strS.at(0) << endl; // На консоли: wh
	
											  // Метод at() обеспечивает проверку границ.

	// Извлечение символов из строки.
	// Функция c_str() возвращает указатель на символьный массив, который содержит строку объекта  string :
	const char * strChar = Name.c_str();

	// Редактирование строк
/*
append – добавление строки к строке;
assign– изменение содержания строки;
insert– вставка в строку;
erase– удаление части строки;
replace– замена части строки.
*/

	string S = "Привет";
	cout << S << endl;
	
	S.append(" , Матроскин");
	
	cout << S << endl;
	
	S.assign("Hellow");
	
	cout << S << endl;

	S.insert(0, "Не ");

	cout << S << endl;

	S.erase(3, 3);

	cout << S << endl;

	S.replace(4,S.length(), "Бла-бла-бла");
	
	cout << S << endl;
// Поиск в строке.
	// find – первое вхождение в строку;
	// rfind – последнее вхождение в строку;
	// find - first_of первое вхождение символа  в строку;
	// find_last_of – последнее вхождение символа  в строку;

	string Where("Раз, два, три, четыре, пять, вышел некто погулять.");
	int a = Where.find('P', Len);
	
	a = Where.find("два", 0);
	
	a = Where.find("два", Len);

// Поиск вхождения строки в строку
// функция substr возвращает подстроку исходной строки, начиная с позиции 
// pos и включая n символов, или до конца строки.

	string Result = Where.substr(1, 3);

 // Чтение из файла
	ifstream F1("F1.txt");
	string Text;
	string Tmp;
	do
	{
	   getline(F1, Tmp);
	   Text.append(" ");
	   Text.append(Tmp);
	} while (!F1.eof());
	cout << Text;
	// Вывод в файл

	ofstream out;				// out - поток для записи.
	out.open("Hello.txt");  // Открыть файл для записи.
	if (out.is_open())
	{
		out << "Hello, World!" << endl;	// Или переменные.
	}
	out.close();

		// Как разделить на слова.
	Text = "Раз два три четыре пять rabbit go walk";
	string Words[100];
		int len = 0;
		Dictionary(Words, len, Text);

		remove_E(Text);

}
