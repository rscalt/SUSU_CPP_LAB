// Это главная функция проекта.
// Она управляет сценарием работы приложения.
// Здесь объявляем данные, которые нужны приложению, и 
// передаем их в алгоритмы в соответствии со сценарием работы.

#include "Module.h"
void main(void)
{
	setlocale(LC_ALL, ".1251");
	int Key = 0;
	int Arr[10] = { 1,2,3,5,6,7};
	int len = 6;
	do
	{
		cout << "Выбери пункт меню\n";
		cout << "1. Вывести\n";
		cout << "2. Ввести\n";
		cout << "3. Случайно\n";
		cout << "4. Упорядочен\n";
		cout << "5. Найти\n";
		cout << "6. Удалить\n";
		cout << "7. Добавить\n";

		cout << "10. Выйти \n";
		cin >> Key;
		switch (Key)
		{
		case 1: {Print_Arr(Arr, len); break; }
		case 2: {Input_Arr(Arr, len); break; }
		case 3: {Rand_Arr(Arr, len); break; }
		case 4: {
			bool B = YesUp(Arr, len); 
			cout << B << endl; 
			break; 
		}
		case 5: {; break; }
		case 6: {; break; }
		case 7: {
			int add_el;
			cout << "Что добавить " << endl;
			cin >> add_el;
			Addd(Arr,len,add_el); break; 
		        }
		case 10: {return; }
		default: {; break; }
		}
	} while (Key != 8);
}




