/* 2. Описать функции ввода и вывода элементов массива. 
Описать функцию, которая определит, является ли массив упорядоченным по возрастанию. 
Описать логическую функцию, которая для массива и некоторого заданного N определит, 
сохранится ли упорядоченность, если N«приписать» в конец массива. 
Если это возможно, функция действительно добавит число в конец массива, и увеличит его длину */

#include <iostream>
#include <iomanip>
using namespace std;

void print_array(float *arr, int arr_length);                       //вывод float-массива
void enter_array(float *arr, int arr_length);                       //ввод длины и элементов массива
bool asc_sorted(float *arr, int arr_length);                        //проверка на сортировку по возрастанию
bool append_if_sorted(float *arr, int &arr_length, bool is_sorted); //добавляет новый элемент в конец массива и увеличивает его длину, если это сохранит упорядоченность по возрастанию

int main()
{
    int array_length = 5;
    bool is_sorted_asc = false;
    float array[array_length] = {};

    enter_array(array, array_length); //ввод
    print_array(array, array_length); //вывод

    is_sorted_asc = asc_sorted(array, array_length); //проверка на сортировку
    printf(is_sorted_asc ? "The array IS sorted\n" : "The array IS NOT sorted\n"); //вывод результата проверки

    bool append_result = append_if_sorted(array, array_length, is_sorted_asc);
    if (append_result == true)
        print_array(array, array_length);
}

void print_array(float *arr, int arr_length) //вывод float-массива
{
    cout << "Array at " << arr << ":\n";

    cout << "index\t"
         << "element\t"
         << "hex_address\t"
         << "dec_address\n";
    for (int i = 0; i < arr_length; i++)
    {
        cout << setw(2) << i << "\t";
        cout << setw(5) << setprecision(2) << arr[i] << "\t";
        cout << setw(10) << &arr[i] << "\t";
        printf("%d", &arr[i]);
        cout << "\n";
    }
}

void enter_array(float *arr, int arr_length) //ввод длины и элементов массива
{
    cout << "Enter array values: \n";
    for (int i = 0; i < arr_length; i++)
        cin >> arr[i];
}

bool asc_sorted(float *arr, int arr_length) //проверяет, отсортирован ли массив по возрастанию (без лишних итерацийЮ возвращает true для отсортированного)
{
    int num_sorted = 0;
    for (int i = 0; i < arr_length - 1; i++)
        if ((arr[i + 1] >= arr[i]) && (i == num_sorted)) //исключаем лишние итерации вторым условием
        {
            num_sorted++;
            if (num_sorted == arr_length - 1)
                return true;
        }
        else
            break;
    return false;
}

bool append_if_sorted(float *arr, int &arr_length, bool is_sorted) //добавляет новый элемент в конец массива и увеличивает его длину, если это сохранит упорядоченность по возрастанию
{
    if (is_sorted == true)
    {
        float add = 0;
        cout << "Enter a value to append: \n"; //введите присоединяемое значение
        cin >> add;

        if (arr[arr_length - 1] <= add) //если упорядочен и последний элемент <= добавляемому
        {
            arr[arr_length++] = add; //увеличиваем длину и присваиваем
            return true;
        }
        else
        {
            cout << "The value can`t be appended! [breaks sorting]\n"; //нельзя присоединить
            return false;                                              //иначе 0
        }
    }
    else
    {
        cout << "Array is not sorted!\n";
        return false;
    }
}