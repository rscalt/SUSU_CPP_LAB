/* Упражнение 3. Задание для самостоятельной разработки. Опишите функцию Two_Arr, которая получает вещественный массив, и формирует два новых массива. 
В первом из них записаны только положительные элементы исходного массива, 
а во втором –только отрицательные.  
Имеет смысл возвращать массивы через список параметров. Как, собственно, и их длины. */

#include <iostream>
#include "Array.h"
#include "Pointerr.h"
#include <cstdlib> //для rand()

int main()
{
    
    //=============Генерируем случайный вещественный массив

	static const unsigned int SIZE = 10; //размер массива
	
	float mix_array[SIZE]; //инициализация массива
	int interval = 20; //интервал для генерирумых случайных значений
	for (int i = 0; i < SIZE; i++)
	mix_array[i] = ( rand() - rand() ) %interval; //случайные 

	float *two_array_pointer = NULL; //глобальный указатель для передачи в функцию; локальные указатели сбрасываются после завершения родительской функции 
	int positive_counter = 0;  //явная инициализация
	int negative_counter = 0;

	two_array_pointer =  twoArr (mix_array, SIZE, two_array_pointer, 
	positive_counter, negative_counter); //можно вернуть массив двух массивов

	float *positive_array_pointer = two_array_pointer; //первые элементы > 0...
	float *negative_array_ppointer = two_array_pointer+positive_counter; //... а после положительных идут отрицательные

	print_array(mix_array, SIZE); //исходный массив
	print_array(positive_array_pointer, positive_counter); //положительный массив
	print_array(negative_array_ppointer, negative_counter); //отрицательный массив
}
