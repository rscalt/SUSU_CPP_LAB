#include <iostream>
#include "Array.h"

//int array_counter(int *arr, int SIZE);

int main()
{
    const unsigned int SIZE = 10;
    int array[SIZE];

    srand(time(NULL));
    const unsigned int interval = 20;
    for (int i = 0; i < SIZE; i++)
    array[i] = ( rand() - rand() )%interval;

    print_array(array, SIZE);

        int i = 0, j = 0;
        bool had_repeating = false;
        for (i = 0; i < SIZE; i++)
        {
            for (j = i+1; j < SIZE; j++)
            {
                if (array[i] == array[j])
                    {
                        cout << "Repeating element indexes: " << i << " , "<< j << endl;
                        had_repeating = true;
                        array[j] = ( rand() - rand() )%interval;
                        cout << "Restarting...\n";
                        i = 0;
                        j = j;
                    }
            }  
        }

    if (had_repeating == true) print_array(array, SIZE);
   
    int numb_min = Min(array, SIZE);
    cout << numb_min;
}

//среднее значение элементов float-массива
void average(float Point, float &avg) //по значению, по ссылке
{
    float value;
    float sum;

    for (int i = 0; i < Point; i++)
        {
        std::cin >> value;
        sum += value;
        }
    avg = sum/Point;
}

/* 
    if (abs(x)<= 1 && abs(y) <= 1) //ограничение предметной области
    { //график симметричен относительно оси абсцисс: |x|
        if  (y == 0)
             if (abs(x) <= 1) //по точкам пересечения фигуры с Ox
        if ( y > 0 )
             if (abs(x)*y <=1) //площадь верхней части фигуры = 1
 	   if ( y < 0 )
             if (abs(x)*y <=1/2) //площадь верхней части фигуры = 0,5
    }
 */