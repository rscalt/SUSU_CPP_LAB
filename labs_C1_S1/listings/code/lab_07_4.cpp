/* *
Упражнение 4. Задание для самостоятельной разработки. 
Дано некоторое произвольное количество точек на плоскости. 
Опишите, отладьте и протестируйте функцию, 
которая удалит из массива самую дальнюю точку. 
Пример того, как это делается в одномерном массиве, 
приведен в функции Del.
*/

#include <iostream>
#include <iomanip> //для форматирования
#include "Array.h" //все функции по условию ПЗ определены здесь

int main()
{
    int point_count = 4; //пример для point_count точек

    int x[point_count] = {}; // инициализируем массив абсцисс, явно пустой
    int y[point_count] = {}; // инициализируем массив ординат, явно пустой
    Rand_Arr(x, y, point_count);
    print_array(x, y, point_count); //отображение двух параллельных массивов

    int index_farpoint = Point(x, y, point_count); //индекс точки для удаления
    cout << "\nThe point at i = " << index_farpoint << " is to be deleted; ( x , y ) are ";
    cout << "( ";
    cout << x[index_farpoint]; //для краткости
    cout << " ; ";
    cout << y[index_farpoint];
    cout << " ) ...";

    cout << " Removing from array...";
    remove_farpoint(x, y, point_count, index_farpoint); 
    cout << "\n";

    cout << "\n Array have been changed: ";
    print_array(x, y, point_count); //отображение двух параллельных массивов
}