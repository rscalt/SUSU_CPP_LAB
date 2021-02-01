/* Упражнение 4. Задание для самостоятельной разработки. 
Опишите функцию New_Arr, 
которая формирует целочисленный массив указанной длины по следующему правилу: 
первое значение равно 1, второе = -1, третье = 2, четвертое = -2, и так далее. */
#include "Array.h"
#include "Pointerr.h"

int main()
{
    const unsigned int size = 11; //указываем длину
    int *array = new int(); //глобальный указатель
    array = new_arr(size);
    print_array(array, size);
    delete[] array;
    return 0;
}
