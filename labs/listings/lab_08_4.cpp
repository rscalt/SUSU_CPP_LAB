/* Упражнение 2. Динамический массив. Функция, возвращающая массив
Есть задачи, когда исходный массив не должен быть изменен функцией, или функция должна породить новый массив. Например, получить копию массива.
В этом случае функция должна конструировать новый массив, и по какому-то алгоритму получить его значения, а потом вернуть. 
Есть два решения. 
1. Новый массив возвращается через список параметров.
2. Новый массив порождается динамически, и возвращается функцией.
Описания функций получения копии массива Copy_Oneи Copy_Two приведеныв заголовочном файле. 
Изучите пример, а затем получите копию массива двумя способами.
В main должны быть объявлены принимающие данные.
Обращение к функции Copy_One:Copy_One(a, b, n);
Обращение к функции Copy_Two:float *New_a = Copy_Two(a,n); */

#include <iostream>
#include "Array.h"
#include "Pointerr.h"
#include  <malloc.h>

int main()
{
    cout << "=====================Copy_One============================\n";
    float arr[] = {-1., 2., -3., 4., -5.}; //исходный массив
    int arr_length = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, arr_length);

    float arr_copy[5] = {}; //для наглядности
    int arr_copy_length = sizeof(arr_copy)/sizeof(arr_copy[0]);
    print_array(arr_copy, arr_copy_length); //нулевой

    Copy_One(arr, arr_copy, arr_copy_length);                                             

    print_array(arr_copy, arr_copy_length); //копия
    cout << "=====================Copy_Two============================\n";
    print_array(arr, arr_length);
    float *new_arr_copy = Copy_Two(arr, arr_length); //copy_two возвращает указатель на начало выделенного (new) блока памяти ...
    print_array(new_arr_copy, arr_length); // а длина вышеуказанного блока = arr_length
}