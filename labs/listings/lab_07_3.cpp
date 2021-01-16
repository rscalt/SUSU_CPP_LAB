/* Упражнение 3. Исследование принципов работы с параллельными массивами. Функция Point получает два массива координат точек:x[]и y[] 
и находит номер точки, наиболее удаленной от начала координат.
Опишите исходные данные для функции, достаточно трех точек для проверки, обратитесь к функции, и затем выведите координаты искомой точки, номер которой вернула функция. */

#include <iostream>
#include <iomanip> //для форматирования
#include "Array.h" //все функции по условию ПЗ определены здесь

int main()
{
    int point_count = 5; //пример для point_count точек

    int x[point_count] = {}; // инициализируем массив абсцисс
    Rand_Arr(x, point_count);

    int y[point_count] = {}; // инициализируем массив ординат
    Rand_Arr(y, point_count);

    print_array(x, y, point_count); //отображение двух параллельных массивов

    int index_farpoint = Point(x, y, point_count);
    cout << "\nThe coordinates are: ";
    cout << "( ";
    cout << x[index_farpoint]; //для краткости
    cout << " ; ";
    cout << y[index_farpoint];
    cout << " )";
}