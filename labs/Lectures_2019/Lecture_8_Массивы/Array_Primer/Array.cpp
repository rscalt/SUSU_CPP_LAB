//---------------------------------------------------------------------------
#include "Array.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 16  					// Длина массива.
const int LEN = 100;

int main(int argc, char* argv[])
{
	srand(0);

	//int ArrOne[LEN];
	//int lenn=0;
	//Print_Arr(ArrOne, LEN);
	//Input_Arr(ArrOne, lenn);
	//Print_Arr(ArrOne, lenn);
	
	int Arr1[] = { 1,2,3,4};
	int Arr2[] = { 4,3,2,1};
	int Arr3[] = { 4,2,3,5};

	int Bool = YesUp(Arr1, 4);
	cout << Bool << endl;

	Bool = YesUp(Arr2, 4);
	cout << Bool << endl;

	Bool = YesDown(Arr2, 4);
	cout << Bool << endl;

	Bool = YesUp(Arr3, 4);
	cout << Bool << endl;



	//  Объявление и инициализация массива.
	float a[] = {1.5,2.2,3.8,7.6};
	int A[] = { 0,1,3,4,5,6 }; 
		int len_a = sizeof(A) / sizeof(int);
  
	Print_Arr(A,len_a);

	int B[3] = { 11,22,33 };
	Print_Arr(B, 3);
	
	int len;
	Input_Arr(A, len);

	Print_Arr(A, len);


	// Функция обработки массива. 
	float S = Avg(a, len_a);
    printf("Average is %6.2f\n",S);
	float x[] = { 0,1,1 };
	float y[] = { 1,1,0 };
	int n = Point(x, y, 3);

 // Ввод массива.
	Input_Arr(a,len_a);
    Print_Arr(a,len_a);
	// Случайное заполнение.
    // Функция srand(время) запускает генератор случайных чисел перед вызовом rand().
    srand((unsigned)time(NULL));   // Однократно - настройка (с системным временем)

	int R[20];
	Rand_Arr(R,20);
    Print_Arr(R,20);
// Поискать что-нибудь

  getch();
  return 0;
}
//---------------------------------------------------------------------------
