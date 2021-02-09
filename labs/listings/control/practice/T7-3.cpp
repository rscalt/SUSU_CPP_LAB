/* 
Описать функцию случайной генерации элементов массива Y, 
в котором могут быть как положительные, так и отрицательные значения. 
Описать функцию получения нового массива Z по следующему закону: 
Zi= Yi,если Yiпо модулю больше 1, и Zi= 1 в противном случае. 
Найти и вернуть число единичек в новом массиве. 
============= Использовать механизм указателей!!! =============
*/

#include <iostream>
#include <iomanip>  // print_array()
#include <stdlib.h> // srand()
#include <time.h>   // time()
#include <math.h> //abs()
#include <valarray> 

using namespace std;

float *create_array(float *arr, int &arr_length); //возвращает !динамический! массив заданной длины (как с положительными, так отрицательными значениями)
void print_array(float *arr, int arr_length); //вывод float-массива
float *create_transformed_array (const float *base_arr, float *new_arr, int arr_length); //возвращает новый динамический массив на основе исходного
int count_ones (float *arr, int arr_length); //возвращает количество элементов массива, равных единице

int main()
{
    //dirty hack для создания массива переменной длины
    int array_length = 1; 
    float *new_array_ptr = NULL;

    //создаем массив
    new_array_ptr = create_array(new_array_ptr, array_length);
    float *X_ARRAY_POINTER = new_array_ptr; //не теряем указатель
    new_array_ptr = NULL;

    //выводим на печать
    print_array(X_ARRAY_POINTER, array_length);

    //получаем новый массив на основе исходного
    new_array_ptr = create_transformed_array(X_ARRAY_POINTER, new_array_ptr, array_length);
    float *Y_ARRAY_POINTER = new_array_ptr; //не теряем указатель
    new_array_ptr = NULL;

    print_array(Y_ARRAY_POINTER, array_length);

    cout << "Count of Y-elements == 1 is " << count_ones(Y_ARRAY_POINTER, array_length);
}

//вывод float-массива
void print_array(float *arr, int arr_length) 
{
    cout << "Array at " << arr << ":\n";

    cout << "index\t"
         << "element\t"
         << "hex_address\t"
         << "dec_address\n";
    for (int i = 0; i < arr_length; i++)
    {
        cout << setw(2) 
             << i << "\t"; //index

        cout << setw(5) << setprecision(2) << setiosflags(ios::fixed)
             << arr[i] << "\t"; //element

        cout << setw(10) 
             << &arr[i] << "\t"; //hex_address

        printf("%d", &arr[i]); //dec_address

        cout << "\n";
    }
}

//возвращает динамический массив заданной длины (как с положительными, так отрицательными значениями)
float *create_array (float *arr, int &arr_length) 
{
    cout << "Enter array length: \n";
    cin >> arr_length; //переопределяем емкость массива
    arr = new float[arr_length](); //выделяем заданную память


    cout << "Enter values interval (0, cin): \n";
    unsigned int interval;
    cin >> interval; //задаем интервал случайных значений

    srand(time(NULL)); //запускаем seed для генератора псевдослучайных чисел, иначе каждый раз после компиляции будем получать одни и те же значения
    for (int i = 0; i < arr_length; i++)
        arr[i] = rand()%interval ; //заполняем +значениями
    for (int i = 0; i < arr_length; i++)
        arr[rand()%(arr_length-1)] *= -1;  //для случайных индексов меняем знак

    return arr; //возвращаем &arr[0]
}

float *create_transformed_array (const float *base_arr, float *new_arr, int arr_length) //возвращает новый динамический массив на основе исходного, той же длины
{
    new_arr = new float[arr_length](); //выделяем память
    
    for( int i = 0; i<arr_length; i++)
    {
        if ( (base_arr[i] > 1) or (base_arr[i] < -1) ) //abs() UB?
             new_arr[i] = base_arr[i];
        else new_arr[i] = 1;
    }
    return new_arr;
}

//возвращает количество элементов массива, равных единице
int count_ones (float *arr, int arr_length)
{
    int counter = 0;

    for (int i = 0; i < arr_length; i++)
    {
        if (arr[i] == 1)
            counter++;
        else continue;
    }

    return counter;
}