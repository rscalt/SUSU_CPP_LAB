
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	char My_str[100];
	string str;
	cout << "Enter your name: ";
	getline(std::cin, str);
	// cin >> str;
	cout << "Hello, " << str << "!!! \n";
int Len = str.size();
	Len = str.length();
	//empty() - метод, возвращающий true для пустой строки и false для непустой :
	//bool B = str.empty();
	//Оператор сравнения строк == :
	string str_new("Petr");
	if (str == str_new) 
		// одно решение
		cout << "Yes, " << str << "!!! \n";
	else 
		// другое решение
		cout << "No, " << str << "!!! \n";
	std::string str1 = "Hello";
	std::string str2 = "World";
	std::string str3 = str1 + str2; // В строке str3 : "HelloWorld".
	//Функция c_str() возвращает указатель на символьный массив, который содержит строку объекта  string :
	
	const char * strChar = str.c_str();
	
	//Обращение к отдельным символам строки : операция индексации[] или метод at().
	std::string strS = "Hello World";
	cout << strS[7] << strS[0] << std::endl; // На консоли: oH
	//Для метода at() индекс, это аргумент функции :
	cout << strS.at(7) << strS.at(0) << std::endl; // На консоли: oH
	//Метод at() обеспечивает проверку границ.
	int a = str.find('P',Len);
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
}
