#include <stdio.h>
#include <iostream>
#include <conio.h>

#include "Function.h"
#include "One.h"
using namespace std;
int main(void)
{
// Обращение к функциям.

	print();
	print(44);
	print(14);
	print(67);
	print(12, '=');
	print(72, '%');
	cout << Avg (3.0, 6., 12);
	float Res = Avg(2.,4.,6.) * 3 *pow(2.,2);

	Table(0., 3.14, 12);

	int x = 12;
	int y = 7;
	Swap1(x, y);
	printf("x=%d y=%d\n", x, y);

	Swap2(x, y);
	printf("x=%d y=%d\n", x, y);

	float Perimetr, Ploshad;
	bool B = Square(3., 4., 5., Perimetr, Ploshad);





	print( );
	print(12);
	print('=');
	print(24, '!');
	print(111,'a','b');
	
	float S, P;
	float a1 =4, a2=3, a3=6;

	if (Square(a1, a2, a3, P, S))
		std::cout << P << S << std::endl;
	else
		std::cout << "Is not triangle\n";
	
	float xx, yy;

	Square(3., 4., 5., xx, yy);

	// 1. Факт. параметры - константы.
	printf ("Avg is %f\n", Avg(3,6,12));
	float x1=12., x2=15., x3=19.;
	// 2. Факт. параметры - переменые.
	float bb = Avg(x1,x2,x3);
	printf ("Avg is %f\n",bb);
	// 3. Факт. параметры - выражения.
	float cc = 2+8.5*Avg(x1*x2 ,2. ,x3-5 );
	printf ("Avg is %f\n",cc);

	
	//if (Square(3, 4, 19, P, S))
	//	std::cout << P << S;
	//else
	//	std::cout << "Is not triangle\n";

	int Global;
	Global = 100;

	{
		int Loc;
		Loc = 12; 
	}
		
	
	print();
	print();
	print('-');
	print('+');
	print(3,'~');
	print(33, ':',')');
	print(330, '^');



	print(369,'==');
	for (int i=1,k=1; i<50; i++, k++)
       print(i,k);
getch();
}