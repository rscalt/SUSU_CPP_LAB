/* Упражнение 1. Параметры по адресу.
Опишите и инициализируйте массив вещественных чисел.
Найдите его емкость, она же длина.
Передайте в функцию transform_One, и выведите решениефункцией Out_Arr.
Передайте в функцию transform_Two, и выведите решение. */

#include <iostream>
#include "Array.h"
#include "Pointerr.h"
#include  <malloc.h>

int main()
{
    float *array = new float[5] {-1., 2., -3., 4., -5.}; //"чистый" пример
    int length = _msize(array)/sizeof(array[0]); // динамический же

    cout << array <<  " is an array of ";
    cout << length << " memory blocks allocated in the heap\n"; //"емкость" динамического массива для целей данной задачи
    print_array(array, length); //сразу посмотрим, что получилось
    Out_Arr_2(array, length); //... в т.ч. через готовую ф-ю
    cout << "=======================================\n";
    
    transform_One(array, length); // Arr[i] = Arr[i] * 2
    print_array(array, length); //повторный вывод
    Out_Arr_2(array, length); //... в т.ч. через готовую ф-ю
    cout << "=======================================\n";
    
    transform_Two(array, length);
    print_array(array, length); //повторный вывод
    Out_Arr_2(array, length); //... в т.ч. через готовую ф-ю
    cout << "=======================================\n";
}