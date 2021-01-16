/* Заголовочный файлArray.hскопируйте в папкупроекта и присоедините к проекту, откройте и ознакомьтесь с содержимым. Все описания функций выполняютсяздесь, а управления вызовами –в Sourсeфайле проекта.
Упражнение 1. Описание и инициализация массива, передача в функцию
1.1.Опишите и инициализируйте массиввещественных чисел:
Найдите его длину
Выведите массив функцией Print_Arr.
Передайте массив вфункциюAvg:
Выведите решение.
1.2.Опишите массив вещественных чисел, емкость которого = 10.
Опишите переменную, обозначающую фактическую длину массива:
Введите Len_aэлементов функцией Input_Arr, выведите на экран функцией 
Найдите и выведите значение наибольшего элемента массива.
Опишите функцию Transform, получающую вещественный массив, которая заменит все элементы, которые больше, чем среднее арифметическое, его значением.Обратитесь к ней, например, с тем же массивомMy_Arr.Функция изменит элементы массива, это будет известно в main. Выведите измененный массив функцией Print_Arr.
*/

#include <iostream>
#include <iomanip>
#include "Array.h"

using namespace std;

void print_array (float array[] , int length); //элегантный вывод массива
void transform_array (float array[], int length); //замена элементов

int main()
{
    cout // форматируем значения...
    << setiosflags(ios::fixed) // неслетающий флаг...
    << setiosflags(ios::right) // выравнивание для setw()
    << setiosflags(ios::showpoint) // всегда с точкой...
    << setprecision(2) << setfill('0');//знаков после запятой + fill

    float array[] = {1.5, 2.5, 3.0, 12.0}; //инициализированный массив
    int array_length = sizeof(array)/sizeof(float); //длина массива float-переменных
    print_array(array, array_length); //выводим на печать

    cout << "Array average is "; //считаем среднее
    cout << Avg(array, array_length) << "\n";

    float my_arr[10] = {}; //новый массив вещественных чисел емкостью 10 элементов
    int my_arr_length = sizeof(my_arr)/sizeof(float); //считаем длину
    int my_arr_input_length = 5; //число фактически вводимых элементов

    Input_Arr(my_arr, my_arr_input_length); //ввод элементов массива
    print_array(my_arr, my_arr_length); //выводим на печать весь массив

    cout << "\n";
    cout << "Index of arr[max] is ";
    cout << Max(my_arr, my_arr_length);
    cout << "\n\n";

    transform_array(my_arr, my_arr_length); //заменяем средним
    cout << "Transformed array is: \n";
    print_array(my_arr, my_arr_length); //снова выводим на печать
}