/*
Упражнение 2. Задание для самостоятельной разработки. 
Опишите функцию Rangeс тремя параметрами, 
которая меняет значения параметров так, 
чтобы они были упорядочены по возрастанию. 
Обратитесь к ней.
*/

/*
Здесь выкладываю свой велосипед [пет-проект] (С) с сортировкой
*/

#include <iostream>
#include <iomanip>
#include <cstdlib> //для rand()
using namespace std;

void sort(unsigned int array[], const unsigned int SIZE); //сортирует массив
void swap(int& arr1, int& arr2); //обмен  индексами элементов по ссылке
void show_array(unsigned int arr[], const unsigned int SIZE); //отображение массива

int main()

{
    system("cls");

    //=============Генерируем массив из SIZE положительных целых чисел в интервале от 0 до interval============//

	static const unsigned int SIZE = 20; //размер массива
	unsigned int array[SIZE]; //инициализация массива
	int interval = 0 + 100; //интервал для генерирумых случайных значений

	for (int i = 0; i < SIZE; i++)
	array[i] = rand() % interval; //случайные 

	cout << "original array:\n";
	show_array(array, SIZE); //отображает сгенерированный массив
	cout << "\n";

    sort(array, SIZE); //сортируем сгенерированный массив пузырьком

	cout << "\n sorted array: \n";  //отображает результат сортировки
	show_array(array, SIZE);
	system("pause");
	return 0;
}

void swap(int& arr1, int& arr2) //меняет значения местами (по ссылке)
{
	int temp = arr1;
	arr1 = arr2;
	arr2 = temp;
}

void show_array(unsigned int arr[], const unsigned int SIZE) //отображает массив
{ 
	for (int k = 0; k < SIZE - 1; k++)
		cout << setw(2) << arr[k] << ", ";
	cout << setw(2) << arr[SIZE - 1] << "\n";
}

void sort(unsigned int array[], const unsigned int SIZE) //сортирует массив пузырьком
{ 
    static int counter = 0;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{   //cout << "j = " << j << ":\n ";
			if (array[j] < array[j + 1])
			{
				counter++;
				cout << "count = " << setw(2) << counter << ": ";
				show_array(array, SIZE);
				//cout << "swapping indexes " << j << " and " << j+1 
				//<< ": of values " << array[j] << " and " << array[j+1] << "\n";
				swap(array[j], array[j + 1]);
				//cout << "new values are " << array[j] << " and " << array[j+1] << "\n";
			}

			//else cout << "skipped...\n";
		}
	}
}