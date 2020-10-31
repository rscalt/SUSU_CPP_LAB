#include "Specification.h"
#include <iostream>
#include <locale>
// Это главная функция проекта.
// Она управляет сценарием работы приложения.
// Здесь объявляем данные, которые нужны приложению, и 
// передаем их в алгоритмы в соответствии со сценарием работы.
void main(void)
{
	setlocale(LC_ALL, ".1251");
// Объявить данные.	
	string Names[N]; 	// Массив имен.
	int Balls[N][4];	// Массив баллов и суммы.
	int Count = N;
	
	int Key;
	do
	{
		cout << "Выбери пункт меню\n";
		cout << "1. Запись на курс: ввести имена слушателей\n";
		cout << "2. Вывести список слушателей\n";
		cout << "3. Заполнить оценки\n";
		cout << "4. Сортировать\n";
		cout << "5. Показать\n";
		cout << "6. Удалить\n";
		cout << "7. Добавить\n";
		cout << "8. Сохранить в файл\n";
		cout << "10. Выйти \n";
		cin >> Key;
		switch (Key)
		{
		case 1: {Input_names("",Names,Count); break; }
		case 2: {Print_names(Names,Count); break; }
		case 3: {Input_balls(Names, Balls,Count); break; }
		case 4: {
			Sort_Balls(Names, Balls, Count);
			Print(Names, Balls, Count);
			break; }
		case 5: {Print(Names, Balls, Count); break; }
		case 6: {; break; }
		case 7: {; break; }
		case 8: {File_Write("Data.txt", Names, Balls, Count); break; }
		case 10: {return; }
		default: {; break; }
		}
	} while (Key != 10);
}




