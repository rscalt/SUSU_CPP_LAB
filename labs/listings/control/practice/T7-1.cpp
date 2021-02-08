/* 
 Проинициализировать два массива произвольной длины, в каждом из которых нет повторяющихся значений. 
 Описать логическую функцию, которая проверит, нет ли в массиве повторяющихся элементов. 
 Описать функцию, которая найдет количество элементов, которые одинаковы в двух массивах.
 */

#include <iostream>
//#include "Array.h" //из курса ранее представленных практических работ
using namespace std;

bool array_has_duplicates(float *array, const unsigned int SIZE, int &duplicate_counter);
//проверка float-массива на наличие повторяющихся элементов
int duplicates_between_arrays (float *first_array, int SIZE_ONE, float *second_array, int SIZE_TWO);// проверка двух float-массивов на повторяющиеся элементы (на пересечение множеств значений элементов)

int main()
{
    const unsigned int SIZE_ONE = 5;
    float array_one[] = {21, 34, 0, 8, 9};
    const unsigned int SIZE_TWO = 3;
    float array_two[] = {1, 0, 21};

    int single_array_duplicate_counter = 0; //число повторяющихся элментов одного массива
    int multi_array_duplicate_counter = 0; //число повторяющихся элментов между массивами

    //==============Сначала  проверим каждый массив на дубликаты==============
    cout << "Checking first array for duplicates... ";

    bool array_one_has_duplicates = array_has_duplicates(array_one, SIZE_ONE, single_array_duplicate_counter);
    printf(array_one_has_duplicates ? "DUPLICATES DETECTED!\n" : "OK\n"); // 1 or 0 ? true : false
    
    cout << "  Single array duplicate counter: " << single_array_duplicate_counter;
    cout << endl;
    cout << endl;


    cout << "Checking second array for duplicates... ";

    bool array_two_has_duplicates = array_has_duplicates(array_two, SIZE_TWO, single_array_duplicate_counter);
    printf(array_two_has_duplicates ? "DUPLICATES DETECTED!\n" : "OK\n"); // 1 or 0 ? true : false
    
    cout << "  Single array duplicate counter: " << single_array_duplicate_counter;
    cout << endl;
    cout << endl;

    //==============Теперь, если в каждом массиве нет дубликатов, проверим, дублируются ли элементы между двумя массивами ==============
    multi_array_duplicate_counter = duplicates_between_arrays(array_one, SIZE_ONE, array_two, SIZE_TWO);
    cout << "# of Duplicates between arrays: " << multi_array_duplicate_counter << endl;

}

bool array_has_duplicates (float *array, const unsigned int SIZE, int &duplicate_counter) //проверка float-массива на наличие повторяющихся элементов
{
    duplicate_counter = 0;
    int i = 0, j = 0;
    bool has_duplicates = false;

    for (i = 0; i < SIZE; i++)
    {
        for (j = i+1; j < SIZE; j++)
        {
            if (array[i] == array[j])
            {
                //cout << "\nRepeating element indexes: " << " \t " << i << " \t "<< j;
                //cout << "\nRepeating element values: " << " \t " << array[i] << " \t "<< array[j];
                //cout << endl;
                has_duplicates = true;
                duplicate_counter++;
            }
        }  
    }
    return has_duplicates;
}

int duplicates_between_arrays (float *first_array, int SIZE_ONE, float *second_array, int SIZE_TWO) // проверка двух float-массивов на повторяющиеся элементы (на пересечение множеств значений элементов)
{
    int duplicates_between_arrays = 0;
    for (int i = 0; i < SIZE_ONE; i++)
    {
        for (int j = 0; j < SIZE_TWO; j++)
        {
            if (first_array[i] == second_array[j])
            duplicates_between_arrays++;
        }
    }
    return duplicates_between_arrays;
}